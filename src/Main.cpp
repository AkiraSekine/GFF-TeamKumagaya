//
// 制作者:     関根 明良
// 内容:       エントリポイント
// 作成日:     2018/10/23
// 最終更新日: 2018/11/29
//

#include "CreaDXTKLib/CreaDXTKLib.h"
#include "CreaDXTKLib/GameManager.h"
#include "Input/Input.h"

#include "Scene/GameScene.h"

CREA_DXTKLIB

using namespace CreaDXTKLib;
using namespace CreaDXTKLib::Input;

using namespace GFF::Scene;

void SetUp()
{
    SetStartScene<GameScene>();

    Inputs::Instance().Add(L"Vertical", Keys::W, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Vertical", Keys::S, -1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Horizontal", Keys::D, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Horizontal", Keys::A, -1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"Done", Keys::Enter, 1.0f, CheckMode::Down);
    Inputs::Instance().Add(L"DoneMouse", MouseButtons::Left, 1.0f, CheckMode::Press);
    Inputs::Instance().Add(L"DoneMouse", MouseButtons::Left, -1.0f, CheckMode::Release);
}