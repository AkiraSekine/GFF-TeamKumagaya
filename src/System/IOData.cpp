//
// 制作者:     関根 明良
// 内容:       データの入出力
// 作成日:     2018/11/27
// 最終更新日: 2019/02/13
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
        // データファイルを開く
        file.open("./data/GameDatas/EquipmentParamater.dat", ios::in | ios::binary);

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

    bool IOData::SpawnTimeLoad(vector<SpawnData>& _spawnDatas)
    {
        ifstream file;

        // スポーンデータファイルを開く
        file.open("data/GameDatas/Spawn.dat", ios::in | ios::binary);

        // 開けなかったら終了
        if (!file)
        {
            Debug::Log(L"can not file open.\n");
            return false;
        }

        char breakLine;
        int dataQty;

        // 全体のサイズを取得
        file.read((char*)&dataQty, sizeof(int));
        file.read(&breakLine, sizeof(char));

        // サイズを変更
        _spawnDatas.resize(dataQty);

        for (int i = 0; i < dataQty; i++)
        {
            SpawnData* sData = &_spawnDatas.at(i);

            // グループ内の敵の数を取得
            file.read((char*)&sData->enemyDataQty, sizeof(int));

            // サイズを変更
            sData->enemyDatas.resize(sData->enemyDataQty);

            for (int j = 0; j < sData->enemyDataQty; j++)
            {
                EnemyData* eData = &sData->enemyDatas.at(j);

                // 敵のデータを取得
                file.read((char*)eData, sizeof(EnemyData));
            }

            file.read(&breakLine, sizeof(char));
        }

        // ファイルを閉じる
        file.close();

        return true;
    }

} // System
} // GFF