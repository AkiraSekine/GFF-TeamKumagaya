//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/10/26
// 最終更新日:  2018/11/4
//

#include "Player.h"
#include "Input/Input.h"
#include "Math/Vector2.h"

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
        // 入力を取得
        float inputRight = Inputs::Instance().GetValue(L"Right");
        float inputUp = Inputs::Instance().GetValue(L"Up");
        bool shot = (bool)Inputs::Instance().GetValue(L"Shot");

        //Aが押されていたら左へ、Dが押されていたら右へ画像を移動
        Vector2 pos = Position();
        pos += Vector2(100.0f, 0.0f) * _elapsedTime * inputRight;
        pos += Vector2(0.0f, 100.0f) * _elapsedTime * inputUp;
        
        //SPACEキーが押されたなら
        if (shot)
        {
            Shoot();
        }

        Position(pos);
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


} // Character
} // Game
} // GFF
