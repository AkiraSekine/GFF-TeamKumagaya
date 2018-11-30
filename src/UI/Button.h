//
// 制作者:     関根 明良
// 内容:       ボタンUIクラス
// 作成日:     2018/11/29
// 最終更新日:
//

#pragma once

#include "CreaDXTKLib/Object.h"

namespace GFF
{
namespace UI
{
    class Button : public CreaDXTKLib::Object2D
    {
        OBJECT2D(Button)

    public:

        /// <summary>
        /// 状態
        /// </summary>
        enum struct State
        {
            None,    // 使用不可
            Normal,  // 通常
            Select,  // 選択中
            Pressed  // 押されている
        };

        /// <summary>
        /// 方向
        /// </summary>
        enum struct Direction
        {
            Up,     // 上
            Bottom, // 下
            Left,   // 左
            Right   // 右
        };

        /// <summary>
        /// 状態毎の加算色を設定
        /// </summary>
        /// <param name="_color">加算色</param>
        /// <param name="_state">状態</param>
        void SetStateColor(const DirectX::XMVECTORF32& _color, const State& _state);

        /// <summary>
        /// 移動先のボタンを設定
        /// </summary>
        /// <param name="_button">移動先のボタン</param>
        /// <param name="_direction">方向</param>
        void SetDestinationButton(Button& _button, const Direction& _direction);

        /// <summary>
        /// 更新処理
        /// </summary>
        /// <param name="_elapsedTime">前フレームからの経過時間</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// 描画処理
        /// </summary>
        void Draw();

        /// <summary>
        /// 決定されたかを取得
        /// </summary>
        /// <returns>決定されたか</returns>
        bool IsDone();

        /// <summary>
        /// 選択されている状態に設定
        /// </summary>
        void SetSelect();

    private:
        
        /// <summary>
        /// 移動先の数
        /// </summary>
        static const int numOfDestinate = 4;
        /// <summary>
        /// 状態の数
        /// </summary>
        static const int numOfState = 4;

        /// <summary>
        /// 選択中のボタン
        /// </summary>
        static Button* m_selectButton;

        /// <summary>
        /// 現在の状態
        /// </summary>
        State m_state = State::None;

        /// <summary>
        /// 移動先のボタン
        /// </summary>
        Button* m_destinations[numOfDestinate];

        /// <summary>
        /// 加算色
        /// </summary>
        DirectX::XMVECTORF32 m_colors[numOfState];

        /// <summary>
        /// 決定されたか
        /// </summary>
        bool m_isDone;

        /// <summary>
        /// 開始処理
        /// </summary>
        virtual void Start() override;

        /// <summary>
        /// 隣のボタンを選択状態にする
        /// </summary>
        /// <param name="_direction">移動先の方向</param>
        void ChangeSelect(const Direction& _direction);
    };
} // UI
} // GFF