//
// �����:     �֍� ����
// ���e:       �f�[�^�̓��o��
// �쐬��:     2018/11/27
// �ŏI�X�V��: 2019/02/13
//

#include "IOData.h"

#include <fstream>

#include "Utility/Debug.h"

#include "SpawnData.h"

using namespace std;
using namespace CreaDXTKLib::Utility;
using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace System
{
    bool IOData::EquipmentLoad(EquipmentDatas& _equipmentDatas)
    {
        ifstream file;
        // �f�[�^�t�@�C�����J��
        file.open("./data/GameDatas/EquipmentParamater.dat", ios::in | ios::binary);

        // �J���Ȃ�������I��
        if (!file)
        {
            Debug::Log(L"can not file open.\n");
            return false;
        }

        // �e�e�f�[�^�̓ǂݍ���
        for (int i = 0; i < NumOfBullets; i++)
        {
            file.read((char*)&_equipmentDatas.bulletData[i].kind, sizeof(Bullet::Kind));
            file.read((char*)&_equipmentDatas.bulletData[i].power, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].recoil, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].moveSpeed, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].distance, sizeof(float));
        }

        // �e�f�[�^�̓ǂݍ���
        for (int i = 0; i < NumOfGuns; i++)
        {
            file.read((char*)&_equipmentDatas.gunData[i].kind, sizeof(Gun::Kind));
            file.read((char*)&_equipmentDatas.gunData[i].moveSpeed, sizeof(float));
            file.read((char*)&_equipmentDatas.gunData[i].fireSpeed, sizeof(int));
            file.read((char*)&_equipmentDatas.gunData[i].reloadTime, sizeof(float));
            file.read((char*)&_equipmentDatas.gunData[i].accuracy, sizeof(float));
            file.read((char*)&_equipmentDatas.gunData[i].isContinuous, sizeof(bool));
            file.read((char*)&_equipmentDatas.gunData[i].magazineSize, sizeof(size_t));
            file.read((char*)&_equipmentDatas.gunData[i].corePos, sizeof(Vector2));
        }

        // �t�@�C�������
        file.close();

        return true;
    }

    bool IOData::SpawnTimeLoad(vector<SpawnData>& _spawnDatas)
    {
        ifstream file;

        // �X�|�[���f�[�^�t�@�C�����J��
        file.open("data/GameDatas/Spawn.dat", ios::in | ios::binary);

        // �J���Ȃ�������I��
        if (!file)
        {
            Debug::Log(L"can not file open.\n");
            return false;
        }

        char breakLine;
        int dataQty;

        // �S�̂̃T�C�Y���擾
        file.read((char*)&dataQty, sizeof(int));
        file.read(&breakLine, sizeof(char));

        // �T�C�Y��ύX
        _spawnDatas.resize(dataQty);

        for (int i = 0; i < dataQty; i++)
        {
            SpawnData* sData = &_spawnDatas.at(i);

            // �O���[�v���̓G�̐����擾
            file.read((char*)&sData->enemyDataQty, sizeof(int));

            // �T�C�Y��ύX
            sData->enemyDatas.resize(sData->enemyDataQty);

            for (int j = 0; j < sData->enemyDataQty; j++)
            {
                EnemyData* eData = &sData->enemyDatas.at(j);

                // �G�̃f�[�^���擾
                file.read((char*)eData, sizeof(EnemyData));
            }

            file.read(&breakLine, sizeof(char));
        }

        // �t�@�C�������
        file.close();

        return true;
    }

} // System
} // GFF