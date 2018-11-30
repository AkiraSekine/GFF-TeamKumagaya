#pragma once

namespace GFF
{
namespace Math
{
    /// <summary>
    /// 値が範囲内に入っているか
    /// </summary>
    /// <param name="_value">調べる値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    /// <returns>値が範囲内か</returns>
    template <typename T>
    extern inline bool Within(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// 値を範囲内に収める
    /// </summary>
    /// <param name="_value">調べる値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    /// <returns>範囲内に収めた値</returns>
    template <typename T>
    extern inline T Clamp(const T& _value, const T& _min, const T& _max);

    /// <summary>
    /// 値が範囲内で循環させる
    /// </summary>
    /// <param name="_value">調べる値</param>
    /// <param name="_min">最小値</param>
    /// <param name="_max">最大値</param>
    /// <returns>循環させた値</returns>
    template <typename T>
    extern inline T Circulate(const T& _value, const T& _min, const T& _max);
} // Math
} // GFF

#include "Math.inl"