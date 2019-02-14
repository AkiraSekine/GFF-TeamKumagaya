//
// �����:     �֍� ����
// ���e:       �f�[�^�̓��o��
// �쐬��:     2018/11/27
// �ŏI�X�V��: 2019/02/13
//

#pragma once

#include "Utility/Singleton.h"

#include <vector>

namespace GFF
{
namespace System
{
    struct EquipmentDatas;

    struct SpawnData;

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

        /// <summary>
        /// �G�̐������̓ǂݍ���
        /// </summary>
        /// <param name="_spawnDatas">�i�[�ϐ�</param>
        /// <returns>�ǂݍ��݂ɐ���������</returns>
        bool SpawnTimeLoad(std::vector<SpawnData>& _spawnDatas);
    };
} // System
} // GFF