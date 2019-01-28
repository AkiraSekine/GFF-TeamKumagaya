//
// §ìÒ:      “‡“c —³”V‰î
// “à—e:        ƒvƒŒƒCƒ„[ˆ—
// ì¬“ú:      2018/11/7
// ÅIXV“ú:
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
        
        // ”­ËƒL[‚ª‰Ÿ‚³‚ê‚½‚çe’e‚ğ”­Ë‚·‚é
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
        //// ”jŠü‚·‚×‚«ó‘Ô‚Ìe’e‚ğ•ª‚¯‚é
        //auto tail_itr = remove_if(
        //    m_bullets.begin(),
        //    m_bullets.end(),
        //    [&](BulletObject* bullet)
        //    {
        //        // e’e‚ª”jŠü‚³‚ê‚é‚×‚«ó‘Ô‚È‚ç•ª‚¯‚é
        //        if (bullet->isDestroy)
        //        {
        //            delete bullet;
        //        }

        //        return bullet->isDestroy;
        //    });

        //// •ª‚¯‚ç‚ê‚½e’e‚ğ”jŠü‚·‚é
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
        // ˜AË‰Â”\‚©
        if (gun.isContinuous)
        {
            // ˜AËŠÔŠu‚ğŒvZ
            const float oneMinuts = 60.0f;
            const float fireTime = oneMinuts / gun.fireSpeed;

            m_shotTime += _elapsedTime;

            // ˜AËŠÔŠu‚ğ‰ß‚¬‚Ä‚¢‚½‚çe’e‚ğ¶¬
            if (m_shotTime >= fireTime)
            {
                m_bullets.push_back(new BulletObject(GetImageHandle(), *this));
                m_bullets.back()->bullet = gun.bullet;

                m_shotTime -= fireTime;
            }
        }
        else
        {
            // ’e‚Ì¶¬
            m_bullets.push_back(new BulletObject(GetImageHandle(), *this));
            m_bullets.back()->bullet = gun.bullet;
        }
    }

    void Player::Move(float _elapsedTime)
    {
        // “ü—Í‚ğæ“¾
        float inputRight = Inputs::Instance().GetValue(L"Right");
        float inputUp = Inputs::Instance().GetValue(L"Up");

        // ƒvƒŒƒCƒ„[‚ğˆÚ“®‚³‚¹‚é
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
