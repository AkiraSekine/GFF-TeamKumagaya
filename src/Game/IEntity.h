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

        CreaDXTKLib::Math::Collider2D* collider;

    private:

    };
}
}