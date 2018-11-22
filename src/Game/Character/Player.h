//
// �����:      ���c ���V��
// ���e:        �v���C���[����
// �쐬��:      2018/10/26
// �ŏI�X�V��:  2018/11/7
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
    /// �v���C���[�N���X
    /// </summary>
    class Player : public ICharacter
    {
        OBJECT2D_PARENT(Player, ICharacter);

    public:

        /// <summary>
        /// ���ˏ���
        /// </summary>
        virtual void Shoot() override;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

    private:

        /// <summary>
        /// 
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;
    };

} // Character
} // Game
} // GFF