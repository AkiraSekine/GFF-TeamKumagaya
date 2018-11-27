//
// 制作者:     関根 明良
// 内容:       キャラクターインターフェース
// 作成日:     2018/10/26
// 最終更新日: 2018/10/28
//

#pragma once

#include "../IEntity.h"

#include "../../System/Equipment.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    /// <summary>
    /// キャラクターインターフェース
    /// </summary>
    class ICharacter : public IEntity
    {
        OBJECT2D_PARENT(ICharacter, IEntity)

    public:

        /// <summary>
        /// 体力
        /// </summary>
        float HP;

        /// <summary>
        /// 銃の情報を取得
        /// </summary>
        virtual inline System::Gun GetGunData() const final
        {
            return m_gun;
        }

    protected:

        /// <summary>
        /// 銃の情報
        /// </summary>
        System::Gun m_gun;

        /// <summary>
        /// 防御力
        /// </summary>
        float m_defence;

        /// <summary>
        /// 弾の発射処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Shoot(float _elapsedTime) ABSTRACT;

        /// <summary>
        /// 移動処理
        /// </summary>
        virtual void Move(float _elapsedTime) ABSTRACT;
    };
} // Character
} // Game
} // GFF