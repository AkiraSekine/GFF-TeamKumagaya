//
// 制作者:     関根 明良
// 内容:       弾オブジェクト
// 作成日:     2018/11/09
// 最終更新日: 2018/11/19
//

#pragma once

#include "IEntity.h"
#include "../System/Equipment.h"

namespace GFF
{
namespace Game
{
    /// <summary>
    /// 銃弾オブジェクト
    /// </summary>
    class BulletObject : public IEntity
    {
        OBJECT2D_PARENT(BulletObject, IEntity);

    public:

        /// <summary>
        /// 銃弾データ
        /// </summary>
        System::Bullet bullet;

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// 銃弾データの設定
        /// </summary>
        /// <param name="_bullet">銃弾データ</param>
        void SetBullet(const System::Bullet& _bullet);

        /// <summary>
        /// 描画処理
        /// </summary>
        /// <param name="_color">加算色</param>
        void Draw(const DirectX::XMVECTORF32& _color = DirectX::Colors::White);

    private:

        /// <summary>
        /// 前フレームの座標
        /// </summary>
        CreaDXTKLib::Math::Vector2 m_beforePos;

        /// <summary>
        /// 初期位置
        /// </summary>
        CreaDXTKLib::Math::Vector2 m_startPos;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() override;
        /// <summary>
        /// 移動処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        void Move(float _elapsedTime);
    };
} // Game
} // GFF