//
// �����:     �֍� ����
// ���e:       �����f�[�^
// �쐬��:     2018/10/26
// �ŏI�X�V��: 2018/11/27
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
        enum struct Kind
        {
            mm9,    // HG, SMG
            mm5p56, // AR
            mm7p62, // MG
            GA12,   // SG
            mm12p7  // SR
        };

        /// <summary>
        /// �e�̎��
        /// </summary>
        Kind kind;

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
        enum struct Kind
        {
            HG,
            SMG,
            AR,
            MG,
            SG,
            SR
        };

        /// <summary>
        /// �e�̎��
        /// </summary>
        Kind kind;

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

    /// <summary>
    /// �e�e�̎�ސ�
    /// </summary>
    static const int NumOfBullets = 5;
    /// <summary>
    /// �e�̎�ސ�
    /// </summary>
    static const int NumOfGuns = 6;

    /// <summary>
    /// �e�e�Əe�̃p�����[�^
    /// </summary>
    struct EquipmentDatas
    {
        /// <summary>
        /// �e�e�f�[�^
        /// </summary>
        Bullet bulletData[NumOfBullets];
        /// <summary>
        /// �e�f�[�^
        /// </summary>
        Gun gunData[NumOfGuns];
    };
} // System
} // GFF