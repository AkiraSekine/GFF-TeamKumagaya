#pragma once

#include "../Utility/Singleton.h"
#include "../Default/pch.h"

#include <map>

namespace CreaDXTKLib
{
namespace Audio
{
    /// <summary>
    /// �����N���X
    /// </summary>
    class Sound final : public Utility::Singleton<Sound>
    {
        SINGLETON(Sound)

    public:

        /// <summary>
        /// �����t�@�C���̓ǂݍ���
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_fileName">�t�@�C����</param>
        /// <param name="_isLoop">���[�v�Đ����邩</param>
        void Load(const std::wstring& _name, const std::wstring& _fileName, bool _isLoop = false);

        /// <summary>
        /// �Đ�
        /// </summary>
        /// <param name="_name">�n���h����</param>
        void Play(const std::wstring& _name);
        /// <summary>
        /// �ꎞ��~
        /// </summary>
        /// <param name="_name">�n���h����</param>
        void Pause(const std::wstring& _name);
        /// <summary>
        /// ��~
        /// </summary>
        /// <param name="_name">�n���h����</param>
        void Stop(const std::wstring& _name);

        /// <summary>
        /// ���[�v�Đ����邩��ݒ�
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_isLoop">���[�v�Đ��������邩</param>
        void IsLoop(const std::wstring& _name, bool _isLoop);
        /// <summary>
        /// ���[�v�Đ����邩���擾
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <returns>���[�v�Đ����邩</returns>
        bool IsLoop(const std::wstring& _name);

        /// <summary>
        /// <para>�{�����[����ݒ�</para>
        /// <para>0.0f�`1.0f</para>
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_volume">�{�����[��</param>
        void Volume(const std::wstring& _name, float _volume);
        /// <summary>
        /// �{�����[�����擾
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <returns>�{�����[��</returns>
        float Volume(const std::wstring& _name);

        /// <summary>
        /// <para>�p����ݒ�</para>
        /// <para>-1.0f�`1.0f</para>
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_pan">�p��</param>
        void Pan(const std::wstring& _name, float _pan);
        /// <summary>
        /// �p�����擾
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <returns>�p��</returns>
        float Pan(const std::wstring& _name);

        /// <summary>
        /// <para>�s�b�`��ݒ�</para>
        /// <para>-1.0f�`1.0f</para>
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <param name="_pitch">�s�b�`</param>
        void Pitch(const std::wstring& _name, float _pitch);
        /// <summary>
        /// �s�b�`���擾
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <returns>�s�b�`</returns>
        float Pitch(const std::wstring& _name);

        /// <summary>
        /// �Đ������̎擾
        /// </summary>
        /// <param name="_name">�n���h����</param>
        /// <returns>�Đ�����</returns>
        bool IsPlaying(const std::wstring& _name);

        /// <summary>
        /// �ǂݍ��񂾃t�@�C����j��
        /// </summary>
        /// <param name="_name">�n���h����</param>
        void Destroy(const std::wstring& _name);

        /// <summary>
        /// �X�V����
        /// </summary>
        void Update();
        /// <summary>
        /// �I������
        /// </summary>
        void OnEnd();

    private:

        struct SoundData
        {
            bool isLoop;
            float volume;
            float pan;
            float pitch;
            std::unique_ptr<DirectX::SoundEffect> file;
            std::unique_ptr<DirectX::SoundEffectInstance> soundFile;
        };

        std::map<std::wstring, SoundData> m_soundDatas = std::map<std::wstring, SoundData>();
    };
} // Audio
} // CreaDXTKLib