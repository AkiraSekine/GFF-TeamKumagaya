//
// �����:      ���c ���V��
// ���e:        �A�C�e������
// �쐬��:      2018/11/7
// �ŏI�X�V��:  2018/11/19
//

#include "Item.h"
#include "Math/Vector2.h"

using namespace CreaDXTKLib::Math;

namespace GFF
{
namespace Game
{
    void Item::Update(float _elapsTime)
    {
        Move(_elapsTime);
    }

    void Item::SetBullet(const System::Bullet & _bullet)
    {
        //�l�̎󂯎��
        bullet = _bullet;
    }

    void Item::Move(float _elapsTime)
    {
        //��`
        const float speed = 100;
        Vector2 pos = Position();

        //�ړ�����(��ʍ�����)
        pos.x -= speed * _elapsTime;

        //�ύX�̓K�p
        Position(pos);
    }
}//Game
}//GFF