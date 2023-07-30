#pragma once
namespace AE
{
	class GSprite
	{
		using ushort = unsigned short;
		using s_uint = unsigned int;

	public:
		GSprite() = default;
		GSprite(s_uint w, s_uint h, AE::GVector::Point2D&& pos);
		GSprite(const std::string_view& str, s_uint w, s_uint h, AE::GVector::Point2D&& pos);
		template <size_t size>
		GSprite(const std::string_view& str, std::array<short, size> color, s_uint w, s_uint h, AE::GVector::Point2D&& pos) : m_width { w }, m_height { h }, m_sprite_position { pos }
		{
			Generate_Unique_Id();
			Init_Pixels(w, h);
			Set_Sprite_Pixels_With_String<size>(str, color);
		}
		~GSprite();

		void Set_Sprite_Pixel(ushort x, ushort y, short character, short color);
		void Set_Sprite_Pixels(ushort x, ushort y, int count, short character, short color);
		template <std::size_t size>
		void Set_Sprite_Pixels_With_String(const std::string_view& str, std::array<short, size>& color)
		{
			// for (const auto &ch : str)
			for (size_t y { 0 }; y < m_height; ++y)
				for (size_t x { 0 }; x < m_width; ++x)
				{
					Set_Sprite_Pixel(x, y, str.at(AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)),
									 color.at(AE::GPuzzle::GHelper::Whatis_index(m_width, x, y)));
					// Set_Sprite_Pixel(i, j, ch, color.at(j + size * i));
				}
		}
		void Set_Sprite_Pixels_With_String(const std::string_view& str);
		short Get_Sprite_Symbole(ushort x, ushort y);
		short Get_Sprite_Color(ushort x, ushort y);

		inline std::vector<short>& Get_Symboles_Array()
		{
			return m_pixles_symbole;
		}
		inline std::vector<short>& Get_Colors_Array()
		{
			return m_pixles_color;
		}

		const inline AE::GVector::Point2D& Get_Sprite_Position()
		{
			return m_sprite_position;
		}
		inline s_uint Get_Sprite_Width()
		{
			return m_width;
		}
		inline s_uint Get_Sprite_Hight()
		{
			return m_height;
		}
	private:
		bool Not_OutofBounds(ushort x, ushort y);
		void Init_Pixels(s_uint width, s_uint height);
		void Clear_Pixels();

		static std::size_t Generate_Unique_Id()
		{
			return m_Sprite_ID++;
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