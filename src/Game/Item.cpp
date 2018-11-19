//
// 制作者:      島田 竜之介
// 内容:        アイテム処理
// 作成日:      2018/11/7
// 最終更新日:  2018/11/19
//

#include "Item.h"
#include "Math/Vector2.h"

using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
    void Item::Update(float _elapsTime)
    {
        Move(_elapsTime);
    }

    void Item::SetBullet(const System::Bullet & _bullet)
    {
        bullet = _bullet;
    }

    void Item::Move(float _elapsTime)
    {
        const float speed = 100;
        Vector2 pos = Position();

        pos.x -= speed * _elapsTime;

        Position(pos);
    }
}//Game
}//GFF