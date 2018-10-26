//
// 制作者:     関根 明良
// 内容:       装備データ
// 作成日:     2018/10/26
// 最終更新日:
//

#pragma once

namespace GFF
{
namespace System
{
    /// <summary>
    /// 銃弾データ
    /// </summary>
    struct Bullet
    {
        /// <summary>
        /// 威力
        /// </summary>
        float power;
        /// <summary>
        /// 反動
        /// </summary>
        float recoil;
        /// <summary>
        /// 弾速
        /// </summary>
        float moveSpeed;
        /// <summary>
        /// 射程距離
        /// </summary>
        float distance;
    };

    /// <summary>
    /// 銃データ
    /// </summary>
    struct Gun
    {
        /// <summary>
        /// 移動速度
        /// </summary>
        float moveSpeed;
        /// <summary>
        /// 連射速度
        /// </summary>
        float fireSpeed;
        /// <summary>
        /// リロード時間
        /// </summary>
        float reloadTime;
        /// <summary>
        /// 精度
        /// </summary>
        float accuracy;
        /// <summary>
        /// 連射可能か
        /// </summary>
        bool isContinuous;
        /// <summary>
        /// 使用中の銃弾
        /// </summary>
        Bullet bullet;
    };
} // System
} // GFF