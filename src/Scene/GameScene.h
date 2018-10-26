//
// 制作者:     関根 明良
// 内容:       ゲームシーン
// 作成日:     2018/10/26
// 最終更新日:
//

#pragma once

#include "CreaDXTKLib/Scene.h"

namespace GFF
{
namespace Scene
{
    /// <summary>
    /// ゲームシーン
    /// </summary>
    class GameScene : public CreaDXTKLib::Scene
    {
    public:

        virtual void Update(float _elapsedTime) override;
        virtual void OnRender() override;

    private:

    };
} // Scene
} // GFF