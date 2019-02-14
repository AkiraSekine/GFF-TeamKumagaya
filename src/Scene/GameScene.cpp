//
// §ìŽÒ:     ŠÖª –¾—Ç
// “à—e:       ƒQ[ƒ€ƒV[ƒ“
// ì¬“ú:     2018/10/26
// ÅIXV“ú: 2019/02/13
//

#include "GameScene.h"

#include "Draw/Image.h"
#include "Input/Input.h"
#include "CreaDXTKLib/CreaDXTKLib.h"

#include "../System/IOData.h"
#include "../Game/Character/Player.h"

using namespace CreaDXTKLib;
using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Draw;
using namespace CreaDXTKLib::Math;

using namespace GFF::Game::Character;
using namespace GFF::System;

namespace GFF
{
namespace Scene
{
    GameScene::GameScene()
    {
        //Player:  “‡“c—³”V‰î
        //“ü—ÍÝ’è‚Ì’Ç‰Á
        Inputs::Instance().Add(L"Right", Keys::D, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::A, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::S, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::W, -1.0f, CheckMode::Press);

        // ‘•”õ‚Ìƒpƒ‰ƒ[ƒ^‚ð“Ç‚Ýž‚Þ
        if (!IOData::Instance().EquipmentLoad(m_equipmentDatas))
        {
            // “Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚½‚çƒQ[ƒ€‚ðI—¹‚·‚é
            ExitGame();
        }

        // “G‚Ì¶¬î•ñ‚ð“Ç‚Ýž‚Þ
        if (!IOData::Instance().SpawnTimeLoad(m_spawnDatas))
        {
            // “Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚½‚çƒQ[ƒ€‚ðI—¹‚·‚é
            ExitGame();
        }

        // (‰¼)e‚Æ’e‚ðÝ’è
        Player::gun = m_equipmentDatas.gunData[(int)Gun::Kind::HG];
        Player::gun.bullet = m_equipmentDatas.bulletData[(int)Bullet::Kind::mm9];

        // ”­ŽË“ü—Í‚ÌÝ’è
        // ƒvƒŒƒCƒ„[‚Ìe‚ª˜AŽË‰Â”\‚È‚ç‰Ÿ‚µ‚Ä‚éŠÔA•s‰Â”\‚È‚ç‰Ÿ‚µ‚½uŠÔ‚ðÝ’è
        if (Player::gun.isContinuous)
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Press);
        }
        else
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Down);
        }

        // ‰æ‘œ‚Ì“Ç‚Ýž‚Ý
        Image::Instance().Load(L"Player", L"data/images/prototype/Circle.png");
        Image::Instance().Load(L"Dot", L"data/images/prototype/Dot.jpg");

        //ƒCƒ“ƒXƒ^ƒ“ƒX‚Ì¶¬
        m_player = new Player(L"Player",Vector2(0,0));
    }

    GameScene::~GameScene()
    {
        //Player: “‡“c—³”V‰î
        // “ü—ÍÝ’è‚Ì”jŠü
        Inputs::Instance().Erase(L"Right");
        Inputs::Instance().Erase(L"Up");
        Inputs::Instance().Erase(L"Shot");

        // InputScene‚ªI—¹‚·‚é‚Ì‚Å‰æ‘œ‚ð”jŠü
        Image::Instance().Erase(L"Player");
        Image::Instance().Erase(L"Dot");

        for (Enemy* enemy : m_enemys)
        {
            enemy->Destroy();
        }

        delete m_player;
    }

    void GFF::Scene::GameScene::Update(float _elapsedTime)
    {

    }

    void GFF::Scene::GameScene::OnRender()
    {
        m_player->Draw();
    }
} // Scene
} // GFF
