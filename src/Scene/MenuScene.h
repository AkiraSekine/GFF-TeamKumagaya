//
// �����:     �֍� ����
// ���e:       ���j���[�V�[��
// �쐬��:     2018/12/04
// �ŏI�X�V��: 2019/01/16
//

#pragma once

#include "CreaDXTKLib/Scene.h"

namespace GFF
{
    namespace UI
    {
        class Button;
    }

namespace Scene
{
    /// <summary>
    /// ���j���[�V�[��
    /// </summary>
    class MenuScene : public CreaDXTKLib::Scene
    {
    public:

        MenuScene();
        virtual ~MenuScene() override;

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

        UI::Button* m_doneButton;
        UI::Button* m_backButton;
    };
} // Scene
} // GFF