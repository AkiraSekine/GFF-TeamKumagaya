//
// 制作者:      島田 竜之介
// 内容:        敵の出現処理
// 作成日:      2018/11/27
// 最終更新日:
//

#include "EnemyManager.h"

namespace GFF
{
namespace Game
{
    EnemyManager::EnemyManager()
    {
        //乱数の取得
        m_rand = Utility::Random(0, 99);
    }
    void EnemyManager::Update(float _elapsedTime)
    {
        //乱数値が条件を満たしていたなら
        if (!m_rand.GetRand<int>())
        {
            //敵をスポーンする
            Spawn();
        }
    }
    void EnemyManager::Spawn()
    {

    }
}//Game
}//GFF