//
// 制作者:     関根 明良
// 内容:       敵クラス
// 作成日:     2018/10/26
// 最終更新日: 2018/11/23
//

#pragma once

#include "ICharacter.h"

#include "../../System/Equipment.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    class Player;

    /// <summary>
    /// 敵クラス
    /// </summary>
    class Enemy : public ICharacter
    {
        OBJECT2D_PARENT(Enemy, ICharacter)

    public:

        /// <summary>
        /// 銃情報
        /// </summary>
        System::Gun gunData;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// プレイヤーを設定
        /// </summary>
        /// <param name="_player">プレイヤー</param>
        static void SetPlayer(Player* _player);

    protected:

        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() override;

    private:

        /// <summary>
        /// プレイヤー情報
        /// </summary>
        static Player* m_player;
    };
} // Character
} // Game
} // GFF