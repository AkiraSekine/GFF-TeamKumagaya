//
// �����:     �֍� ����
// ���e:       �Q�[���V�[��
// �쐬��:     2018/10/26
// �ŏI�X�V��:
//

#pragma once

#include "CreaDXTKLib/Scene.h"

namespace GFF
{
namespace Scene
{
    /// <summary>
    /// �Q�[���V�[��
    /// </summary>
    class GameScene : public CreaDXTKLib::Scene
    {
    public:

        virtual void Update(float _elapsedTime) override;
        virtual void OnRender() override;

    private:

    };
} // Scene
} // GFF