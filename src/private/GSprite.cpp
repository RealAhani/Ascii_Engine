#include "Engine_PCH.hpp"
#include "GSprite.hpp"
namespace AE
{
	GSprite::GSprite(s_uint w, s_uint h, AE::GVector::Point2D&& pos) : m_width { w }, m_height { h }, m_sprite_position { pos }
	{
		Generate_Unique_Id();
		Init_Pixels(w, h);
	}
	GSprite::GSprite(const std::string_view& str, s_uint w, s_uint h, AE::GVector::Point2D&& pos) : m_width { w }, m_height { h }, m_sprite_position { pos }
	{
		Generate_Unique_Id();
		Init_Pixels(w, h);
		Set_Sprite_Pixels_With_String(str);
	}
	GSprite::~GSprite()
	{
		Clear_Pixels();
	}

	void GSprite::Set_Sprite_Pixel(ushort x, ushort y, short character, short color)
	{
		// set 1 pixle with  this character and this color at this x and y
		if (Not_OutofBounds(x, y))
		{
			m_pixles_symbole[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)] = character;
			m_pixles_color[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)] = color;
		}
	}
	void GSprite::Set_Sprite_Pixels(ushort x, ushort y, int count, short character, short color)
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

	void GSprite::Set_Sprite_Pixels_With_String(const std::string_view& str)
	{
		// for (const auto &ch : str)
		for (size_t y { 0 }; y < m_height; ++y)
			for (size_t x { 0 }; x < m_width; ++x)
			{
				Set_Sprite_Pixel(x, y, str.at(AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)), 0x001);
			}
	}
	bool GSprite::Not_OutofBounds(ushort x, ushort y)
	{
		if (x >= 0 and x <= m_width and y >= 0 and y <= m_height)
			return true;
		return false;
	}
	void GSprite::Init_Pixels(s_uint width, s_uint height)
	{
		m_pixles_symbole.reserve(width * height);
		m_pixles_symbole.resize(width * height);
		m_pixles_color.reserve(width * height);
		m_pixles_color.resize(width * height);
	}
	void GSprite::Clear_Pixels()
	{
		m_pixles_symbole.clear();
		m_pixles_color.clear();
		m_width = m_height = 0;
	}

	short GSprite::Get_Sprite_Symbole(ushort x, ushort y)
	{
		if (Not_OutofBounds(x, y))
		{
			return m_pixles_symbole[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)];
		}
		return 0;
		// return the m_pixels cordinate at this x and y
	}
	short GSprite::Get_Sprite_Color(ushort x, ushort y)
	{
		if (Not_OutofBounds(x, y))
		{
			return m_pixles_color[AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)];
		}
		return 0;
		// return the m_pixels cordinate at this x and y
	}
}