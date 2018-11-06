#include "GameScene.h"
#include "Draw/Image.h"
#include "Input/Input.h"
#include "../Game/Character/Player.h"

using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Math;

using namespace GFF::Game::Character;

namespace GFF
{
namespace Scene
{
    GameScene::GameScene()
    {
        //Player:  “‡“c—³”V‰î
        //“ü—Íİ’è‚Ì’Ç‰Á
        Inputs::Instance().Add(L"Right", Keys::D, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::A, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::S, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::W, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Down);
            
        Inputs::Instance().Add(L"Right", Keys::Right, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::Left, -1.0f, CheckMode::Press);

        //Player—p‚Ì‰æ‘œ‚Ì“Ç‚İ‚İ
        Image::Instance().Load(L"data/images/prototype/Circle.png", L"Player");

        m_player = Player(L"Player",Vector2(0,0));
    }

    GameScene::~GameScene()
    {
        //Player: “‡“c—³”V‰î
        // “ü—Íİ’è‚Ì”jŠü
        //Inputs::Instance().Erase(L"Right");

        // InputScene‚ªI—¹‚·‚é‚Ì‚Å‰æ‘œ‚ğ”jŠü
        Image::Instance().Erase(L"Player");
    }

    void GFF::Scene::GameScene::Update(float _elapsedTime)
    {
        m_player.Update(_elapsedTime);
    }

    void GFF::Scene::GameScene::OnRender()
    {
        m_player.Draw();
    }
} // Scene
} // GFF
