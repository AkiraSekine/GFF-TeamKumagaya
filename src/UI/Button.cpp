//
// 制作者:     関根 明良
// 内容:       ボタンUIクラス
// 作成日:     2018/11/29
// 最終更新日: 2018/12/17
//

#include "Button.h"

#include "Input/Input.h"
#include "Input/Mouse.hpp"
#include "Math/Vector2.h"
#include "Draw/Image.h"
#include "Draw/Text.h"

#include "../Math/Math.h"

using namespace std;

using namespace DirectX;

using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Math;
using namespace CreaDXTKLib::Draw;

using namespace GFF::Math;

namespace GFF
{
namespace UI
{
    Button* Button::m_selectButton;
    bool Button::noProcess = false;

    void Button::SetStateColor(const XMVECTORF32 & _color, const State & _state)
    {
        m_colors[(int)_state] = _color;
    }

    void Button::SetDestinationButton(Button & _button, const Direction & _direction)
    {
        m_destinations[(int)_direction] = &_button;
    }

    void Button::SetString(const wstring & _name, const Vector2 & _position, const wstring _text)
    {
        m_fontHandle = _name;

        m_textPos = _position;

        m_text = _text;
    }

    void Button::SetTextColor(const XMVECTORF32 & _color)
    {
        m_textColor = _color;
    }

    void Button::Update(float _elapsedTime)
    {
        _elapsedTime;

        if (noProcess)
        {
            return;
        }

        // マウスでの決定入力を取得
        float done = Inputs::Instance().GetValue(L"DoneMouse");

        // カーソル座標を取得
        Vector2 mousePos = CreaDXTKLib::Input::Mouse::Instance().Position();

        // 画像サイズを取得
        Vector2 imageSize = GetImageSize() * Scale() * 0.5f;

        // 中心座標を取得
        Vector2 pos = Position();

        // カーソルがボタンの画像内に入っていたら
        if (Within<float>(mousePos.x, pos.x - imageSize.x, pos.x + imageSize.x) &&
            Within<float>(mousePos.y, pos.y - imageSize.y, pos.y + imageSize.y))
        {
            // このボタンを選択状態にする
            if (m_state == State::Normal)
            {
                SetSelect();
            }

            // ボタン上でクリックされたら押されている状態に
            // ボタン上でクリックを放したら決定された状態にする
            if (done > 0)
            {
                m_state = State::Pressed;
            }
            else if (done < 0 && m_state == State::Pressed)
            {
                m_isDone = true;
            }
        }
        // ボタンが押されている状態でカーソルが画像の範囲外に出たら選択状態に変更
        else if (m_state == State::Pressed)
        {
            m_state = State::Select;
        }

        if (m_state != State::Select)
        {
            return;
        }

        // 縦方向と横方向の入力を取得
        float verticalInput = Inputs::Instance().GetValue(L"Vertical");
        float horizontalInput = Inputs::Instance().GetValue(L"Horizontal");

        // 方向の入力があったらその方向のボタンを選択する
        if (verticalInput > 0)
        {
            ChangeSelect(Direction::Up);

            noProcess = true;
        }
        else if (verticalInput < 0)
        {
            ChangeSelect(Direction::Bottom);

            noProcess = true;
        }

        if (horizontalInput > 0)
        {
            ChangeSelect(Direction::Right);

            noProcess = true;
        }
        else if (horizontalInput < 0)
        {
            ChangeSelect(Direction::Left);

            noProcess = true;
        }
    }

    void Button::Draw()
    {
        // 現在の状態に合わせて加算色を変えて描画
        Image::Instance().Draw(GetImageHandle(), *this, m_colors[(int)m_state], GetImageSize() / 2.0f);

        Text::Instance().Draw(m_fontHandle, Position() + m_textPos, m_textColor, m_text);
    }

    bool Button::IsDone()
    {
        // このボタンが選択状態で決定されたら決定されている状態に変更
        if (m_state == State::Select && Inputs::Instance().GetValue(L"Done"))
        {
            m_isDone = true;
        }

        return m_isDone;
    }

    void Button::SetSelect()
    {
        if (m_selectButton != nullptr)
        {
            // 元の選択状態のボタンを通常の状態にし、このボタンを選択状態に設定
            m_selectButton->m_state = State::Normal;
        }

        m_selectButton = this;

        m_state = State::Select;
    }

    void Button::Start()
    {
        // m_destinationsの初期化
        for (int i = 0; i < numOfDestinate; i++)
        {
            m_destinations[i] = nullptr;
        }

        // m_colorsの初期化
        for (int i = 0; i < numOfState; i++)
        {
            m_colors[i] = Colors::White;
        }

        m_isDone = false;
    }

    void Button::ChangeSelect(const Direction & _direction)
    {
        Button* button = m_destinations[(int)_direction];

        if (button != nullptr && button->m_state != State::None)
        {
            // 指定された方向のボタンを選択状態に設定
            m_state = State::Normal;

            button->m_state = State::Select;

            m_selectButton = button;
        }
    }
} // UI
} // GFF