//
// �����:     �֍� ����
// ���e:       �e�I�u�W�F�N�g
// �쐬��:     2018/11/09
// �ŏI�X�V��: 2018/11/19
//

#include "BulletObject.h"

#include "Math/Collider2D.h"

using namespace CreaDXTKLib::Math;

using namespace GFF::System;

namespace GFF
{
namespace Game
{
    void BulletObject::Update(float _elapsedTime)
    {
        Move(_elapsedTime);
    }

    void BulletObject::SetBullet(const Bullet& _bullet)
    {
        bullet = _bullet;
    }

    void BulletObject::Start()
    {
        // �����R���C�_�[���ړ��O���W����ړ�����W�̐����Ő���
        collider = new LineCollider(m_beforePos, Position());
    }

    void BulletObject::Move(float _elapsedTime)
    {
        // �ړ��O�̍��W���擾
        m_beforePos = Position();

        Vector2 moveValue;

        // �ړ��l���v�Z���Ĉړ�������
        moveValue = GetRightVector() * bullet.moveSpeed * _elapsedTime;

        Position(m_beforePos + moveValue);
    }
} // Game
} // GFF