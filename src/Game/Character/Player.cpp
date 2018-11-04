//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/10/26
// 最終更新日:  2018/11/4
//

#include "Player.h"
#include "Input/Input.h"
#include "Math/Vector2.h"
#include "Utility/Debug.h"

using namespace CreaDXTKLib::Input;
using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
namespace Character
{

    void Player::Move(float _elapsedTime)
    {
        _elapsedTime;
        float a = Inputs::Instance().GetValue(L"MoveRight");


        CreaDXTKLib::Utility::Debug::Log(L"%f\n", a);

        Position(Position() + Vector2(a, 0));

    }

    void Player::Shoot()
    {
    }

    void Player::Start()
    {
    }

    void Player::Update(float _elapsedTime)
    {
        Move(_elapsedTime);
    }

    void Player::End()
    {
    }

} // Character
} // Game
} // GFF
