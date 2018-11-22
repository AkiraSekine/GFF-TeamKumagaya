//
// �����:     �֍� ����
// ���e:       �Q�[�����ɓo�ꂷ��I�u�W�F�N�g�Ɍp��������N���X
// �쐬��:     2018/11/21
// �ŏI�X�V��:
//

#include "IEntity.h"

#include "Math/Collider2D.h"

using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
    void IEntity::AddColliderTarget(Collider2D * _target)
    {
        collider->AddTarget(_target);
    }

    void IEntity::EraseColliderTarget(CreaDXTKLib::Math::Collider2D * _target)
    {
        collider->EraseTarget(_target);
    }
} // Game
} // GFF