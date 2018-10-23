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
/// ゲームの設定
/// </summary>
extern void SetUp();

namespace CreaDXTKLib
{
    /// <summary>
    /// 描画関係
    /// </summary>
    namespace Draw { }

    /// <summary>
    /// 入力関係
    /// </summary>
    namespace Input { }

    /// <summary>
    /// 汎用的なクラス
    /// </summary>
    namespace Utility { }

    /// <summary>
    /// 数学関係
    /// </summary>
    namespace Math { }

    /// <summary>
    /// 終了させる
    /// </summary>
    extern void ExitGame();
}