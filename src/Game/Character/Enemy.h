//
// �����:     �֍� ����
// ���e:       �G�N���X
// �쐬��:     2018/10/26
// �ŏI�X�V��:
//

#pragma once

#include "ICharacter.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    /// <summary>
    /// �G�N���X
    /// </summary>
    class Enemy : public ICharacter
    {
        OBJECT2D_PARENT(Enemy, ICharacter)

    public:

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

    protected:

        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Move(float _elapsedTime) override;

    private:

        /// <summary>
        /// �v���C���[���
        /// </summary>
        //static Player* m_player;
    };
} // Character
} // Game
} // GFF