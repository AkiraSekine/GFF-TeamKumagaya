//
// 制作者:     関根 明良
// 内容:       敵クラス
// 作成日:     2018/10/26
// 最終更新日: 2018/11/26
//

#include "Enemy.h"

#include "Math/Collider2D.h"

#include "Player.h"

using namespace CreaDXTKLib::Math;

using namespace GFF::System;

namespace GFF
{
namespace Game
{
namespace Character
{
    Player* Enemy::m_player;

    void Enemy::Update(float _elapsedTime)
    {
        Move(_elapsedTime);
    }

    void Enemy::SetPlayer(Player * _player)
    {
        m_player = _player;
    }

    void Enemy::Move(float _elapsedTime)
    {
        Vector2 pos = Position();

        // 左方向へ移動
        pos += -GetRightVector() * gunData.moveSpeed * _elapsedTime;

        Position(pos);
    }

    void Enemy::Start()
    {
        
    }

} // Character
} // Game
} // GFF