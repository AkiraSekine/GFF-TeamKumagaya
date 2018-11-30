//
// �����:     �֍� ����
// ���e:       �{�^��UI�N���X
// �쐬��:     2018/11/29
// �ŏI�X�V��:
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
        State m_state = State::None;

        /// <summary>
        /// �ړ���̃{�^��
        /// </summary>
        Button* m_destinations[numOfDestinate];

        /// <summary>
        /// ���Z�F
        /// </summary>
        DirectX::XMVECTORF32 m_colors[numOfState];

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