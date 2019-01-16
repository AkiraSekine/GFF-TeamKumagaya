//
// �����:     �֍� ����
// ���e:       �{�^��UI�N���X
// �쐬��:     2018/11/29
// �ŏI�X�V��: 2018/12/17
//

#pragma once

#include "CreaDXTKLib/Object.h"

namespace GFF
{
namespace UI
{
    /// <summary>
    /// �{�^��UI�N���X
    /// </summary>
    class Button : public CreaDXTKLib::Object2D
    {
        OBJECT2D(Button)

    public:

        /// <summary>
        /// ���
        /// </summary>
        enum struct State
        {
            None,    // �g�p�s��
            Normal,  // �ʏ�
            Select,  // �I��
            Pressed  // ������Ă���
        };

        /// <summary>
        /// ����
        /// </summary>
        enum struct Direction
        {
            Up,     // ��
            Bottom, // ��
            Left,   // ��
            Right   // �E
        };

        static bool noProcess;

        /// <summary>
        /// ��Ԗ��̉��Z�F��ݒ�
        /// </summary>
        /// <param name="_color">���Z�F</param>
        /// <param name="_state">���</param>
        void SetStateColor(const DirectX::XMVECTORF32& _color, const State& _state);

        /// <summary>
        /// �ړ���̃{�^����ݒ�
        /// </summary>
        /// <param name="_button">�ړ���̃{�^��</param>
        /// <param name="_direction">����</param>
        void SetDestinationButton(Button& _button, const Direction& _direction);

        /// <summary>
        /// ������̐ݒ�
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_position">�`��ʒu</param>
        /// <param name="_text">�`�敶����</param>
        void SetString(const std::wstring& _name, const CreaDXTKLib::Math::Vector2& _position, const std::wstring _text);

        /// <summary>
        /// �`�敶����̐F��ݒ�
        /// </summary>
        /// <param name="_color">�F</param>
        void SetTextColor(const DirectX::XMVECTORF32& _color);

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw();

        /// <summary>
        /// ���肳�ꂽ�����擾
        /// </summary>
        /// <returns>���肳�ꂽ��</returns>
        bool IsDone();

        /// <summary>
        /// �I������Ă����Ԃɐݒ�
        /// </summary>
        void SetSelect();

    private:
        
        /// <summary>
        /// �ړ���̐�
        /// </summary>
        static const int numOfDestinate = 4;
        /// <summary>
        /// ��Ԃ̐�
        /// </summary>
        static const int numOfState = 4;

        /// <summary>
        /// �I�𒆂̃{�^��
        /// </summary>
        static Button* m_selectButton;

        /// <summary>
        /// ���݂̏��
        /// </summary>
        State m_state = State::Normal;

        /// <summary>
        /// �ړ���̃{�^��
        /// </summary>
        Button* m_destinations[numOfDestinate];

        /// <summary>
        /// ���Z�F
        /// </summary>
        DirectX::XMVECTORF32 m_colors[numOfState];

        /// <summary>
        /// ������̐F
        /// </summary>
        DirectX::XMVECTORF32 m_textColor;

        /// <summary>
        /// �`�敶����
        /// </summary>
        std::wstring m_text;

        /// <summary>
        /// �t�H���g�n���h��
        /// </summary>
        std::wstring m_fontHandle;

        /// <summary>
        /// �`�敶����̍��W
        /// </summary>
        CreaDXTKLib::Math::Vector2 m_textPos;

        /// <summary>
        /// ���肳�ꂽ��
        /// </summary>
        bool m_isDone;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;

        /// <summary>
        /// �ׂ̃{�^����I����Ԃɂ���
        /// </summary>
        /// <param name="_direction">�ړ���̕���</param>
        void ChangeSelect(const Direction& _direction);
    };
} // UI
} // GFF