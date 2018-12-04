//
// 制作者:     関根 明良
// 内容:       ゲームシーン
// 作成日:     2018/10/26
// 最終更新日: 2018/11/27
//

#include "GameScene.h"

#include "Draw/Image.h"
#include "Input/Input.h"
#include "CreaDXTKLib/CreaDXTKLib.h"

#include "../System/IOData.h"

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
        //Player:  島田竜之介
        //入力設定の追加
        Inputs::Instance().Add(L"Right", Keys::D, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::A, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::S, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::W, -1.0f, CheckMode::Press);

        // 装備のパラメータを読み込む
        if (!IOData::Instance().EquipmentLoad(m_equipmentDatas))
        {
            // 読み込みに失敗したらゲームを終了する
            ExitGame();
        }

        // (仮)銃と弾を設定
        Player::gun = m_equipmentDatas.gunData[(int)Gun::Kind::HG];
        Player::gun.bullet = m_equipmentDatas.bulletData[(int)Bullet::Kind::mm9];

        // 発射入力の設定
        // プレイヤーの銃が連射可能なら押してる間、不可能なら押した瞬間を設定
        if (Player::gun.isContinuous)
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Press);
        }
        else
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Down);
        }

        // 画像の読み込み
        Image::Instance().Load(L"Player", L"data/images/prototype/Circle.png");
        Image::Instance().Load(L"Dot", L"data/images/prototype/Dot.jpg");

        //インスタンスの生成
        m_player = Player(L"Player",Vector2(0,0));
    }

    GameScene::~GameScene()
    {
        //Player: 島田竜之介
        // 入力設定の破棄
        Inputs::Instance().Erase(L"Right");
        Inputs::Instance().Erase(L"Up");
        Inputs::Instance().Erase(L"Shot");

        // InputSceneが終了するので画像を破棄
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
