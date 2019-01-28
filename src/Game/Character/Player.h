//
// �����:      ���c ���V��
// ���e:        �v���C���[����
// �쐬��:      2018/10/26
// �ŏI�X�V��:  2018/11/7
//

#pragma once

#include "ICharacter.h"

#include <vector>

#include "../../System/Equipment.h"

namespace GFF
{
 namespace Game
{
     class BulletObject;

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
        /// �e�f�[�^
        /// </summary>
        static GFF::System::Gun gun;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// Update�̌�Ɏ��s�����X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void LateUpdate(float _elapsedTime) override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        void Draw();

    private:

        /// <summary>
        /// �e�e�z��
        /// </summary>
        std::vector<BulletObject*> m_bullets;

        /// <summary>
        /// �A�ˊԊu�̌v��
        /// </summary>
        float m_shotTime = 0;

        /// <summary>
        /// ���ˏ���
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Shoot(float _elapsedTime) override;

        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Move(float _elapsedTime) override;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;

        /// <summary>
        /// �I������
        /// </summary>
        virtual void OnDestroy() override;
    };

} // Character
} // Game
} // GFF