#include "Random.h"

using namespace std;

namespace GFF
{
namespace Utility
{
    random_device Random::m_seedGen;

    Random::Random() :
        m_randEngine(m_seedGen()),
        m_isInt(false),
        m_isNormal(true)
    {
        m_limit.floatLimit.min = 0.0f;
        m_limit.floatLimit.max = 100.0f;

        m_generator.floatDist =
            uniform_real_distribution<>(m_limit.floatLimit.min, m_limit.floatLimit.max);
    }

    Random::Random(const int& _min, const int& _max) :
        m_randEngine(m_seedGen()),
        m_isInt(true)
    {
        m_limit.intLimit.min = _min;
        m_limit.intLimit.max = _max;

        m_generator.intDist = uniform_int_distribution<>(_min, _max);
    }

    Random::Random(const float& _min, const float& _max) :
        m_randEngine(m_seedGen()),
        m_isInt(false),
        m_isNormal(true)
    {
        m_limit.floatLimit.min = _min;
        m_limit.floatLimit.max = _max;

        m_generator.floatDist = uniform_real_distribution<>(_min, _max);
    }

    Random::Random(const float & _mean, const float & _stdev, const float & _min, const float & _max) :
        m_randEngine(m_seedGen()),
        m_isInt(false),
        m_isNormal(true)
    {
        m_limit.floatLimit.min = _min;
        m_limit.floatLimit.max = _max;

        m_generator.normalDist = normal_distribution<>(_mean, _stdev);
    }
} // Utility
} // GFF