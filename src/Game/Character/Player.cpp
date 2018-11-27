//
// �����:      ���c ���V��
// ���e:        �v���C���[����
// �쐬��:      2018/11/7
// �ŏI�X�V��:
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
        
        // ���˃L�[�������ꂽ��e�e�𔭎˂���
        if (shot)
        {
            Shoot(_elapsedTime);
        }

        if (m_gun.isContinuous && !shot)
        {
            m_shotTime = 0.0f;
        }

        int bulletCount = 0;

        // �e�e�̍X�V����
        for (BulletObject* bullet : m_bullets)
        {
            bullet->Update(_elapsedTime);

            // �e�e���j�������ׂ���ԂȂ�j������
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
        // �A�ˉ\��
        if (m_gun.isContinuous)
        {
            // �A�ˊԊu���v�Z
            const float fireTime = 1.0f / m_gun.fireSpeed / 60.0f;

            m_shotTime += _elapsedTime;

            // �A�ˊԊu���߂��Ă�����e�e�𐶐�
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
        // ���͂��擾
        float inputRight = Inputs::Instance().GetValue(L"Right");
        float inputUp = Inputs::Instance().GetValue(L"Up");

        // �v���C���[���ړ�������
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
