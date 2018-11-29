//
// 制作者:      島田 竜之介
// 内容:        敵の出現処理
// 作成日:      2018/11/27
// 最終更新日:
//

#include "EnemyManager.h"

#include "Character/Player.h"
#include "Character/Enemy.h"

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
        //乱数の値が0だったなら
        if (!m_rand.GetRand<int>())
        {
            //敵をスポーンする
            Spawn();
        }
    }
    void EnemyManager::SetPlayer(Character::Player & _player)
    {
        //値の受け取り
        m_player = &_player;
    }
    void EnemyManager::Spawn()
    {
        m_enemys.push_back(new Character::Enemy());
    }
}//Game
}//GFF