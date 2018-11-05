//
// 制作者:     関根 明良
// 内容:       敵クラス
// 作成日:     2018/10/26
// 最終更新日:
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
    /// 敵クラス
    /// </summary>
    class Enemy : public ICharacter
    {
        OBJECT2D_PARENT(Enemy, ICharacter)

    public:

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

    protected:

        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Move(float _elapsedTime) override;

    private:

        /// <summary>
        /// プレイヤー情報
        /// </summary>
        //static Player* m_player;
    };
} // Character
} // Game
} // GFF