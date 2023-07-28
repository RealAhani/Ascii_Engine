#pragma once
namespace AE
{
	class GSprite
	{
		using ushort = unsigned short;
		using s_uint = unsigned int;

	public:
		GSprite() = default;
		GSprite(s_uint w, s_uint h)
		{
			Generate_Unique_Id();
			Init_Pixels(w, h);
		}
		~GSprite()
		{
			Clear_Pixels();
		}

		void Set_Sprite_Pixel(ushort x, ushort y, short character, short color)
		{
			// set 1 pixle with  this character and this color at this x and y
			if (Not_OutofBounds(x, y))
			{
				m_pixles_symbole[AE::GPuzzle::GHelper::Whatis_index(m_width,x,y)] = character;
				m_pixles_color[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)] = color;
			}
		}
		void Set_Sprite_Pixels(ushort x, ushort y, int count, short character, short color)
		{
			// set pixles with spesific count to this character and this color at this x and y
			if (Not_OutofBounds(x, y))
			{
				for (size_t i = 0; i < count; ++i)
				{
					m_pixles_symbole[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y) + i] = character;
					m_pixles_color[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y) + i] = color;
				}
			}
		}
		bool Not_OutofBounds(ushort x, ushort y)
		{
			if (x >= 0 and x <= m_width and y >= 0 and y <= m_height)
				return true;
			return false;
		}
		void Init_Pixels(s_uint width, s_uint height)
		{
			m_pixles_symbole.reserve(width * height);
			m_pixles_symbole.resize(width * height);
			m_pixles_color.reserve(width * height);
			m_pixles_color.resize(width * height);
		}
		void Clear_Pixels()
		{
			m_pixles_symbole.clear();
			m_pixles_color.clear();
			m_width = m_height = 0;
		}

		[[__maybe_unused]] static std::size_t Generate_Unique_Id()
		{
			return m_Sprite_ID++;
		}
		std::vector<short> Get_Symboles_Array()
		{
			if (m_pixles_symbole.size() > 0)
				return m_pixles_symbole;
			return {};
		}
		std::vector<short> Get_Colors_Array()
		{
			if (m_pixles_color.size() > 0)
				return m_pixles_color;
			return {};
		}
		short Get_Sprite_Symbole(ushort x, ushort y)
		{
			if (Not_OutofBounds(x, y))
			{
				return m_pixles_symbole[x * m_width + y];
			}
			return 0;
			// return the m_pixels cordinate at this x and y
		}
		short Get_Sprite_Color(ushort x, ushort y)
		{
			if (Not_OutofBounds(x, y))
			{
				return m_pixles_color[x * m_width + y];
			}
			return 0;
			// return the m_pixels cordinate at this x and y
		}
		const AE::GVector::Point2D& Get_Sprite_Position()
		{
			return m_sprite_position;
		}

	private:
		std::vector<short> m_pixles_symbole {};
		std::vector<short> m_pixles_color {};
		s_uint m_width {};
		s_uint m_height {};

		AE::GVector::Point2D m_sprite_position {};
		static inline std::size_t m_Sprite_ID {};
	};
}