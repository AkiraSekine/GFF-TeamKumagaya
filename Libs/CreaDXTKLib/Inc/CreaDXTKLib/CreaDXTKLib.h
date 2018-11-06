#pragma once

#include "../DirectXTK/pch.h"

#ifndef ABSTRACT

/// <summary>
/// �������z�֐��ɂ���
/// </summary>
#define ABSTRACT = 0

#endif // !ABSTRACT

#if defined(_DEBUG) && defined(_MSVC_LANG)

//#pragma comment(lib, "CreaDXTKLib_d.lib")
#pragma comment(lib, "Draw_d.lib")
#pragma comment(lib, "Input_d.lib")
#pragma comment(lib, "Math_d.lib")
#pragma comment(lib, "Utility_d.lib")
#pragma comment(lib, "Audio_d.lib")

#elif defined(_MSVC_LANG)

//#pragma comment(lib, "CreaDXTKLib.lib")
#pragma comment(lib, "Draw.lib")
#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Math.lib")
#pragma comment(lib, "Utility.lib")
#pragma comment(lib, "Audio.lib")

#endif

extern "C"
{
    int Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
}

#ifndef CREA_DXTKLIB

#define CREA_DXTKLIB \
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)\
{ Main(hInstance, hPrevInstance, lpCmdLine, nCmdShow); }

#endif // !CREA_DXTKLIB

/// <summary>
/// �Q�[���̐ݒ�
/// </summary>
extern void SetUp();

/// <summary>
/// �Q�[���I�����ɌĂ΂��֐��|�C���^
/// </summary>
extern void(*EndFunction)();

/// <summary>
/// �E�B���h�E���A�N�e�B�u��ԂɂȂ������ɌĂ΂��֐��|�C���^
/// </summary>
extern void(*OnActive)();

/// <summary>
/// �E�B���h�E����A�N�e�B�u��ԂɂȂ������ɌĂ΂��֐��|�C���^
/// </summary>
extern void(*OnInactive)();

/// <summary>
/// �E�B���h�E���ŏ������ꂽ���ɌĂ΂��֐��|�C���^
/// </summary>
extern void(*OnMinimize)();

/// <summary>
/// �E�B���h�E���ŏ�������߂������ɌĂ΂��֐��|�C���^
/// </summary>
extern void(*OnReturnMinimize)();

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
    /// �T�E���h�֌W
    /// </summary>
    namespace Audio { }

    /// <summary>
    /// �I��������
    /// </summary>
    extern void ExitGame();
}