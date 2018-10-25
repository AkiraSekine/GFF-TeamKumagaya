#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"

#include <map>

template<class T> class CreaDXTKLib::Utility::Singleton;

namespace CreaDXTKLib
{
namespace Input
{
    /// <summary>
    /// �L�[
    /// </summary>
    using Keys = DirectX::Keyboard::Keys;

    /// <summary>
    /// �}�E�X�{�^��
    /// </summary>
    enum struct MouseButtons : char
    {
        Left,
        Middle,
        Right,
        Button1,
        Button2
    };

    /// <summary>
    /// ���͊֌W
    /// </summary>
    class Inputs final : public Utility::Singleton<Inputs>
    {
    public:

        /// <summary>
        /// �`�F�b�N���@
        /// </summary>
        enum struct CheckMode : char
        {
            Down    = 0b0001,    //�������u��
            Up      = 0b0010,    //�������u��
            Press   = 0b0100,    //�����Ă����
            Release = 0b1000     //�b���Ă����
        };

        /// <summary>
        /// ���͐ݒ��ǉ�
        /// </summary>
        /// <param name="_name">���O</param>
        /// <param name="_key">�L�[</param>
        /// <param name="_value">�l</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        void Add(const std::wstring& _name,
            DirectX::Keyboard::Keys _key,
            float _value,
            CheckMode _mode);
        /// <summary>
        /// ���͐ݒ��ǉ�
        /// </summary>
        /// <param name="_name">���O</param>
        /// <param name="_button">�}�E�X�{�^��</param>
        /// <param name="_value">�l</param>
        /// <param name="_mode">�`�F�b�N���@</param>
        void Add(const std::wstring& _name,
            MouseButtons _button,
            float _value,
            CheckMode _mode);

        /// <summary>
        /// ���͂̎擾
        /// </summary>
        /// <param name="_name">���O</param>
        /// <returns>�l</returns>
        float GetValue(const std::wstring& _name);

    private:

        struct InputSet
        {
            bool isKey;

            union
            {
                DirectX::Keyboard::Keys key;
                MouseButtons mouseButton;
            } keyButton;

            float value;
            CheckMode checkMode;
        };

        std::multimap<std::wstring, InputSet> m_inputSets =
            std::multimap<std::wstring, InputSet>();
    };

    /// <summary>
    /// �`�F�b�N���@
    /// </summary>
    using CheckMode = Inputs::CheckMode;

} // Input
} // CreaDXTKLib