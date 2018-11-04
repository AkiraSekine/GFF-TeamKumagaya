//
// 制作者:      島田 竜之介
// 内容:        プレイヤー処理
// 作成日:      2018/10/26
// 最終更新日:  2018/11/4
//

#pragma once

#include "CreaDXTKLib/Object.h"
#include "ICharacter.h"

namespace GFF
{
 namespace Game
{
namespace Character
{
    class Player : public ICharacter, public CreaDXTKLib::Object2D
    {
        OBJECT2D_PARENT(Player, ICharacter);

    public:

        virtual void Move(float _elapsedTime) override;
        virtual void Shoot() override;
        virtual void Start() override;
        virtual void Update(float _elapsedTime) override;
        virtual void End() override;

    };

} // Character
} // Game
} // GFF