//
// �����:     �֍� ����
// ���e:       �e�I�u�W�F�N�g
// �쐬��:     2018/11/09
// �ŏI�X�V��: 2018/11/19
//

#include "BulletObject.h"

#include "Math/Collider2D.h"
#include "Draw/Image.h"

using namespace CreaDXTKLib::Math;
using namespace CreaDXTKLib::Draw;

using namespace GFF::System;

namespace GFF
{
namespace Game
{
    void BulletObject::Update(float _elapsedTime)
    {
        Move(_elapsedTime);

        Vector2 distance = Position() - m_startPos;

        if (distance.SqrMagnitude() > bullet.distance * bullet.distance ||
            collider->CheckCollision() != nullptr)
        {
            isDestroy = true;
        }
    }

    void BulletObject::SetBullet(const Bullet& _bullet)
    {
        bullet = _bullet;
    }

    void BulletObject::Draw(const DirectX::XMVECTORF32& _color)
    {
        Image::Instance().Draw(L"Dot", *this, _color, Vector2::zero);
    }

    void BulletObject::Start()
    {
        m_startPos = Position();

        // �����R���C�_�[���ړ��O���W����ړ�����W�̐����Ő���
        collider = new LineCollider(m_beforePos, Position());
    }

    void BulletObject::Move(float _elapsedTime)
    {
        // �ړ��O�̍��W���擾
        m_beforePos = Position();

        Vector2 moveValue;
        Vector2 newPos;

        // �ړ��l���v�Z���Ĉړ�������
        moveValue = GetRightVector() * bullet.moveSpeed * _elapsedTime;

        newPos = m_beforePos + moveValue;

        Position(newPos);

        Vector2 distance = newPos - m_beforePos;

        Scale(Vector2(distance.Magnitude(), 1.0f));

        Rotation(atan2f(distance.y, distance.x));
    }
} // Game
} // GFF