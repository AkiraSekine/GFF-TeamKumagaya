//
// 制作者:     関根 明良
// 内容:       弾オブジェクト
// 作成日:     2018/11/09
// 最終更新日:
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
        collider = new LineCollider(m_beforePos, Position());
    }

    void BulletObject::Move(float _elapsedTime)
    {
        m_beforePos = Position();

        Vector2 moveValue;

        moveValue = GetRightVector() * bullet.moveSpeed * _elapsedTime;

        Position(m_beforePos + moveValue);
    }
} // Game
} // GFF