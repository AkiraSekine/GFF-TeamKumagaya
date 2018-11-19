//
// �����:      ���c ���V��
// ���e:        �A�C�e������
// �쐬��:      2018/11/7
// �ŏI�X�V��:  2018/11/19
//

#pragma once

#include "IEntity.h"
#include "../System/Equipment.h"

namespace GFF
{
namespace Game
{
    class Item : public IEntity
    {
        OBJECT2D_PARENT(Item, IEntity);

    public:
    
        System::Bullet bullet;

        virtual void Update(float _elapsTime) override;
        void SetBullet(const System::Bullet& _bullet);

    private:
        
        void Move(float _elapsTime);
        virtual void Start() override;
    };

}//Game
}//GFF