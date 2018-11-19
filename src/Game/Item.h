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
        /// <summary>
        /// �A�b�v�f�[�g����
        /// </summary>
        virtual void Update(float _elapsTime) override;
        /// <summary>
        /// Bullet�̃Z�b�g
        /// </summary>
        void SetBullet(const System::Bullet& _bullet);

    private:
        
        /// <summary>
        /// �ړ�����
        /// </summary>
        void Move(float _elapsTime);
        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;
    };

}//Game
}//GFF