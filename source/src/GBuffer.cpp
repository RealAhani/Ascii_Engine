///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#include "GBuffer.hpp"
#include "GSprite.hpp"
namespace AE
{

	GBuffer::GBuffer() 
	{
		m_Sprites.reserve(150);
		m_Sprites.resize(150);
		Init_Buffer();
	}
	GBuffer::~GBuffer()
	{
		Clear_Buffer();
	}
	void GBuffer::Init_Buffer()
	{
		int t_size = GScreen::Get_with() * GScreen::Get_heigth();
		m_buffer_pixles_symboles = new  short[t_size]
		{};
		m_buffer_pixles_colors = new  short[t_size]
		{};
	}
	void GBuffer::Clear_Buffer()
	{
		delete m_buffer_pixles_symboles;
		delete m_buffer_pixles_colors;
		m_buffer_pixles_symboles = m_buffer_pixles_colors = nullptr;
		Clear_Sprite();
	}
	// Add to Sprite
	void GBuffer::Add_Sprite(const GSprite& sprite)
	{
		m_Sprites.emplace_back(sprite);
	}
	void GBuffer::Clear_Sprite()
	{
		m_Sprites.clear();
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
				const auto& pos = res.Get_Sprite_Position();
				for (s_uint y = 0; y < res.Get_Sprite_Hight(); ++y)
				{
					if (y + pos.y >= GScreen::Get_heigth())
						break;
					for (s_uint x = 0; x < res.Get_Sprite_Width(); ++x)
					{
						if (x + pos.x >= GScreen::Get_with())
							break;
						m_buffer_pixles_symboles[AE::GPuzzle::GHelper::Whatis_index<int>(GScreen::Get_with(), x + pos.x, y + pos.y)] =
							res.Get_Symboles_Array().at(AE::GPuzzle::GHelper::Whatis_index<int>(res.Get_Sprite_Width(), x, y));
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
				const auto& pos = res.Get_Sprite_Position();
				for (s_uint y = 0; y < res.Get_Sprite_Hight(); ++y)
				{
					if (y + pos.y >= GScreen::Get_heigth())
						break;
					for (s_uint x = 0; x < res.Get_Sprite_Width(); ++x)
					{
						if (x + pos.x >= GScreen::Get_with())
							break;
						m_buffer_pixles_colors[AE::GPuzzle::GHelper::Whatis_index<int>(GScreen::Get_with(), x + pos.x, y + pos.y)] =
							res.Get_Colors_Array().at(AE::GPuzzle::GHelper::Whatis_index<int>(res.Get_Sprite_Width(), x, y));
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
		const auto& temp_size = GScreen::Get_with() * GScreen::Get_heigth();
		for (size_t i = 0; i < temp_size; ++i)
		{
			if (m_buffer_pixles_symboles[i] == 0)
			{
				m_buffer_pixles_symboles[i] = L' ';
			}
		}
	}
}