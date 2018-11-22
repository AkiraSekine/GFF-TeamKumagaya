//
// 制作者:     関根 明良
// 内容:       ゲーム内に登場するオブジェクトに継承させるクラス
// 作成日:     2018/11/21
// 最終更新日:
//

#include "IEntity.h"

#include "Math/Collider2D.h"

using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
    void IEntity::AddColliderTarget(Collider2D * _target)
    {
        collider->AddTarget(_target);
    }

    void IEntity::EraseColliderTarget(CreaDXTKLib::Math::Collider2D * _target)
    {
        collider->EraseTarget(_target);
    }
} // Game
} // GFF