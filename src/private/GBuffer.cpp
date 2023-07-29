#include "Engine_PCH.hpp"
#include "GBuffer.hpp"
#include "GSprite.hpp"
namespace AE
{

	GBuffer::GBuffer(s_uint width, s_uint height) : m_width { width }, m_height { height }
	{
		m_Sprites.reserve(150);
		m_Sprites.resize(150);
		Init_Buffer(width, height);
	}
	GBuffer::~GBuffer()
	{
		Clear_Buffer();
	}
	void GBuffer::Init_Buffer(s_uint width, s_uint height)
	{

		m_buffer_pixles_symboles = new  short[width * height]
		{};
		m_buffer_pixles_colors = new  short[width * height]
		{};
	}
	void GBuffer::Clear_Buffer()
	{
		delete m_buffer_pixles_symboles;
		delete m_buffer_pixles_colors;
		m_buffer_pixles_symboles = m_buffer_pixles_colors = nullptr;
		m_width = m_height = 0;
	}
	// Add to Sprite
	void GBuffer::Add_Sprite(const GSprite& sprite)
	{
		m_Sprites.emplace_back(sprite);
	}
	// Sort Sprite Array Based on Zbuffer 
	///TO DO Z BUFFER SHOULD CREATE
	void GBuffer::Sort_Sprites_Array()
	{
		/*for (size_t i { 0 }; i < m_Sprites.size(); ++i)
		{
			for (size_t j { 1 }; j < m_Sprites.size(); ++j)
			{
				if (m_Sprites.at(i).Get_Sprite_Position().y > m_Sprites.at(j).Get_Sprite_Position().y)
				{
					auto temp = m_Sprites.at(i);
					m_Sprites.at(i) = m_Sprites.at(j);
					m_Sprites.at(j) = temp;
				}
			}
		}
		for (size_t i { 0 }; i < m_Sprites.size(); ++i)
		{
			for (size_t j { 1 }; j < m_Sprites.size(); ++j)
			{
				if (m_Sprites.at(i).Get_Sprite_Position().x > m_Sprites.at(j).Get_Sprite_Position().x)
				{
					auto temp = m_Sprites.at(i);
					m_Sprites.at(i) = m_Sprites.at(j);
					m_Sprites.at(j) = temp;
				}
			}
		}*/
	}
	// Set pixels buffer based on sorted sprite array
	void GBuffer::Fill_Pixels_Symboles()
	{
		for (auto& res : m_Sprites)
		{
			if (!res.Get_Symboles_Array().empty())
			{
				auto pos = res.Get_Sprite_Position();
				for (s_uint y = 0; y < res.Get_Sprite_Hight(); ++y)
				{
					if (y + pos.y >= m_height)
						break;
					for (s_uint x = 0; x < res.Get_Sprite_Width(); ++x)
					{
						if (x + pos.x >= m_width)
							break;
						m_buffer_pixles_symboles[AE::GPuzzle::GHelper::Whatis_index(m_width, x + pos.x, y + pos.y)] =
							res.Get_Symboles_Array().at(AE::GPuzzle::GHelper::Whatis_index(res.Get_Sprite_Width(), x, y));
					}
				}
			}
		}
	}
	void GBuffer::Fill_Pixels_Color()
	{
		for (auto& res : m_Sprites)
		{
			if (!res.Get_Colors_Array().empty())
			{
				auto pos = res.Get_Sprite_Position();
				for (s_uint y = 0; y < res.Get_Sprite_Hight(); ++y)
				{
					if (y + pos.y >= m_height)
						break;
					for (s_uint x = 0; x < res.Get_Sprite_Width(); ++x)
					{
						if (x + pos.x >= m_width)
							break;
						m_buffer_pixles_colors[AE::GPuzzle::GHelper::Whatis_index(m_width, x + pos.x, y + pos.y)] =
							res.Get_Colors_Array().at(AE::GPuzzle::GHelper::Whatis_index(res.Get_Sprite_Width(), x, y));
					}
				}
			}
		}
	}
	// Get pixles buffer
	short* GBuffer::Get_Buffer_Symboles_Array()
	{
		return m_buffer_pixles_symboles;
	}

	short* GBuffer::Get_Buffer_Color_Array()
	{
		return m_buffer_pixles_colors;
	}
	std::vector<GSprite>& GBuffer::Get_Sprites()
	{
		return m_Sprites;
	}

	// Correct empty pixles and get all thing to gether and send to GRendere
	void GBuffer::Currect_Empty_Index_Buffer()
	{
		for (size_t i = 0; i < m_width * m_height; ++i)
		{
			if (m_buffer_pixles_symboles[i] == 0)
			{
				m_buffer_pixles_symboles[i] = L' ';
			}
			if (m_buffer_pixles_colors[i] == 0)
			{
				m_buffer_pixles_colors[i] = 0x0000;
			}
		}
	}
}