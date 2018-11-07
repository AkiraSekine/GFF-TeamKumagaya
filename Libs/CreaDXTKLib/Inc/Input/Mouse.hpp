#pragma once

#include "Input.h"

#include "Math/Vector2.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// �}�E�X����
    /// </summary>
    class Mouse final : public Utility::Singleton<Mouse>
    {
        SINGLETON(Mouse)

    public:

        /// <summary>
        /// ����������
        /// </summary>
        /// <param name="window">�E�B���h�E�n���h��</param>
        void Initialize(HWND window);

        /// <summary>
        /// �I������
        /// </summary>
        void OnEnd();

        /// <summary>
        /// �X�V����
        /// </summary>
        void Update();

        /// <summary>
        /// ���͂̎擾
        /// </summary>
        /// <param name="_button">���ׂ����{�^��</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        /// <returns>�L�[���`�F�b�N���@�̏�Ԃ�</returns>
        bool GetInput(const MouseButtons& _button, const CheckMode& _mode = CheckMode::Press);

        /// <summary>
        /// �}�E�X�̍��W���擾
        /// </summary>
        /// <returns>�}�E�X�̍��W</returns>
        Math::Vector2 Position();

        /// <summary>
        /// �}�E�X�̍��W��ݒ�
        /// </summary>
        /// <param name="_position">�V�������W</param>
        void Position(const Math::Vector2& _position);

        /// <summary>
        /// �J�[�\���̈ړ��l���擾
        /// </summary>
        /// <returns>�J�[�\���̈ړ��l</returns>
        Math::Vector2 GetMoveValue();

        /// <summary>
        /// �z�C�[���̈ړ��l���擾
        /// </summary>
        /// <returns>�ړ��l</returns>
        int GetWheelValue();

        /// <summary>
        /// �J�[�\����\�����邩��ݒ�
        /// </summary>
        /// <param name="_isVisible">�\�����邩</param>
        void CursorVisible(const bool& _isVisible);

        /// <summary>
        /// �J�[�\����\�����邩���擾
        /// </summary>
        /// <returns>�J�[�\����\�����邩</returns>
        bool CursorVisible();

    private:

        static const int m_numOfButtons = 5;

        unsigned char m_buttonState[m_numOfButtons];

        Math::Vector2 m_moveValue = Math::Vector2::zero;

        int m_wheelValue = 0;

        bool m_isVisible = true;

        std::unique_ptr<DirectX::Mouse> m_mouse;

        bool IsMouseDown(const MouseButtons& _button);
    };

} // Input
} // CreaDXTKLib