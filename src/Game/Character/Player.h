//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/10/26
// 最終更新日:  2018/11/7
//

#pragma once

#include "ICharacter.h"

#include <vector>

#include "../../System/Equipment.h"

namespace GFF
{
 namespace Game
{
     class BulletObject;

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
        /// 銃データ
        /// </summary>
        static GFF::System::Gun gun;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// Updateの後に実行される更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void LateUpdate(float _elapsedTime) override;

        /// <summary>
        /// 描画処理
        /// </summary>
        void Draw();

    private:

        /// <summary>
        /// 銃弾配列
        /// </summary>
        std::vector<BulletObject*> m_bullets;

        /// <summary>
        /// 連射間隔の計測
        /// </summary>
        float m_shotTime = 0;

        /// <summary>
        /// 発射処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Shoot(float _elapsedTime) override;

        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() override;

        /// <summary>
        /// 終了処理
        /// </summary>
        virtual void OnDestroy() override;
    };

} // Character
} // Game
} // GFF