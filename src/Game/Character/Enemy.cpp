//
// �����:     �֍� ����
// ���e:       �G�N���X
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/26
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

        // �������ֈړ�
        pos += -GetRightVector() * gunData.moveSpeed * _elapsedTime;

        Position(pos);
    }

    void Enemy::Start()
    {
        
    }

} // Character
} // Game
} // GFF