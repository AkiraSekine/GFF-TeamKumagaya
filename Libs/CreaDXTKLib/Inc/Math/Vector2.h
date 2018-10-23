#pragma once

#include "../Default/pch.h"

#include <string>

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// 2D�x�N�g��
    /// </summary>
    class Vector2
    {
    public:

        /// <summary>
        /// x�����̑傫��
        /// </summary>
        float x;
        /// <summary>
        /// y�����̑傫��
        /// </summary>
        float y;

        /// <summary>
        /// Vector2(0.0f, 0.0f)
        /// </summary>
        static Vector2 zero;
        /// <summary>
        /// Vector2(1.0f, 1.0f)
        /// </summary>
        static Vector2 one;

        Vector2();
        Vector2(float _x);
        Vector2(float _x, float _y);
        virtual ~Vector2();

        /// <summary>
        /// �x�N�g���̑傫�����v�Z
        /// </summary>
        /// <returns>�x�N�g���̑傫��</returns>
        virtual float Magnitude();
        /// <summary>
        /// �x�N�g���̑傫����2����v�Z
        /// </summary>
        /// <returns>�x�N�g���̑傫����2��</returns>
        virtual float SqrMagnitude();

        /// <summary>
        /// ���K�������l���v�Z
        /// </summary>
        /// <returns>���K�l</returns>
        virtual Vector2 Normalize();

        /// <summary>
        /// ���ς��v�Z
        /// </summary>
        /// <param name="_vec">�x�N�g��</param>
        /// <returns>����</returns>
        virtual float Dot(Vector2& _vec);
        /// <summary>
        /// �O�ς��v�Z
        /// </summary>
        /// <param name="_vec">�x�N�g��</param>
        /// <returns>�O��</returns>
        virtual float Cross(Vector2& _vec);

        virtual const Vector2 operator-() const;
        virtual const Vector2 operator+(const Vector2& _vec) const;
        virtual const Vector2 operator+(const float& _value) const;
        virtual const Vector2 operator+(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator-(const Vector2& _vec) const;
        virtual const Vector2 operator-(const float& _value) const;
        virtual const Vector2 operator-(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator*(const Vector2& _vec) const;
        virtual const Vector2 operator*(const float& _value) const;
        virtual const Vector2 operator*(const DirectX::SimpleMath::Vector2& _vec) const;
        virtual const Vector2 operator/(const Vector2& _vec) const;
        virtual const Vector2 operator/(const float& _value) const;
        virtual const Vector2 operator/(const DirectX::SimpleMath::Vector2& _vec) const;

        virtual inline Vector2& operator+=(const Vector2& _vec);
        virtual inline Vector2& operator+=(const float _value);
        virtual inline Vector2& operator+=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator-=(const Vector2& _vec);
        virtual inline Vector2& operator-=(const float _value);
        virtual inline Vector2& operator-=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator*=(const Vector2& _vec);
        virtual inline Vector2& operator*=(const float _value);
        virtual inline Vector2& operator*=(const DirectX::SimpleMath::Vector2& _vec);
        virtual inline Vector2& operator/=(const Vector2& _vec);
        virtual inline Vector2& operator/=(const float _value);
        virtual inline Vector2& operator/=(const DirectX::SimpleMath::Vector2& _vec);

        virtual inline operator std::wstring () const;
        virtual inline operator DirectX::SimpleMath::Vector2 () const;

    protected:

    private:

    };
}
}

#include "Vector2.inl"