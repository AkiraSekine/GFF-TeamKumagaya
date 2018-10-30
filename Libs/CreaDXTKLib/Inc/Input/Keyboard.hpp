#pragma once

#include "Input.h"

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// �L�[����
    /// </summary>
    class Keyboard final : public Utility::Singleton<Keyboard>
    {
        SINGLETON(Keyboard)

    public:

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize();

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
        /// <param name="_key">���ׂ����L�[</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        /// <returns>�L�[���`�F�b�N���@�̏�Ԃ�</returns>
        bool GetInput(Keys _key, CheckMode _mode = CheckMode::Press);

    private:

        static const int m_numOfKeys = 256;

        unsigned char m_keyState[m_numOfKeys];

        std::unique_ptr<DirectX::Keyboard> m_keyboard;
    };
} // Input
} // CreaDXTKLib