//
// �����:     �֍� ����
// ���e:       �Q�[���V�[��
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/27
//

#pragma once

#include "CreaDXTKLib/Scene.h"
#include "../Game/Character/Player.h"

#include "../System/Equipment.h"

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

        GameScene();
        virtual ~GameScene();

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

        /// <summary>
        /// �v���C���[
        /// </summary>
        GFF::Game::Character::Player m_player;
        /// <summary>
        /// �����̃p�����[�^
        /// </summary>
        GFF::System::EquipmentDatas m_equipmentDatas;
    };
} // Scene
} // GFF