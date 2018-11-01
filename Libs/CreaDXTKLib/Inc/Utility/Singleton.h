#pragma once

#ifndef SINGLETON

/// <summary>
/// �V���O���g���̐ݒ�
/// </summary>
/// <param name="_Class_">Singleton�����Ƃ����N���X</param>
#define SINGLETON(_Class_) \
public: \
friend class CreaDXTKLib::Utility::Singleton<_Class_>; \
protected: \
inline _Class_() { } \
inline ~_Class_() { }

#endif // !SINGLETON

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// �V���O���g���̊��N���X
    /// </summary>
    template<class T>
    class Singleton
    {
    public:

        /// <summary>
        /// �C���X�^���X���擾
        /// </summary>
        /// <returns>�C���X�^���X</returns>
        static T & Instance();

    protected:

        inline Singleton() { } // �O���ł̃C���X�^���X�������֎~
        inline virtual ~Singleton() { }

    private:

        inline Singleton(const Singleton&) { } // �R�s�[�R���X�g���N�^�̎g�p�֎~

        inline void operator = (const Singleton& obj) { } // ������Z�q�̎g�p�֎~

    };

} // Utility
} // CreaDXTKLib

// ��`�t�@�C�����C���N���[�h
#include "Singleton.inl"