#pragma once

#include "../Math/Transform.h"
#include "CreaDXTKLib.h"

#ifndef OBJECT2D

#define OBJECT2D(_CLASS)\
public:\
_CLASS() :\
Object2D()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const Math::Vector2& _position = Math::Vector2::zero,\
float _rotation = 0.f,\
const Math::Vector2& _scale = Math::Vector2::one,\
Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
Object2D(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const Math::Transform2D& _transform,\
Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
Object2D(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ End(); }

#endif // !OBJECT2D

namespace CreaDXTKLib
{
    namespace Math
    {
        class Transform2D;
    }

    class Object2D : public Math::Transform2D
    {
    public:

        Object2D();
        /// <param name="_imageName">�摜�̃n���h����</param>
        /// <param name="_position">���W</param>
        /// <param name="_rotation">��]�p</param>
        /// <param name="_scale">�g�嗦</param>
        /// <param name="_parent">�eTransform2D</param>
        /// <param name="_objectName">�I�u�W�F�N�g��</param>
        Object2D(const std::wstring& _imageName,
            const Math::Vector2& _position = Math::Vector2::zero,
            float _rotation = 0.f,
            const Math::Vector2& _scale = Math::Vector2::one,
            Math::Transform2D* _parent = nullptr,
            const std::wstring& _objectName = L"Object");
        /// <param name="_transform">Transform2D</param>
        /// <param name="_parent">�etransform2D</param>
        /// <param name="_objectName">�I�u�W�F�N�g��</param>
        Object2D(const std::wstring& _imageName,
            const Math::Transform2D& _transform,
            Math::Transform2D* _parent = nullptr,
            const std::wstring& _objectName = L"Object");

        virtual ~Object2D();

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() ABSTRACT;
        /// <summary>
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) ABSTRACT;
        /// <summary>
        /// �I������
        /// </summary>
        virtual void End() ABSTRACT;

        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(DirectX::FXMVECTOR& _color = DirectX::Colors::White);
        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_rect">�`���`</param>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(const RECT& _rect,
            DirectX::FXMVECTOR& _color = DirectX::Colors::White);
        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(DirectX::XMVECTORF32& _color);
        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_rect">�`���`</param>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(const RECT& _rect, DirectX::XMVECTORF32& _color);

        /// <summary>
        /// �A�N�e�B�u��Ԃ�ݒ�
        /// </summary>
        /// <param name="_isActive">�A�N�e�B�u��Ԃ�</param>
        virtual void SetActive(bool _isActive) final;

        /// <summary>
        /// �I�u�W�F�N�g�����擾
        /// </summary>
        /// <returns>�I�u�W�F�N�g��</returns>
        virtual std::wstring ObjectName() final;
        /// <summary>
        /// �I�u�W�F�N�g����ݒ�
        /// </summary>
        /// <param name="_objectName">�I�u�W�F�N�g��</param>
        virtual void ObjectName(const std::wstring& _objectName) final;

        virtual operator bool() const;

    protected:

        /// <summary>
        /// �A�N�e�B�u��Ԃ�
        /// </summary>
        bool m_isActive = true;

        /// <summary>
        /// �I�u�W�F�N�g��
        /// </summary>
        std::wstring m_objectName;

    private:

        std::wstring m_imageHandle;

        bool CheckParentIsActive();
    };
}