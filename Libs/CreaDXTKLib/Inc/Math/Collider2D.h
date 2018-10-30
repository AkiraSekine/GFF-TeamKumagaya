#pragma once

#include "Vector2.h"
#include "../CreaDXTKLib/CreaDXTKLib.h"

namespace CreaDXTKLib
{
namespace Math
{
    class CircleCollider;
    class BoxCollider;
    class LineCollider;

    /// <summary>
    /// 2D�̓����蔻��
    /// </summary>
    class Collider2D
    {
    public:

        /// <summary>
        /// �`��
        /// </summary>
        enum Shape
        {
            Circle,
            Box,
            Line
        };

        /// <summary>
        /// �`��
        /// </summary>
        Shape m_shape;

        virtual ~Collider2D() { }

        /// <summary>
        /// �������Ă��邩�̎擾
        /// </summary>
        /// <returns>������������̃R���C�_�[</returns>
        virtual Collider2D* CheckCollision() const final;
        /// <summary>
        /// �������Ă��邩�̎擾
        /// </summary>
        /// <returns>������������̃R���C�_�[</returns>
        virtual Collider2D* CheckCollision(Collider2D* _collider) const final;

        /// <summary>
        /// ����Ώۂ̒ǉ�
        /// </summary>
        /// <param name="_collider">�Ώ�</param>
        virtual void AddTarget(Collider2D* _collider);

    protected:

        /// <summary>
        /// �^�[�Q�b�g
        /// </summary>
        std::vector<Collider2D*> m_targets = std::vector<Collider2D*>();

        /// <summary>
        /// CircleCollider�Ƃ̔��菈��
        /// </summary>
        /// <param name="_target">�^�[�Q�b�g</param>
        virtual Collider2D* CheckCircle(CircleCollider* _target) const ABSTRACT;
        /// <summary>
        /// BoxCollider�Ƃ̔��菈��
        /// </summary>
        /// <param name="_target">�^�[�Q�b�g</param>
        virtual Collider2D* CheckBox(BoxCollider* _target) const ABSTRACT;
        /// <summary>
        /// LineCollider�Ƃ̔��菈��
        /// </summary>
        /// <param name="_target">�^�[�Q�b�g</param>
        virtual Collider2D* CheckLine(LineCollider* _target) const ABSTRACT;

    };

    /// <summary>
    /// �����̃R���C�_�[
    /// </summary>
    class LineCollider : public Collider2D
    {
    public:

        /// <summary>
        /// �[�_�̐�
        /// </summary>
        static const unsigned char numOfPoints = 2;

        /// <summary>
        /// �[�_�̍��W
        /// </summary>
        const Vector2* point[numOfPoints];
        /// <summary>
        /// �����̃x�N�g��
        /// </summary>
        const Vector2& lineVec;

        /// <param name="_start">�n�_���W</param>
        /// <param name="_end">�I�_���W</param>
        LineCollider(const Vector2& _start, const Vector2& _end);

    private:

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

    };

    /// <summary>
    /// �~�`�̃R���C�_�[
    /// </summary>
    class CircleCollider : public Collider2D
    {
    public:

        /// <summary>
        /// ���S���W
        /// </summary>
        const Vector2& position;
        /// <summary>
        /// ���a
        /// </summary>
        const float& radius;

        /// <param name="_position">���S���W</param>
        /// <param name="_radius">���a</param>
        CircleCollider(const Vector2& _position, const float& _radius);

    private:

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

    };

    /// <summary>
    /// ��`�̃R���C�_�[
    /// </summary>
    class BoxCollider : public Collider2D
    {
    public:

        /// <summary>
        /// �ӂ̐�
        /// </summary>
        static const unsigned char numOfLines = 4;

        /// <summary>
        /// LineCollider4�ӕ�
        /// </summary>
        LineCollider* lines[numOfLines];
        /// <summary>
        /// ���S���W
        /// </summary>
        const Vector2& centerPosition;
        /// <summary>
        /// ��`�T�C�Y
        /// </summary>
        const Vector2& size;

        /// <param name="_centerPosition">���S���W</param>
        /// <param name="_size">��`�T�C�Y</param>
        BoxCollider(const Vector2& _centerPosition, const Vector2& _size);
        virtual ~BoxCollider();

        /// <summary>
        /// ����Ώۂ̒ǉ�
        /// </summary>
        /// <param name="_collider">�Ώ�</param>
        virtual void AddTarget(Collider2D* _collider) override;

    private:

        virtual Collider2D* CheckCircle(CircleCollider* _target) const;
        virtual Collider2D* CheckBox(BoxCollider* _target) const;
        virtual Collider2D* CheckLine(LineCollider* _target) const;

    };
} // Math
} // CreaDXTKLib