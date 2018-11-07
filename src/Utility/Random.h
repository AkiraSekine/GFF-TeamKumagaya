#pragma once

#include <random>

namespace GFF
{
namespace Utility
{
    /// <summary>
    /// 乱数生成クラス
    /// </summary>
    class Random final
    {
    public:

        Random();
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        Random(const int& _min, const int& _max);
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        Random(const float& _min, const float& _max);
        /// <param name="_mean">平均値</param>
        /// <param name="_stdev">標準偏差</param>
        /// <param name="_min">最小値</param>
        /// <param name="_max">最大値</param>
        Random(const float& _mean, const float& _stdev, const float& _min, const float& _max);

        /// <summary>
        /// 乱数の取得
        /// </summary>
        template <typename T>
        T GetRand();

    private:

        /// <summary>
        /// int型の制限値
        /// </summary>
        struct LimitInt
        {
            int min, max;
        };

        /// <summary>
        /// float型の制限値
        /// </summary>
        struct LimitFloat
        {
            float min, max;
        };

        /// <summary>
        /// 制限値
        /// </summary>
        union Limit
        {
            Limit() { }
            ~Limit() { }

            LimitInt intLimit;
            LimitFloat floatLimit;
        };

        /// <summary>
        /// 分布生成器
        /// </summary>
        union Generator
        {
            Generator() { }
            ~Generator() { }

            std::uniform_int_distribution<> intDist;
            std::uniform_real_distribution<> floatDist;
            std::normal_distribution<> normalDist;
        };

        /// <summary>
        /// 制限値
        /// </summary>
        Limit m_limit;
        /// <summary>
        /// 分布生成器
        /// </summary>
        Generator m_generator;

        /// <summary>
        /// 乱数生成器
        /// </summary>
        std::mt19937 m_randEngine;

        /// <summary>
        /// ランダムシード生成器
        /// </summary>
        static std::random_device m_seedGen;

        /// <summary>
        /// 返り値がint型か
        /// </summary>
        bool m_isInt;
        /// <summary>
        /// 返り値が一様分布か
        /// </summary>
        bool m_isNormal;

    };
} // Utility
} // GFF

#include "Random.inl"