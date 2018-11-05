//
// �����:     �֍� ����
// ���e:       �L�����N�^�[�C���^�[�t�F�[�X
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/10/28
//

#pragma once

#include "../IEntity.h"

#include "../../System/Equipment.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    /// <summary>
    /// �L�����N�^�[�C���^�[�t�F�[�X
    /// </summary>
    class ICharacter : public IEntity
    {
        OBJECT2D_PARENT(ICharacter, IEntity)

    public:

        /// <summary>
        /// �̗�
        /// </summary>
        float HP;

        /// <summary>
        /// �e�̔��ˏ���
        /// </summary>
        virtual void Shoot() ABSTRACT;

        /// <summary>
        /// �e�̏����擾
        /// </summary>
        virtual inline System::Gun GetGunData() const final
        {
            return m_gun;
        }

    protected:

        /// <summary>
        /// �e�̏��
        /// </summary>
        System::Gun m_gun;

        /// <summary>
        /// �h���
        /// </summary>
        float m_defence;

        /// <summary>
        /// �ړ�����
        /// </summary>
        virtual void Move(float _elapsedTime) ABSTRACT;
    };
} // Character
} // Game
} // GFF