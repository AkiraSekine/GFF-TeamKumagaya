#pragma once

#include "../Default/pch.h"

#ifndef ABSTRACT
#define ABSTRACT = 0
#endif // !ABSTRACT

#if defined(_DEBUG) && defined(_MSVC_LANG)

#pragma comment(lib, "CreaDXTKLib_d.lib")
#pragma comment(lib, "Draw_d.lib")
#pragma comment(lib, "Input_d.lib")
#pragma comment(lib, "Math_d.lib")
#pragma comment(lib, "Utility_d.lib")

#elif defined(_MSVC_LANG)

#pragma comment(lib, "CreaDXTKLib.lib")
#pragma comment(lib, "Draw.lib")
#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Math.lib")
#pragma comment(lib, "Utility.lib")

#endif

extern "C"
{
    int Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
}

#define CREADXTKLIB \
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)\
{ Main(hInstance, hPrevInstance, lpCmdLine, nCmdShow); }

/// <summary>
/// �Q�[���̐ݒ�
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// �`��֌W
    /// </summary>
    namespace Draw { }

    /// <summary>
    /// ���͊֌W
    /// </summary>
    namespace Input { }

    /// <summary>
    /// �ėp�I�ȃN���X
    /// </summary>
    namespace Utility { }

    /// <summary>
    /// ���w�֌W
    /// </summary>
    namespace Math { }

    /// <summary>
    /// �I��������
    /// </summary>
    extern void ExitGame();
}