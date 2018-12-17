//
// �����:     �֍� ����
// ���e:       �{�^��UI�N���X
// �쐬��:     2018/11/29
// �ŏI�X�V��:
//

#include "Button.h"

#include "Input/Input.h"
#include "Input/Mouse.hpp"
#include "Math/Vector2.h"
#include "Draw/Image.h"

#include "../Math/Math.h"

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

    void Button::Update(float _elapsedTime)
    {
        _elapsedTime;

        if (noProcess)
        {
            return;
        }

        // �}�E�X�ł̌�����͂��擾
        float done = Inputs::Instance().GetValue(L"DoneMouse");

        // �J�[�\�����W���擾
        Vector2 mousePos = CreaDXTKLib::Input::Mouse::Instance().Position();

        // �摜�T�C�Y���擾
        Vector2 imageSize = GetImageSize() * Scale() * 0.5f;

        // ���S���W���擾
        Vector2 pos = Position();

        // �J�[�\�����{�^���̉摜���ɓ����Ă�����
        if (Within<float>(mousePos.x, pos.x - imageSize.x, pos.x + imageSize.x) &&
            Within<float>(mousePos.y, pos.y - imageSize.y, pos.y + imageSize.y))
        {
            // ���̃{�^����I����Ԃɂ���
            SetSelect();

            // �{�^����ŃN���b�N���ꂽ�牟����Ă����Ԃ�
            // �{�^����ŃN���b�N��������猈�肳�ꂽ��Ԃɂ���
            if (done > 0)
            {
                m_state = State::Pressed;
            }
            else if (done < 0 && m_state == State::Pressed)
            {
                m_isDone = true;
            }
        }
        // �{�^����������Ă����ԂŃJ�[�\�����摜�͈̔͊O�ɏo����I����ԂɕύX
        else if (m_state == State::Pressed)
        {
            m_state = State::Select;
        }

        if (m_state != State::Select)
        {
            return;
        }

        // �c�����Ɖ������̓��͂��擾
        float verticalInput = Inputs::Instance().GetValue(L"Vertical");
        float horizontalInput = Inputs::Instance().GetValue(L"Horizontal");

        // �����̓��͂��������炻�̕����̃{�^����I������
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
        // ���݂̏�Ԃɍ��킹�ĉ��Z�F��ς��ĕ`��
        Image::Instance().Draw(GetImageHandle(), *this, m_colors[(int)m_state], GetImageSize() / 2.0f);
    }

    bool Button::IsDone()
    {
        // ���̃{�^�����I����ԂŌ��肳�ꂽ�猈�肳��Ă����ԂɕύX
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
            // ���̑I����Ԃ̃{�^����ʏ�̏�Ԃɂ��A���̃{�^����I����Ԃɐݒ�
            m_selectButton->m_state = State::Normal;
        }

        m_selectButton = this;

        m_state = State::Select;
    }

    void Button::Start()
    {
        // m_destinations�̏�����
        for (int i = 0; i < numOfDestinate; i++)
        {
            m_destinations[i] = nullptr;
        }

        // m_colors�̏�����
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
            // �w�肳�ꂽ�����̃{�^����I����Ԃɐݒ�
            m_state = State::Normal;

            button->m_state = State::Select;

            m_selectButton = button;
        }
    }
} // UI
} // GFF