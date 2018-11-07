#pragma once

#include <random>

namespace GFF
{
namespace Utility
{
    /// <summary>
    /// ���������N���X
    /// </summary>
    class Random final
    {
    public:

        Random();
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        Random(const int& _min, const int& _max);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        Random(const float& _min, const float& _max);
        /// <param name="_mean">���ϒl</param>
        /// <param name="_stdev">�W���΍�</param>
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        Random(const float& _mean, const float& _stdev, const float& _min, const float& _max);

        /// <summary>
        /// �����̎擾
        /// </summary>
        template <typename T>
        T GetRand();

    private:

        /// <summary>
        /// int�^�̐����l
        /// </summary>
        struct LimitInt
        {
            int min, max;
        };

        /// <summary>
        /// float�^�̐����l
        /// </summary>
        struct LimitFloat
        {
            float min, max;
        };

        /// <summary>
        /// �����l
        /// </summary>
        union Limit
        {
            Limit() { }
            ~Limit() { }

            LimitInt intLimit;
            LimitFloat floatLimit;
        };

        /// <summary>
        /// ���z������
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
        /// �����l
        /// </summary>
        Limit m_limit;
        /// <summary>
        /// ���z������
        /// </summary>
        Generator m_generator;

        /// <summary>
        /// ����������
        /// </summary>
        std::mt19937 m_randEngine;

        /// <summary>
        /// �����_���V�[�h������
        /// </summary>
        static std::random_device m_seedGen;

        /// <summary>
        /// �Ԃ�l��int�^��
        /// </summary>
        bool m_isInt;
        /// <summary>
        /// �Ԃ�l����l���z��
        /// </summary>
        bool m_isNormal;

    };
} // Utility
} // GFF

#include "Random.inl"