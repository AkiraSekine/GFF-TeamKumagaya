//
// 制作者:     関根 明良
// 内容:       データの入出力
// 作成日:     2018/11/27
// 最終更新日:
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
        // データファイルを開く
        file.open("./data/GameDatas/EquimentParamater.dat", ios::in | ios::binary);

        // 開けなかったら終了
        if (!file)
        {
            Debug::Log(L"can not file open.\n");
            return false;
        }

        // 銃弾データの読み込み
        for (int i = 0; i < NumOfBullets; i++)
        {
            file.read((char*)&_equipmentDatas.bulletData[i].kind, sizeof(Bullet::Kind));
            file.read((char*)&_equipmentDatas.bulletData[i].power, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].recoil, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].moveSpeed, sizeof(float));
            file.read((char*)&_equipmentDatas.bulletData[i].distance, sizeof(float));
        }

        // 銃データの読み込み
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

        // ファイルを閉じる
        file.close();

        return true;
    }
} // System
} // GFF