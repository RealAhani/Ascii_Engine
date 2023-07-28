#pragma once
#include "GSprite.hpp"
namespace AE
{
	class GSprite;
	class GBuffer
	{
		using ushort = unsigned short;
		using s_uint = unsigned int;

	public:
		GBuffer(s_uint width, s_uint height) : m_width { width }, m_height { height }
		{
			m_Sprites.reserve(150);
			m_Sprites.resize(150);
			Init_Buffer(width, height);
		}
		~GBuffer()
		{
		}
		void Init_Buffer(s_uint width, s_uint height)
		{

			m_buffer_pixles_symboles = new  short[width * height]
			{};
			m_buffer_pixles_colors = new  short[width * height]
			{};
		}
		void Clear_Buffer()
		{
			delete m_buffer_pixles_symboles;
			delete m_buffer_pixles_colors;
			m_buffer_pixles_symboles = m_buffer_pixles_colors = nullptr;
			m_width = m_height = 0;
		}
		// Add to Sprite
		void Add_Sprite(const GSprite& sprite)
		{
			m_Sprites.emplace_back(sprite);
		}
		// Sort Sprite Array
		void Sort_Sprites_Array()
		{
			for (size_t i { 0 }; i < m_Sprites.size(); ++i)
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
			}
		}
		// Set pixels buffer based on sorted sprite array
		void Fill_Pixels_Symboles()
		{
			for (auto& res : m_Sprites)
			{
				int counter { 0 };
				for (auto& symb : res.Get_Symboles_Array())
				{
					m_buffer_pixles_symboles[counter] = symb;
					++counter;
				}
			}
		}
		void Fill_Pixels_Color()
		{
			for (auto& res : m_Sprites)
			{
				int counter { 0 };
				for (auto& color : res.Get_Colors_Array())
				{
					m_buffer_pixles_colors[counter] = color;
					++counter;
				}
			}
		}
		// Get pixles buffer
		short* Get_Buffer_Symboles_Array()
		{
			return m_buffer_pixles_symboles;
		}
		
		short* Get_Buffer_Color_Array()
		{
			return m_buffer_pixles_colors;
		}
		std::vector<GSprite> Get_Sprites()
		{
			if (m_Sprites.size() > 0)
				return m_Sprites;
			return {};
		}

		// Correct empty pixles and get all thing to gether and send to GRendere
		void Currect_Empty_Index_Buffer()
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

	private:
		std::vector<GSprite> m_Sprites {};
		short* m_buffer_pixles_symboles { nullptr };
		short* m_buffer_pixles_colors { nullptr };
		s_uint m_width {};
		s_uint m_height {};
	};
}
