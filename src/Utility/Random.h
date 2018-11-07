#pragma once

#include <random>

namespace GFF
{
namespace Utility
{
    class Random final
    {
    public:

        Random();
        Random(const int& _min, const int& _max);
        Random(const float& _min, const float& _max);
        Random(const float& _mean, const float& _stdev, const float& _min, const float& _max);

        template <typename T>
        T GetRand();

    private:

        struct LimitInt
        {
            int min, max;
        };

        struct LimitFloat
        {
            float min, max;
        };

        union Limit
        {
            Limit() { }
            ~Limit() { }

            LimitInt intLimit;
            LimitFloat floatLimit;
        };

        union Generator
        {
            Generator() { }
            ~Generator() { }

            std::uniform_int_distribution<> intDist;
            std::uniform_real_distribution<> floatDist;
            std::normal_distribution<> normalDist;
        };

        Limit m_limit;
        Generator m_generator;

        std::mt19937 m_randEngine;

        static std::random_device m_seedGen;

        bool m_isInt;
        bool m_isNormal;

    };
} // Utility
} // GFF

#include "Random.inl"