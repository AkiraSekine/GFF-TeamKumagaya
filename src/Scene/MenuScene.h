//
// �����:     �֍� ����
// ���e:       ���j���[�V�[��
// �쐬��:     2018/12/04
// �ŏI�X�V��:
//

#pragma once

#include "CreaDXTKLib/Scene.h"

#include "../UI/Button.h"

namespace GFF
{
namespace Scene
{
    /// <summary>
    /// ���j���[�V�[��
    /// </summary>
    class MenuScene : public CreaDXTKLib::Scene
    {
    public:

        MenuScene();
        virtual ~MenuScene();

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) override;

        /// <summary>
        /// �`�揈��
        /// </summary>
        virtual void OnRender() override;

    private:

        UI::Button m_doneButton;
        UI::Button m_backButton;
    };
} // Scene
} // GFF