//
// �����:     �֍� ����
// ���e:       �Q�[���V�[��
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/27
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
        //Player:  ���c���V��
        //���͐ݒ�̒ǉ�
        Inputs::Instance().Add(L"Right", Keys::D, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::A, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::S, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::W, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Down);

        //Player�p�̉摜�̓ǂݍ���
        Image::Instance().Load(L"Player", L"data/images/prototype/Circle.png");

        //�C���X�^���X�̐���
        m_player = Player(L"Player",Vector2(0,0));

        // �����̃p�����[�^��ǂݍ���
        if (!IOData::Instance().EquipmentLoad(m_equipmentDatas))
        {
            // �ǂݍ��݂Ɏ��s������Q�[�����I������
            ExitGame();
        }
    }

    GameScene::~GameScene()
    {
        //Player: ���c���V��
        // ���͐ݒ�̔j��
        Inputs::Instance().Erase(L"Right");
        Inputs::Instance().Erase(L"Up");
        Inputs::Instance().Erase(L"Shot");

        // InputScene���I������̂ŉ摜��j��
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
