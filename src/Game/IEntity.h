//
// 制作者:     関根 明良
// 内容:       ゲーム内に登場するオブジェクトに継承させるクラス
// 作成日:     2018/10/26
// 最終更新日: 2018/11/19
//

#pragma once

#include "CreaDXTKLib/Object.h"

namespace CreaDXTKLib
{
    namespace Math
    {
        class Collider2D;
    }
}

namespace GFF
{
namespace Game
{
    /// <summary>
    /// ゲーム内に登場するオブジェクトに継承させるクラス
    /// </summary>
    class IEntity : public CreaDXTKLib::Object2D
    {
        OBJECT2D(IEntity)

    public:

        /// <summary>
        /// コライダー
        /// </summary>
        CreaDXTKLib::Math::Collider2D* collider = nullptr;

        /// <summary>
        /// ターゲットコライダーの追加
        /// </summary>
        /// <param name="_target">ターゲットコライダー</param>
        virtual void AddColliderTarget(CreaDXTKLib::Math::Collider2D* _target) final;

        /// <summary>
        /// ターゲットコライダーを削除
        /// </summary>
        /// <param name="_target">ターゲットコライダー</param>
        virtual void EraseColliderTarget(CreaDXTKLib::Math::Collider2D* _target) final;

    private:

    };
}
}