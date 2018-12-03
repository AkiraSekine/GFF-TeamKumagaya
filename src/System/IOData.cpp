//
// �����:     �֍� ����
// ���e:       �f�[�^�̓��o��
// �쐬��:     2018/11/27
// �ŏI�X�V��:
//

#include "IOData.h"

#include <istream>
#include <fstream>
#include "Utility/Debug.h"

#include "Equipment.h"

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
        file.open("./data/GameDatas/EquimentParamater.dat", ios::in | ios::binary);

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
} // System
} // GFF