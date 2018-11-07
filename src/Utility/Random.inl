#pragma once

#include <stdexcept>

namespace GFF
{
namespace Utility
{
    template<typename T>
    inline T Random::GetRand()
    {
        if (typeid(T) != typeid(int) && typeid(T) != typeid(float))
        {
            throw std::invalid_argument("");
        }

        if (m_isInt)
        {
            return m_generator.intDist(m_randEngine);
        }
        else if (m_isNormal)
        {
            float ret;

            do
            {
                ret = m_generator.normalDist(m_randEngine);
            } while (ret < m_limit.floatLimit.min || ret > m_limit.floatLimit.max);

            return ret;
        }
        else
        {
            return m_generator.floatDist(m_randEngine);
        }
    }
} // Utility
} // GFF