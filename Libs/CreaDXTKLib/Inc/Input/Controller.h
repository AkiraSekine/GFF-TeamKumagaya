#pragma once

#include "DirectXTK/pch.h"

#include "Utility/Singleton.h"
#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    class Controller : public Utility::Singleton<Controller>
    {
        SINGLETON(Controller)

    public:

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize();
        /// <summary>
        /// �X�V����
        /// </summary>
        void Update();
        /// <summary>
        /// ��A�N�e�B�u�A�ŏ���������
        /// </summary>
        void OnSuspend();
        /// <summary>
        /// �A�N�e�B�u������
        /// </summary>
        void OnResume();

        /// <summary>
        /// ���͏�Ԃ��擾
        /// </summary>
        /// <param name="_num">�R���g���[���[�ԍ�</param>
        /// <param name="_parts">�R���g���[���[�p�[�c</param>
        /// <param name="_checkMode">�`�F�b�N���@</param>
        /// <returns>�p�[�c���`�F�b�N���@�̏�Ԃ�</returns>
        bool GetInput(const int& _num, const ControllerParts& _parts, const CheckMode& _checkMode = CheckMode::Press);

        /// <summary>
        /// ���͂̒l���擾
        /// </summary>
        /// <param name="_num">�R���g���[���[�ԍ�</param>
        /// <param name="_parts">�R���g���[���[�p�[�c</param>
        /// <returns>���͂̒l</returns>
        float GetVelue(const int& _num, const ControllerParts& _parts);

        /// <summary>
        /// �o�C�u���[�V����
        /// </summary>
        /// <param name="_num">�R���g���[���[�ԍ�</param>
        /// <param name="_left">���̒l</param>
        /// <param name="_right">�E�̒l</param>
        void Vibration(const int& _num, const float& _left, const float& _right);

    private:

        static const char m_maxControllerCount = 4;
        static const char m_numOfButtons = 16;
        static const char m_numOfValues = 6;

        const char m_triggerNum = (char)ControllerParts::LTrigger;

        unsigned char m_buttonStates[m_maxControllerCount][m_numOfButtons];
        float m_values[m_maxControllerCount][m_numOfValues];

        std::unique_ptr<DirectX::GamePad> m_gamePad;

        void SetState(const int& _num, const ControllerParts& _parts, const bool& _state);
    };
} // Input
} // CreaDXTKLib