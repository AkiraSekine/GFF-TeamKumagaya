#pragma once

#include <random>

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// ���������N���X
    /// </summary>
    class Random
    {
    public:

        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        Random(const int& _min, const int& _max);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        /// <param name="_seed">�V�[�h�l</param>
        Random(const int& _min, const int& _max, const int& _seed);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        Random(const float& _min, const float& _max);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        /// <param name="_seed">�V�[�h�l</param>
        Random(const float& _min, const float& _max, const int& _seed);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        /// <param name="_mean">���ϒl</param>
        /// <param name="_stddev">�W���΍�</param>
        Random(const float& _min, const float& _max, const float& _mean, const float& _stddev);
        /// <param name="_min">�ŏ��l</param>
        /// <param name="_max">�ő�l</param>
        /// <param name="_mean">���ϒl</param>
        /// <param name="_stddev">�W���΍�</param>
        /// <param name="_seed">�V�[�h�l</param>
        Random(const float& _min, const float& _max, const float& _mean, const float& _stddev, const int& _seed);

        /// <summary>
        /// �����𐮐��^�Ŏ擾
        /// </summary>
        /// <returns>����</returns>
        int GetInt();
        /// <summary>
        /// �����������^�Ŏ擾
        /// </summary>
        /// <returns>����</returns>
        float GetReal();
        /// <summary>
        /// ������W���΍��Ŏ擾
        /// </summary>
        /// <returns>����</returns>
        float GetNormal();

        /// <summary>
        /// �V�[�h�l���擾
        /// </summary>
        /// <returns>�V�[�h�l</returns>
        int GetSeed() const;

    private:

        /// <summary>
        /// ����������
        /// </summary>
        union Generator
        {
            Generator() { }
            ~Generator() { }

            std::uniform_int_distribution<> intDist;
            std::uniform_real_distribution<> realDist;
            std::normal_distribution<> normalDist;
        };

        /// <summary>
        /// �����^�̐����l
        /// </summary>
        struct IntLimit
        {
            int min;
            int max;
        };

        /// <summary>
        /// �����^�̐����l
        /// </summary>
        struct RealLimit
        {
            float min;
            float max;
        };

        /// <summary>
        /// �����l
        /// </summary>
        union Limit
        {
            Limit() { }
            ~Limit() { }

            IntLimit intLimit;
            RealLimit realLimit;
        };
        
        Generator m_randGen;

        Limit m_limit;

        std::mt19937 m_engine;

        int m_seed;

    };
} // Utility
} // CreaDXTKLib