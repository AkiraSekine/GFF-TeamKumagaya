#pragma once

#include "Vector2.h"

#include <vector>

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// �ʒu,��],�X�P�[�����
    /// </summary>
    class Transform2D
    {
    public:

        Transform2D();

        /// <param name="_position">���W</param>
        /// <param name="_parent">�eTransform2D</param>
        Transform2D(const Vector2& _position,
            Transform2D * _parent = nullptr);

        /// <param name="_position">���W</param>
        /// <param name="_rotation">��]�p</param>
        /// <param name="_parent">�eTransform2D</param>
        Transform2D(const Vector2& _position,
            const float& _rotation,
            Transform2D * _parent = nullptr);

        /// <param name="_position">���W</param>
        /// <param name="_rotation">��]�p</param>
        /// <param name="_scale">�g�嗦</param>
        /// <param name="_parent">�eTransform2D</param>
        Transform2D(const Vector2& _position,
            const float& _rotation,
            const Vector2& _scale,
            Transform2D * _parent = nullptr);

        virtual ~Transform2D();

        /// <summary>
        /// ���W���擾
        /// </summary>
        /// <returns>���W</returns>
        virtual Vector2 Position() const final;
        /// <summary>
        /// ���W��ݒ�
        /// </summary>
        /// <param name="_newPos">�V�������W</param>
        virtual void Position(const Vector2& _newPos) final;
        /// <summary>
        /// ���΍��W���擾
        /// </summary>
        /// <returns>���΍��W</returns>
        virtual Vector2 LocalPosition() const final;

        /// <summary>
        /// ��]�p���擾
        /// </summary>
        /// <returns>��]�p</returns>
        virtual float Rotation() const final;
        /// <summary>
        /// ��]�p��ݒ�
        /// </summary>
        /// <param name="_newRot">�V�����p�x</param>
        virtual void Rotation(const float& _newRot) final;
        /// <summary>
        /// ���Ίp�x���擾
        /// </summary>
        /// <returns>���Ίp�x</returns>
        virtual float LocalRotation() const final;

        /// <summary>
        /// �g�嗦���擾
        /// </summary>
        /// <returns>�g�嗦</returns>
        virtual Vector2 Scale() const final;
        /// <summary>
        /// �g�嗦��ݒ�
        /// </summary>
        /// <param name="_newScale">�V�����g�嗦</param>
        virtual void Scale(const Vector2& _newScale) final;

        /// <summary>
        /// �O�����̃x�N�g�����擾
        /// </summary>
        /// <returns>�O�����̃x�N�g��</returns>
        virtual Vector2 GetUpVector() const final;
        /// <summary>
        /// �E�����̃x�N�g�����擾
        /// </summary>
        /// <returns>�E�����̃x�N�g��</returns>
        virtual Vector2 GetRightVector() const final;

        /// <summary>
        /// �eTransform2D��ݒ�
        /// </summary>
        /// <param name="_parent">�e��Transfom2D</param>
        virtual void Parent(Transform2D * _parent);
        /// <summary>
        /// �eTransform2D���擾
        /// </summary>
        /// <returns>�eTransform2D</returns>
        virtual Transform2D * Parent() const final;
        /// <summary>
        /// �eTransform2D�Ƃ̐e�q�֌W������
        /// </summary>
        virtual void RemoveParent() final;

    protected:

    private:

        Vector2 m_position;
        float m_rotation;
        Vector2 m_scale;
        Vector2 m_localPosition;
        float m_localRotation;

        std::vector<Transform2D *> m_children = std::vector<Transform2D *>();
        Transform2D * m_parent = nullptr;
        unsigned int m_childNum = 0;

        virtual float CorrectionRotation(float _rotation) final;

        void ChildrenCalc();

    };

} // CreaDXTKLib
} // Math