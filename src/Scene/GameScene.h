//
// 制作者:     関根 明良
// 内容:       ゲームシーン
// 作成日:     2018/10/26
// 最終更新日:
//

#pragma once

#include "CreaDXTKLib/Scene.h"
#include "../Game/Character/Player.h"

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
        GameScene();
        ~GameScene();
        virtual void Update(float _elapsedTime) override;
        virtual void OnRender() override;

    private:
        GFF::Game::Character::Player m_player;
    };
} // Scene
} // GFF