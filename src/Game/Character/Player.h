//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/10/26
// 最終更新日:  2018/11/7
//

#pragma once

#include "ICharacter.h"

namespace GFF
{
 namespace Game
{
namespace Character
{
    /// <summary>
    /// プレイヤークラス
    /// </summary>
    class Player : public ICharacter
    {
        OBJECT2D_PARENT(Player, ICharacter);

    public:

        /// <summary>
        /// 発射処理
        /// </summary>
        virtual void Shoot() override;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

    private:

        /// <summary>
        /// 
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() override;
    };

} // Character
} // Game
} // GFF