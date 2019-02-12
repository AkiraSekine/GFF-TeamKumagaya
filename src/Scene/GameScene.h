//
// �����:     �֍� ����
// ���e:       �Q�[���V�[��
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/27
//

#pragma once

#include "CreaDXTKLib/Scene.h"

#include "../System/Equipment.h"

#include "../Game/Character/Enemy.h"

namespace CreaDXTKLib
{
    class Scene;
}

namespace GFF
{
    namespace Game
    {
        namespace Character
        {
            class Player;
        }
    }

namespace Scene
{
    /// <summary>
    /// �Q�[���V�[��
    /// </summary>
    class GameScene : public CreaDXTKLib::Scene
    {
    public:

        GameScene();
        virtual ~GameScene() override;

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
        GFF::Game::Character::Player* m_player;

        /// <summary>
        /// �G
        /// </summary>
        std::vector<GFF::Game::Character::Enemy*> m_enemys;

        /// <summary>
        /// �����̃p�����[�^
        /// </summary>
        GFF::System::EquipmentDatas m_equipmentDatas;
    };
} // Scene
} // GFF