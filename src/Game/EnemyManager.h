//
// �����:      ���c ���V��
// ���e:        �G�̏o������
// �쐬��:      2018/11/27
// �ŏI�X�V��:
//

#pragma once

#include <vector>

#include "../Utility/Random.h"

namespace GFF
{
namespace Game
{
    namespace Character 
    {
        class Player;
        class Enemy;
    }

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

        /// <summary>
        /// �v���C���[��ݒ�
        /// </summary>
        /// <param name="_player">�v���C���[</param>
        void SetPlayer(Character::Player& _player);

    private:

        /// <summary>
        /// �G���
        /// </summary>
        std::vector<Character::Enemy*> m_enemys;

        /// <summary>
        /// �v���C���[���
        /// </summary>
        Character::Player* m_player;

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