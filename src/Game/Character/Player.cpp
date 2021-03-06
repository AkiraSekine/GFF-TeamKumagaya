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

using namespace std;

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
            //Shoot(_elapsedTime);
        }

        if (gun.isContinuous && !shot)
        {
            m_shotTime = 0.0f;
        }
    }

    void Player::LateUpdate(float _elapsedTime)
    {
        //// 破棄すべき状態の銃弾を分ける
        //auto tail_itr = remove_if(
        //    m_bullets.begin(),
        //    m_bullets.end(),
        //    [&](BulletObject* bullet)
        //    {
        //        // 銃弾が破棄されるべき状態なら分ける
        //        if (bullet->isDestroy)
        //        {
        //            delete bullet;
        //        }

        //        return bullet->isDestroy;
        //    });

        //// 分けられた銃弾を破棄する
        //m_bullets.erase(tail_itr, m_bullets.end());
    }

    void Player::Draw()
    {
        __super::Draw();

        for (BulletObject* bullet : m_bullets)
        {
            bullet->Draw(DirectX::Colors::Black);
        }
    }

    void Player::Shoot(float _elapsedTime)
    {
        // 連射可能か
        if (gun.isContinuous)
        {
            // 連射間隔を計算
            const float oneMinuts = 60.0f;
            const float fireTime = oneMinuts / gun.fireSpeed;

            m_shotTime += _elapsedTime;

            // 連射間隔を過ぎていたら銃弾を生成
            if (m_shotTime >= fireTime)
            {
                m_bullets.push_back(new BulletObject(GetImageHandle(), *this));
                m_bullets.back()->bullet = gun.bullet;

                m_shotTime -= fireTime;
            }
        }
        else
        {
            // 弾の生成
            m_bullets.push_back(new BulletObject(GetImageHandle(), *this));
            m_bullets.back()->bullet = gun.bullet;
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
