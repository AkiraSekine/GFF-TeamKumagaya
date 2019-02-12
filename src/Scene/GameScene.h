//
// 制作者:     関根 明良
// 内容:       ゲームシーン
// 作成日:     2018/10/26
// 最終更新日: 2018/11/27
//

#pragma once

#include "CreaDXTKLib/Scene.h"

#include "../System/Equipment.h"

#include "../Game/Character/Enemy.h"

namespace CreaDXTKLib
{
    class Scene;
}

namespace GFF
{
    namespace Game
    {
        namespace Character
        {
            class Player;
        }
    }

namespace Scene
{
    /// <summary>
    /// ゲームシーン
    /// </summary>
    class GameScene : public CreaDXTKLib::Scene
    {
    public:

        GameScene();
        virtual ~GameScene() override;

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

        /// <summary>
        /// プレイヤー
        /// </summary>
        GFF::Game::Character::Player* m_player;

        /// <summary>
        /// 敵
        /// </summary>
        std::vector<GFF::Game::Character::Enemy*> m_enemys;

        /// <summary>
        /// 装備のパラメータ
        /// </summary>
        GFF::System::EquipmentDatas m_equipmentDatas;
    };
} // Scene
} // GFF