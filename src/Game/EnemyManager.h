//
// 制作者:      島田 竜之介
// 内容:        敵の出現処理
// 作成日:      2018/11/27
// 最終更新日:
//

#pragma once

#include <vector>

#include "../Game/Character/Enemy.h"
#include "../Utility/Random.h"

namespace GFF
{
namespace Game
{
    /// <summary>
    /// 敵出現
    /// </summary>
    class EnemyManager
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        EnemyManager();

        /// <summary>
        /// アップデート処理
        /// </summary>
        /// <param name="_elapsTime">前フレームからの経過時間</param>
        void Update(float _elapsedTime);

    private:

        /// <summary>
        /// 敵情報
        /// </summary>
        std::vector<Character::Enemy> m_enemy;

        /// <summary>
        /// ランダム変数
        /// </summary>
        Utility::Random m_rand;

        /// <summary>
        /// 敵の出現
        /// </summary>
        void Spawn();
    };

}//Game
}//GFF