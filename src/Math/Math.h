#pragma once

namespace GFF
{
namespace Math
{
    /// <summary>
    /// �l���͈͓��ɓ����Ă��邩
    /// </summary>
    /// <param name="_value">���ׂ�l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    /// <returns>�l���͈͓���</returns>
    template <typename T>
    extern inline bool Within(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// �l��͈͓��Ɏ��߂�
    /// </summary>
    /// <param name="_value">���ׂ�l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    /// <returns>�͈͓��Ɏ��߂��l</returns>
    template <typename T>
    extern inline T Clamp(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// �l���͈͓��ŏz������
    /// </summary>
    /// <param name="_value">���ׂ�l</param>
    /// <param name="_min">�ŏ��l</param>
    /// <param name="_max">�ő�l</param>
    /// <returns>�z�������l</returns>
    template <typename T>
    extern inline T Circulate(const T& _value, const T& _min, const T& _max);
} // Math
} // GFF

#include "Math.inl"