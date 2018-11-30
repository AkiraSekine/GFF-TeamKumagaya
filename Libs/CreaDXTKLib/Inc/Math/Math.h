#pragma once

#include "Vector2.h"

namespace CreaDXTKLib
{
namespace Math
{
    /// <summary>
    /// �f�O���[���烉�W�A���ɕϊ�
    /// </summary>
    extern const float Deg2Rad;
    /// <summary>
    /// ���W�A������f�O���[�ɕϊ�
    /// </summary>
    extern const float Rad2Deg;

    /// <summary>
    /// �l���͈͓��ɓ����Ă��邩
    /// </summary>
    /// <param name="_value">�`�F�b�N����l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    template <typename T>
    extern inline bool Within(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// �l��͈͓��Ɏ��߂�
    /// </summary>
    /// <param name="_value">�`�F�b�N����l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    /// <returns>�͈͓��̒l</returns>
    template <typename T>
    extern inline T Clamp(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// �l�����[�v������
    /// </summary>
    /// <param name="_value">�`�F�b�N����l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    /// <returns>���[�v�����l</returns>
    template <typename T>
    extern inline T Circulate(const T& _value, const T& _min, const T& _max);

    const Vector2 operator+(const float _value, const Vector2& _vec);
    const Vector2 operator-(const float _value, const Vector2& _vec);
    const Vector2 operator*(const float _value, const Vector2& _vec);
    const Vector2 operator/(const float _value, const Vector2& _vec);
} // Math
} // CreaDXTKLib

#include "Math.inl"