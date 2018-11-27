//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/11/7
// 最終更新日:
//

#include "Player.h"

#include "Input/Input.h"
#include "Math/Vector2.h"

#include "../BulletObject.h"

using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
namespace Character
{
    GFF::System::Gun Player::gun;

    void Player::Update(float _elapsedTime)
    {
        bool shot = (bool)Inputs::Instance().GetValue(L"Shot");

        Move(_elapsedTime);
        
        // 発射キーが押されたら銃弾を発射する
        if (shot)
        {
            Shoot(_elapsedTime);
        }

        if (m_gun.isContinuous && !shot)
        {
            m_shotTime = 0.0f;
        }

        int bulletCount = 0;

        // 銃弾の更新処理
        for (BulletObject* bullet : m_bullets)
        {
            bullet->Update(_elapsedTime);

            // 銃弾が破棄されるべき状態なら破棄する
            if (bullet->isDestroy)
            {
                delete bullet;

                m_bullets.erase(m_bullets.begin() + bulletCount);
            }

            bulletCount++;
        }
    }

    void Player::Shoot(float _elapsedTime)
    {
        // 連射可能か
        if (m_gun.isContinuous)
        {
            // 連射間隔を計算
            const float fireTime = 1.0f / m_gun.fireSpeed / 60.0f;

            m_shotTime += _elapsedTime;

            // 連射間隔を過ぎていたら銃弾を生成
            if (m_shotTime >= fireTime)
            {
                m_bullets.push_back(new BulletObject());

                m_shotTime -= fireTime;
            }
        }
        else
        {
            m_bullets.push_back(new BulletObject());
        }
    }

    void Player::Move(float _elapsedTime)
    {
        // 入力を取得
        float inputRight = Inputs::Instance().GetValue(L"Right");
        float inputUp = Inputs::Instance().GetValue(L"Up");

        // プレイヤーを移動させる
        Vector2 pos = Position();
        pos += Vector2(inputRight, inputUp) * gun.moveSpeed * _elapsedTime;

        Position(pos);
    }

    void Player::Start()
    {
    }

    void Player::OnDestroy()
    {
        for (BulletObject* bullet : m_bullets)
        {
            delete bullet;
        }

        m_bullets.clear();
    }
} // Character
} // Game
} // GFF
