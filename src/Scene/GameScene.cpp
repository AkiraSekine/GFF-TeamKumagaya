//
// �����:     �֍� ����
// ���e:       �Q�[���V�[��
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2019/02/13
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
        //Player:  ���c���V��
        //���͐ݒ�̒ǉ�
        Inputs::Instance().Add(L"Right", Keys::D, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Right", Keys::A, -1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::S, 1.0f, CheckMode::Press);
        Inputs::Instance().Add(L"Up", Keys::W, -1.0f, CheckMode::Press);

        // �����̃p�����[�^��ǂݍ���
        if (!IOData::Instance().EquipmentLoad(m_equipmentDatas))
        {
            // �ǂݍ��݂Ɏ��s������Q�[�����I������
            ExitGame();
        }

        // �G�̐�������ǂݍ���
        if (!IOData::Instance().SpawnTimeLoad(m_spawnDatas))
        {
            // �ǂݍ��݂Ɏ��s������Q�[�����I������
            ExitGame();
        }

        // (��)�e�ƒe��ݒ�
        Player::gun = m_equipmentDatas.gunData[(int)Gun::Kind::HG];
        Player::gun.bullet = m_equipmentDatas.bulletData[(int)Bullet::Kind::mm9];

        // ���˓��͂̐ݒ�
        // �v���C���[�̏e���A�ˉ\�Ȃ牟���Ă�ԁA�s�\�Ȃ牟�����u�Ԃ�ݒ�
        if (Player::gun.isContinuous)
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Press);
        }
        else
        {
            Inputs::Instance().Add(L"Shot", Keys::Space, 1.0f, CheckMode::Down);
        }

        // �摜�̓ǂݍ���
        Image::Instance().Load(L"Player", L"data/images/prototype/Circle.png");
        Image::Instance().Load(L"Dot", L"data/images/prototype/Dot.jpg");

        //�C���X�^���X�̐���
        m_player = new Player(L"Player",Vector2(0,0));
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
