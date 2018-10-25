#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"

namespace CreaDXTKLib
{
namespace Audio
{
    /// <summary>
    /// �T�E���h�֌W�̏���
    /// </summary>
    class SoundSystem final : public Utility::Singleton<SoundSystem>
    {
        SINGLETON(SoundSystem)

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
        /// �I������
        /// </summary>
        void OnEnd();

        /// <summary>
        /// �I�[�f�B�I�G���W���̎擾
        /// </summary>
        /// <returns>�I�[�f�B�I�G���W��</returns>
        DirectX::AudioEngine* GetAudioEngine();

        /// <summary>
        /// �I�[�f�B�I�f�o�C�X���Č��o������
        /// </summary>
        void OnNewAudioDevice();

        /// <summary>
        /// �T�C�����g���[�h���̎擾
        /// </summary>
        /// <returns>�T�C�����g���[�h��</returns>
        bool IsSilent();

    private:

        bool m_isSilent;
        bool m_retryAudio;

        std::unique_ptr<DirectX::AudioEngine> m_audioEngine;
    };
} // Audio
} // CreaDXTKLib