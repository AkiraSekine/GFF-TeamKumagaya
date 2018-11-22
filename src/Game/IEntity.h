//
// �����:     �֍� ����
// ���e:       �Q�[�����ɓo�ꂷ��I�u�W�F�N�g�Ɍp��������N���X
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/19
//

#pragma once

#include "CreaDXTKLib/Object.h"

namespace CreaDXTKLib
{
    namespace Math
    {
        class Collider2D;
    }
}

namespace GFF
{
namespace Game
{
    /// <summary>
    /// �Q�[�����ɓo�ꂷ��I�u�W�F�N�g�Ɍp��������N���X
    /// </summary>
    class IEntity : public CreaDXTKLib::Object2D
    {
        OBJECT2D(IEntity)

    public:

        /// <summary>
        /// �R���C�_�[
        /// </summary>
        CreaDXTKLib::Math::Collider2D* collider = nullptr;

        /// <summary>
        /// �^�[�Q�b�g�R���C�_�[�̒ǉ�
        /// </summary>
        /// <param name="_target">�^�[�Q�b�g�R���C�_�[</param>
        virtual void AddColliderTarget(CreaDXTKLib::Math::Collider2D* _target) final;

        /// <summary>
        /// �^�[�Q�b�g�R���C�_�[���폜
        /// </summary>
        /// <param name="_target">�^�[�Q�b�g�R���C�_�[</param>
        virtual void EraseColliderTarget(CreaDXTKLib::Math::Collider2D* _target) final;

    private:

    };
}
}