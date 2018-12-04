//
// 制作者:     関根 明良
// 内容:       弾オブジェクト
// 作成日:     2018/11/09
// 最終更新日: 2018/11/19
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

        // 線分コライダーを移動前座標から移動後座標の線分で生成
        collider = new LineCollider(m_beforePos, Position());
    }

    void BulletObject::Move(float _elapsedTime)
    {
        // 移動前の座標を取得
        m_beforePos = Position();

        Vector2 moveValue;
        Vector2 newPos;

        // 移動値を計算して移動させる
        moveValue = GetRightVector() * bullet.moveSpeed * _elapsedTime;

        newPos = m_beforePos + moveValue;

        Position(newPos);

        Vector2 distance = newPos - m_beforePos;

        Scale(Vector2(distance.Magnitude(), 1.0f));

        Rotation(atan2f(distance.y, distance.x));
    }
} // Game
} // GFF