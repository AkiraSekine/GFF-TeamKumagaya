#pragma once

#include "CreaDXTKLib.h"

#include <string>

namespace CreaDXTKLib
{
    /// <summary>
    /// �V�[���̊��N���X
    /// </summary>
    class Scene
    {
    public:

        virtual ~Scene();

        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) ABSTRACT;
        /// <summary>
        /// �`�揈��
        /// </summary>
        virtual void OnRender() ABSTRACT;

        /// <summary>
        /// �N���X�����擾
        /// </summary>
        /// <returns>�N���X��</returns>
        virtual std::wstring GetSceneName() final;
    };
}