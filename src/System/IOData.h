//
// �����:     �֍� ����
// ���e:       �f�[�^�̓��o��
// �쐬��:     2018/11/27
// �ŏI�X�V��:
//

#pragma once

#include "Utility/Singleton.h"

namespace GFF
{
namespace System
{
    struct EquipmentDatas;

    /// <summary>
    /// �f�[�^�̓��o�̓N���X
    /// </summary>
    class IOData : public CreaDXTKLib::Utility::Singleton<IOData>
    {
        SINGLETON(IOData)

    public:

        /// <summary>
        /// �����f�[�^�̓ǂݍ���
        /// </summary>
        /// <param name="_equipmentDatas">�i�[�ϐ�</param>
        /// <returns>�ǂݍ��݂ɐ���������</returns>
        bool EquipmentLoad(EquipmentDatas& _equipmentDatas);
    };
} // System
} // GFF