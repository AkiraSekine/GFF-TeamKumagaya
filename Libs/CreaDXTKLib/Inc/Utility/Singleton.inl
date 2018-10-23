#pragma once

namespace CreaDXTKLib
{
namespace Utility
{
    template<class T>
    inline T & Singleton<T>::Instance()
    {
        // ���[�J���̐ÓI�ȃC���X�^���X�𐶐�
        static T instance;

        return instance;
    }
} // Utility
} // CreaDXTKLib