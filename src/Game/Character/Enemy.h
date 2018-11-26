//
// �����:     �֍� ����
// ���e:       �G�N���X
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/23
//

#pragma once

#include "ICharacter.h"

#include "../../System/Equipment.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    class Player;

    /// <summary>
    /// �G�N���X
    /// </summary>
    class Enemy : public ICharacter
    {
        OBJECT2D_PARENT(Enemy, ICharacter)

    public:

        /// <summary>
        /// �e���
        /// </summary>
        System::Gun gunData;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// �v���C���[��ݒ�
        /// </summary>
        /// <param name="_player">�v���C���[</param>
        static void SetPlayer(Player* _player);

    protected:

        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;

    private:

        /// <summary>
        /// �v���C���[���
        /// </summary>
        static Player* m_player;
    };
} // Character
} // Game
} // GFF