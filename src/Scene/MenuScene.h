//
// 制作者:     関根 明良
// 内容:       メニューシーン
// 作成日:     2018/12/04
// 最終更新日:
//

#pragma once

#include "CreaDXTKLib/Scene.h"

#include "../UI/Button.h"

namespace GFF
{
namespace Scene
{
    /// <summary>
    /// メニューシーン
    /// </summary>
    class MenuScene : public CreaDXTKLib::Scene
    {
    public:

        MenuScene();
        virtual ~MenuScene();

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// 描画処理
        /// </summary>
        virtual void OnRender() override;

    private:

        UI::Button m_doneButton;
        UI::Button m_backButton;
    };
} // Scene
} // GFF