//
// �����:      ���c ���V��
// ���e:        �G�̏o������
// �쐬��:      2018/11/27
// �ŏI�X�V��:
//

#include "EnemyManager.h"

#include "Utility/Random.h"

#include "Character/Player.h"
#include "Character/Enemy.h"

using namespace CreaDXTKLib::Utility;

namespace GFF
{
namespace Game
{
    EnemyManager::EnemyManager() :
        m_rand(Random(0, 99))
    {
    }
    void EnemyManager::Update(float _elapsedTime)
    {
        _elapsedTime;

        //�����̒l��0�������Ȃ�
        if (!m_rand.GetInt())
        {
            //�G���X�|�[������
            Spawn();
        }
    }
    void EnemyManager::SetPlayer(Character::Player & _player)
    {
        //�l�̎󂯎��
        m_player = &_player;
    }
    void EnemyManager::Spawn()
    {
        m_enemys.push_back(new Character::Enemy());
    }
}//Game
}//GFF