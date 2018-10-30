//
// 制作者:     関根 明良
// 内容:       敵クラス
// 作成日:     2018/10/26
// 最終更新日:
//

#include "Enemy.h"

namespace GFF
{
namespace Game
{
namespace Character
{
    //Player* Enemy::m_player;

    void Enemy::Update(float _elapsedTime)
    {
        Move(_elapsedTime);
    }

    void Enemy::Move(float _elapsedTime)
    {
        
    }

} // Character
} // Game
} // GFF