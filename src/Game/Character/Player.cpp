//
// �����:      ���c ���V��
// ���e:        �v���C���[����
// �쐬��:      2018/10/26
// �ŏI�X�V��:  2018/11/4
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
        // ���͂��擾
        float inputRight = Inputs::Instance().GetValue(L"Right");
        float inputUp = Inputs::Instance().GetValue(L"Up");
        bool shot = (bool)Inputs::Instance().GetValue(L"Shot");

        //A��������Ă����獶�ցAD��������Ă�����E�։摜���ړ�
        Vector2 pos = Position();
        pos += Vector2(100.0f, 0.0f) * _elapsedTime * inputRight;
        pos += Vector2(0.0f, 100.0f) * _elapsedTime * inputUp;
        
        //SPACE�L�[�������ꂽ�Ȃ�
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
