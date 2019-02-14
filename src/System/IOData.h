//
// 制作者:     関根 明良
// 内容:       データの入出力
// 作成日:     2018/11/27
// 最終更新日: 2019/02/13
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
    /// データの入出力クラス
    /// </summary>
    class IOData : public CreaDXTKLib::Utility::Singleton<IOData>
    {
        SINGLETON(IOData)

    public:

        /// <summary>
        /// 装備データの読み込み
        /// </summary>
        /// <param name="_equipmentDatas">格納変数</param>
        /// <returns>読み込みに成功したか</returns>
        bool EquipmentLoad(EquipmentDatas& _equipmentDatas);

        /// <summary>
        /// 敵の生成情報の読み込み
        /// </summary>
        /// <param name="_spawnDatas">格納変数</param>
        /// <returns>読み込みに成功したか</returns>
        bool SpawnTimeLoad(std::vector<SpawnData>& _spawnDatas);
    };
} // System
} // GFF