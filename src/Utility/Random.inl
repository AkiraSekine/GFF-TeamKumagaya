#pragma once

#include <stdexcept>

namespace GFF
{
namespace Utility
{
    template<typename T>
    inline T Random::GetRand()
    {
        // テンプレートの型がintかfloatでなければ例外を出す
        if (typeid(T) != typeid(int) && typeid(T) != typeid(float))
        {
            throw std::invalid_argument("");
        }

        if (m_isInt)
        {
            // int型の乱数を生成
            return m_generator.intDist(m_randEngine);
        }
        else if (m_isNormal)
        {
            float ret;

            do
            {
                // 一様分布での乱数を生成
                ret = m_generator.normalDist(m_randEngine);

                // 生成した乱数が制限値の範囲内になるまで繰り返す
            } while (ret < m_limit.floatLimit.min || ret > m_limit.floatLimit.max);

            return ret;
        }
        else
        {
            // float型の乱数を生成
            return m_generator.floatDist(m_randEngine);
        }
    }
} // Utility
} // GFF