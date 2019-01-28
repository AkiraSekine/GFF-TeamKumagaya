//
// �����:     �֍� ����
// ���e:       �e�I�u�W�F�N�g
// �쐬��:     2018/11/09
// �ŏI�X�V��: 2018/11/19
//

#pragma once

#include "IEntity.h"
#include "../System/Equipment.h"

namespace GFF
{
namespace Game
{
    /// <summary>
    /// �e�e�I�u�W�F�N�g
    /// </summary>
    class BulletObject : public IEntity
    {
        OBJECT2D_PARENT(BulletObject, IEntity);

    public:

        /// <summary>
        /// �e�e�f�[�^
        /// </summary>
        System::Bullet bullet;

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// �e�e�f�[�^�̐ݒ�
        /// </summary>
        /// <param name="_bullet">�e�e�f�[�^</param>
        void SetBullet(const System::Bullet& _bullet);

        /// <summary>
        /// �`�揈��
        /// </summary>
        /// <param name="_color">���Z�F</param>
        void Draw(const DirectX::XMVECTORF32& _color = DirectX::Colors::White);

    private:

        /// <summary>
        /// �O�t���[���̍��W
        /// </summary>
        CreaDXTKLib::Math::Vector2 m_beforePos;

        /// <summary>
        /// �����ʒu
        /// </summary>
        CreaDXTKLib::Math::Vector2 m_startPos;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() override;
        /// <summary>
        /// �ړ�����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        void Move(float _elapsedTime);
    };
} // Game
} // GFF