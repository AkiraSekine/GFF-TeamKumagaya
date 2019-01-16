//
// 制作者:     関根 明良
// 内容:       メニューシーン
// 作成日:     2018/12/04
// 最終更新日:
//

#include "MenuScene.h"

#include "Draw/Image.h"
#include "Draw/Text.h"
#include "Utility/Debug.h"
#include "CreaDXTKLib/GameManager.h"

#include "GameScene.h"

using namespace CreaDXTKLib;
using namespace CreaDXTKLib::Math;
using namespace CreaDXTKLib::Draw;

using namespace GFF::UI;

namespace GFF
{
namespace Scene
{
    MenuScene::MenuScene()
    {
        Image::Instance().Load(L"Dot", L"data/images/prototype/Dot.jpg");

        m_doneButton = Button(L"Dot", Vector2(1442, 863), 0.0f, Vector2(256, 128));
        m_backButton = Button(L"Dot", Vector2(1058, 863), 0.0f, Vector2(256, 128));

        m_doneButton.SetString(L"UI", Vector2(-128, -30), L"カイシ");
        m_backButton.SetString(L"UI", Vector2(-128, -30), L"モドル");

        m_doneButton.SetTextColor(DirectX::Colors::Black);
        m_backButton.SetTextColor(DirectX::Colors::Black);

        m_doneButton.SetStateColor(DirectX::Colors::Yellow, Button::State::Select);
        m_doneButton.SetStateColor(DirectX::Colors::Gray, Button::State::Pressed);

        m_backButton.SetStateColor(DirectX::Colors::Yellow, Button::State::Select);
        m_backButton.SetStateColor(DirectX::Colors::Gray, Button::State::Pressed);

        m_doneButton.SetDestinationButton(m_backButton, Button::Direction::Bottom);
        m_doneButton.SetDestinationButton(m_backButton, Button::Direction::Up);
        m_backButton.SetDestinationButton(m_doneButton, Button::Direction::Bottom);
        m_backButton.SetDestinationButton(m_doneButton, Button::Direction::Up);

        m_doneButton.SetSelect();
    }

    MenuScene::~MenuScene()
    {
        Image::Instance().Erase(L"Dot");
    }

    void MenuScene::Update(float _elapsedTime)
    {
        Button::noProcess = false;

        m_doneButton.Update(_elapsedTime);
        m_backButton.Update(_elapsedTime);

        if (m_doneButton.IsDone())
        {
            SceneTransition<GameScene>();
        }
    }

    void MenuScene::OnRender()
    {
        m_doneButton.Draw();
        m_backButton.Draw();
    }
} // Scene
} // GFF