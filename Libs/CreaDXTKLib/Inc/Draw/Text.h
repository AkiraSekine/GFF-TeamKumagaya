#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"
#include "../Math/Vector2.h"

#include <string>
#include <map>

namespace CreaDXTKLib
{
namespace Draw
{
    /// <summary>
    /// �e�L�X�g�`��N���X
    /// </summary>
    class Text final : public Utility::Singleton<Text>
    {
        SINGLETON(Text)

    public:

        /// <summary>
        /// �t�H���g�t�@�C���̓ǂݍ���
        /// </summary>
        /// <param name="_key">�n���h����</param>
        /// <param name="_fileName">�t�@�C����</param>
        void Load(const std::wstring& _key, const std::wstring& _fileName);

        /// <summary>
        /// �e�L�X�g�̕`��
        /// </summary>
        /// <param name="_key">�n���h����</param>
        /// <param name="_position">�`����W</param>
        /// <param name="_text">�`�敶����(�t�H�[�}�b�g)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const std::wstring _text, ...);
        /// <summary>
        /// �e�L�X�g�̕`��
        /// </summary>
        /// <param name="_key">�n���h����</param>
        /// <param name="_position">�`����W</param>
        /// <param name="_color">�F</param>
        /// <param name="_text">�`�敶����(�t�H�[�}�b�g)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const DirectX::XMVECTORF32& _color , const std::wstring _text, ...);
        /// <summary>
        /// �e�L�X�g�̕`��
        /// </summary>
        /// <param name="_key">�n���h����</param>
        /// <param name="_position">�`����W</param>
        /// <param name="_color">�F</param>
        /// <param name="_text">�`�敶����(�t�H�[�}�b�g)</param>
        void Draw(const std::wstring& _key, const Math::Vector2& _position, const DirectX::FXMVECTOR& _color , const std::wstring _text, ...);

        /// <summary>
        /// ����������
        /// </summary>
        void Initialize(Microsoft::WRL::ComPtr<ID3D11Device1> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context);

        /// <summary>
        /// �I������
        /// </summary>
        void OnEnd();

    private:

        Microsoft::WRL::ComPtr<ID3D11Device1> m_device;

        std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

        std::map<std::wstring, DirectX::SpriteFont*> m_fonts = std::map<std::wstring, DirectX::SpriteFont*>();

    };
} // Draw
} // CreaDXTKLib