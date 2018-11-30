#pragma once

#include "../Math/Transform.h"
#include "CreaDXTKLib.h"

namespace CreaDXTKLib
{
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
            const float& _rotation = 0.f,
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
        /// �X�V����
        /// </summary>
        /// <param name="_elapsedTime">�O�t���[������̌o�ߎ���</param>
        virtual void Update(float _elapsedTime) ABSTRACT;

        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(const DirectX::FXMVECTOR& _color = DirectX::Colors::White) const final;
        /// <summary>
        /// �I�u�W�F�N�g��`��
        /// </summary>
        /// <param name="_rect">�`���`</param>
        /// <param name="_color">���Z�F</param>
        virtual void Draw(const RECT& _rect,
            const DirectX::FXMVECTOR& _color = DirectX::Colors::White) const final;

        /// <summary>
        /// �A�N�e�B�u��Ԃ�ݒ�
        /// </summary>
        /// <param name="_isActive">�A�N�e�B�u��Ԃ�</param>
        virtual void SetActive(const bool& _isActive) final;

        /// <summary>
        /// �I�u�W�F�N�g�����擾
        /// </summary>
        /// <returns>�I�u�W�F�N�g��</returns>
        virtual std::wstring ObjectName() const final;
        /// <summary>
        /// �I�u�W�F�N�g����ݒ�
        /// </summary>
        /// <param name="_objectName">�I�u�W�F�N�g��</param>
        virtual void ObjectName(const std::wstring& _objectName) final;

        virtual operator bool() const;

    protected:

        /// <summary>
        /// �I�u�W�F�N�g��
        /// </summary>
        std::wstring m_objectName;

        std::wstring m_imageHandle;

        /// <summary>
        /// �J�n����
        /// </summary>
        virtual void Start() { }

        /// <summary>
        /// �I������
        /// </summary>
        virtual void OnDestroy() { }

        /// <summary>
        /// �A�N�e�B�u��ԂɂȂ������ɌĂ΂��
        /// </summary>
        virtual void OnEnable() { }

        /// <summary>
        /// ��A�N�e�B�u��ԂɂȂ������ɌĂ΂��
        /// </summary>
        virtual void OnDisable() { }

    private:

        bool m_isActive = true;

        bool CheckParentIsActive() const;
    };
}

#ifndef OBJECT2D

/// <summary>
/// �I�u�W�F�N�g�̐ݒ�
/// </summary>
/// <param name="_CLASS">Object2D�����Ƃ����N���X</param>
#define OBJECT2D(_CLASS)\
public:\
_CLASS() :\
CreaDXTKLib::Object2D()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Vector2& _position = CreaDXTKLib::Math::Vector2::zero,\
const float& _rotation = 0.f,\
const CreaDXTKLib::Math::Vector2& _scale = CreaDXTKLib::Math::Vector2::one,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
CreaDXTKLib::Object2D(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Transform2D& _transform,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
CreaDXTKLib::Object2D(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ OnDestroy(); }

#endif // !OBJECT2D

#ifndef OBJECT2D_PARENT

/// <summary>
/// �I�u�W�F�N�g�̐ݒ�
/// </summary>
/// <param name="_CLASS">�N���X��</param>
/// <param name="_PARENT">���N���X</param>
#define OBJECT2D_PARENT(_CLASS, _PARENT)\
public:\
_CLASS() :\
_PARENT()\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Vector2& _position = CreaDXTKLib::Math::Vector2::zero,\
float _rotation = 0.f,\
const CreaDXTKLib::Math::Vector2& _scale = CreaDXTKLib::Math::Vector2::one,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
_PARENT(_imageName, _position, _rotation, _scale, _parent, _objectName)\
{ Start(); }\
_CLASS(const std::wstring& _imageName,\
const CreaDXTKLib::Math::Transform2D& _transform,\
CreaDXTKLib::Math::Transform2D* _parent = nullptr,\
const std::wstring& _objectName = L"Object") :\
_PARENT(_imageName, _transform, _parent, _objectName)\
{ Start(); }\
virtual ~_CLASS() override\
{ OnDestroy(); }

#endif // !OBJECT2D_PARENT