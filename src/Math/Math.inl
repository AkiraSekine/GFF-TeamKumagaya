#pragma once

namespace GFF
{
namespace Math
{
    template<typename T>
    bool Within(const T& _value, const T& _min, const T& _max)
    {
        return (_min <= _value && _value <= _max);
    }

    template<typename T>
    T Clamp(const T& _value, const T& _min, const T& _max)
    {
        if (_value < _min)
        {
            return _min;
        }
        else if (_value > _max)
        {
            return _max;
        }

        return _value;
    }

    template<typename T>
    T Circulate(const T& _value, const T& _min, const T& _max)
    {
        T range = _max - _min;
        T ret = _value;

        while (ret > _max)
        {
            ret -= range;
        }

        while (ret < _min)
        {
            ret += range;
        }

        return ret;
    }
} // Math
} // GFF