//
// �����:      ���c ���V��
// ���e:        �G�̏o������
// �쐬��:      2018/11/27
// �ŏI�X�V��:
//

#pragma once

#include <vector>

#include "../Game/Character/Enemy.h"
#include "../Utility/Random.h"

namespace GFF
{
namespace Game
{
    /// <summary>
    /// �G�o��
    /// </summary>
    class EnemyManager
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        EnemyManager();

        /// <summary>
        /// �A�b�v�f�[�g����
        /// </summary>
        /// <param name="_elapsTime">�O�t���[������̌o�ߎ���</param>
        void Update(float _elapsedTime);

    private:

        /// <summary>
        /// �G���
        /// </summary>
        std::vector<Character::Enemy> m_enemy;

        /// <summary>
        /// �����_���ϐ�
        /// </summary>
        Utility::Random m_rand;

        /// <summary>
        /// �G�̏o��
        /// </summary>
        void Spawn();
    };

}//Game
}//GFF