//
// �����:      ���c ���V��
// ���e:        �G�̏o������
// �쐬��:      2018/11/27
// �ŏI�X�V��:
//

#include "EnemyManager.h"

namespace GFF
{
namespace Game
{
    EnemyManager::EnemyManager()
    {
        //�����̎擾
        m_rand = Utility::Random(0, 99);
    }
    void EnemyManager::Update(float _elapsedTime)
    {
        //�����l�������𖞂����Ă����Ȃ�
        if (!m_rand.GetRand<int>())
        {
            //�G���X�|�[������
            Spawn();
        }
    }
    void EnemyManager::Spawn()
    {

    }
}//Game
}//GFF