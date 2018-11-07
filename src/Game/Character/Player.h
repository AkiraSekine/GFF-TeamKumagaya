//
// �����:      ���c ���V��
// ���e:        �v���C���[����
// �쐬��:      2018/10/26
// �ŏI�X�V��:  2018/11/5
//

#pragma once

#include "ICharacter.h"

namespace GFF
{
 namespace Game
{
namespace Character
{
    class Player : public ICharacter
    {
        OBJECT2D_PARENT(Player, ICharacter);

    public:

        virtual void Shoot() override;
        virtual void Start() override;
        virtual void Update(float _elapsedTime) override;

    private:

        virtual void Move(float _elapsedTime) override;
    };

} // Character
} // Game
} // GFF