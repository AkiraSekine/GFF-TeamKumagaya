#pragma once

#include "Singleton.h"
#include "../Math/Vector2.h"

#include <Windows.h>

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// �E�B���h�E�֌W
    /// </summary>
    class Window final : public Singleton<Window>
    {
        SINGLETON(Window)

    public:

        /// <summary>
        /// �w�i�F
        /// </summary>
        DirectX::XMVECTORF32 backGroundColor = DirectX::Colors::CornflowerBlue;

        /// <summary>
        /// �E�B���h�E�n���h����ݒ�
        /// </summary>
        /// <param name="_windowHandle">�E�B���h�E�n���h��</param>
        void SetWindowHandle(HWND _windowHandle);

        /// <summary>
        /// �E�B���h�E�T�C�Y���擾
        /// </summary>
        /// <returns>�E�B���h�E�T�C�Y</returns>
        Math::Vector2 GetSize();
        /// <summary>
        /// �E�B���h�E�T�C�Y��ݒ�
        /// </summary>
        /// <param name="_width">��</param>
        /// <param name="_height">����</param>
        void SetSize(int _width, int _height);

        /// <summary>
        /// �E�B���h�E�̈ʒu��ݒ�
        /// </summary>
        /// <param name="_position">�ʒu</param>
        void SetPosition(Math::Vector2& _position);

        /// <summary>
        /// �E�B���h�E����ݒ�
        /// </summary>
        /// <param name="_text">�E�B���h�E��</param>
        void SetText(const std::wstring& _text);

        /// <summary>
        /// �E�B���h�E�X�^�C����ݒ�
        /// </summary>
        /// <param name="_style">
        /// <para>�X�^�C�����</para>
        /// <para>https://msdn.microsoft.com/ja-jp/library/cc410714.aspx</para>
        /// <para>��dwExStyle�̍��ڂ��Q��</para>
        /// </param>
        void SetStyle(long _style);

    private:

        HWND m_windowHandle;
        RECT m_windowRect;

    };
} // Utility
} // CreaDXTKLib