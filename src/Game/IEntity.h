//
// 制作者:     関根 明良
// 内容:       ゲーム内に登場するオブジェクトに継承させるクラス
// 作成日:     2018/10/26
// 最終更新日: 2018/10/28
//

#pragma once

#include "CreaDXTKLib/Object.h"

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

    private:

    };
}
}