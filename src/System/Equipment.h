//
// 制作者:     関根 明良
// 内容:       装備データ
// 作成日:     2018/10/26
// 最終更新日: 2018/11/27
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
        enum struct Kind
        {
            mm9,    // HG, SMG
            mm5p56, // AR
            mm7p62, // MG
            GA12,   // SG
            mm12p7  // SR
        };

        /// <summary>
        /// 弾の種類
        /// </summary>
        Kind kind;

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
        enum struct Kind
        {
            HG,
            SMG,
            AR,
            MG,
            SG,
            SR
        };

        /// <summary>
        /// 銃の種類
        /// </summary>
        Kind kind;

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

    /// <summary>
    /// 銃弾の種類数
    /// </summary>
    static const int NumOfBullets = 5;
    /// <summary>
    /// 銃の種類数
    /// </summary>
    static const int NumOfGuns = 6;

    /// <summary>
    /// 銃弾と銃のパラメータ
    /// </summary>
    struct EquipmentDatas
    {
        /// <summary>
        /// 銃弾データ
        /// </summary>
        Bullet bulletData[NumOfBullets];
        /// <summary>
        /// 銃データ
        /// </summary>
        Gun gunData[NumOfGuns];
    };
} // System
} // GFF