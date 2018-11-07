#pragma once

#include <stdexcept>

namespace GFF
{
namespace Utility
{
    template<typename T>
    inline T Random::GetRand()
    {
        // �e���v���[�g�̌^��int��float�łȂ���Η�O���o��
        if (typeid(T) != typeid(int) && typeid(T) != typeid(float))
        {
            throw std::invalid_argument("");
        }

        if (m_isInt)
        {
            // int�^�̗����𐶐�
            return m_generator.intDist(m_randEngine);
        }
        else if (m_isNormal)
        {
            float ret;

            do
            {
                // ��l���z�ł̗����𐶐�
                ret = m_generator.normalDist(m_randEngine);

                // �������������������l�͈͓̔��ɂȂ�܂ŌJ��Ԃ�
            } while (ret < m_limit.floatLimit.min || ret > m_limit.floatLimit.max);

            return ret;
        }
        else
        {
            // float�^�̗����𐶐�
            return m_generator.floatDist(m_randEngine);
        }
    }
} // Utility
} // GFF