//
// �����:     �֍� ����
// ���e:       �����f�[�^
// �쐬��:     2018/10/26
// �ŏI�X�V��:
//

#pragma once

namespace GFF
{
namespace System
{
    /// <summary>
    /// �e�e�f�[�^
    /// </summary>
    struct Bullet
    {
        /// <summary>
        /// �З�
        /// </summary>
        float power;
        /// <summary>
        /// ����
        /// </summary>
        float recoil;
        /// <summary>
        /// �e��
        /// </summary>
        float moveSpeed;
        /// <summary>
        /// �˒�����
        /// </summary>
        float distance;
    };

    /// <summary>
    /// �e�f�[�^
    /// </summary>
    struct Gun
    {
        /// <summary>
        /// �ړ����x
        /// </summary>
        float moveSpeed;
        /// <summary>
        /// �A�ˑ��x
        /// </summary>
        float fireSpeed;
        /// <summary>
        /// �����[�h����
        /// </summary>
        float reloadTime;
        /// <summary>
        /// ���x
        /// </summary>
        float accuracy;
        /// <summary>
        /// �A�ˉ\��
        /// </summary>
        bool isContinuous;
        /// <summary>
        /// �g�p���̏e�e
        /// </summary>
        Bullet bullet;
    };
} // System
} // GFF