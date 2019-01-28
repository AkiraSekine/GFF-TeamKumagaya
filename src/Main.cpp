//
// 制作者:     関根 明良
// 内容:       エントリポイント
// 作成日:     2018/10/23
// 最終更新日: 2019/01/16
//

#include "CreaDXTKLib/CreaDXTKLib.h"
#include "CreaDXTKLib/GameManager.h"
#include "Input/Input.h"
#include "Draw/Text.h"
#include "Utility/Window.h"

#include "Scene/MenuScene.h"

CREA_DXTKLIB

using namespace CreaDXTKLib;
using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Utility;

using namespace GFF::Scene;

void SetUp()
{
    // ウィンドウの設定
    Window::Instance().SetStyle(WS_EX_CLIENTEDGE);
    Window::Instance().SetSize(1920, 1080);
    Window::Instance().SetPosition(Math::Vector2::zero);
    Window::Instance().backGroundColor = DirectX::Colors::Black;

    // 入力の設定
    Inputs::Instance().Add(L"Vertical", Keys::W, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Vertical", Keys::S, -1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Horizontal", Keys::D, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Horizontal", Keys::A, -1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Done", Keys::Enter, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"DoneMouse", MouseButtons::Left, 1.0f, CheckMode::Press);
    Inputs::Instance().Add(L"DoneMouse", MouseButtons::Left, -1.0f, CheckMode::Up);

    // フォントファイルの読み込み
    Text::Instance().Load(L"UI", L"Data/Fonts/Giraffe.spritefont");

    // 最初のシーンを設定
    SetStartScene<MenuScene>();
}