//
// �����:     �֍� ����
// ���e:       �L�����N�^�[�C���^�[�t�F�[�X
// �쐬��:     2018/10/26
// �ŏI�X�V��:
//

#pragma once

#include "CreaDXTKLib/Object.h"
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
    public:

        /// <summary>
        /// �̗�
        /// </summary>
        float HP;

        virtual ~ICharacter() { }

        /// <summary>
        /// �ړ�����
        /// </summary>
        virtual void Move(float _elapsedTime) ABSTRACT;

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

    };
} // Character
} // Game
} // GFF