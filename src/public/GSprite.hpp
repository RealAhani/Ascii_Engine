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
			Init_Pixelse(w, h);
		}
		~GSprite()
		{
			Clear_Pixels();
		}
		short Get_Sprite_Pixels(ushort x, ushort y)
		{
			// return the m_pixels cordinate at this x and y
		}
		void Set_Sprite_Pixel(ushort x, ushort y, short character, short color)
		{
			// set 1 pixle with  this character and this color at this x and y
		}
		void Set_Sprite_Pixels(ushort x, ushort y, int count, short character, short color)
		{
			// set pixles with spesific count to this character and this color at this x and y
		}

		void Init_Pixelse(s_uint width, s_uint height)
		{
			m_pixles_symbole = new short(width * height);
			m_pixles_color = new short(width * height);
		}
		void Clear_Pixels()
		{
			delete m_pixles_symbole;
			delete m_pixles_color;
			m_pixles_symbole = m_pixles_color = nullptr;
			m_width = m_height = 0;
		}

		[[__maybe_unused]] static std::size_t Generate_Unique_Id()
		{
			return m_Sprite_ID++;
		}

	private:
		short* m_pixles_symbole { nullptr };
		short* m_pixles_color { nullptr };
		s_uint m_width {};
		s_uint m_height {};
		s_uint m_Sprite_X {};
		s_uint m_Sprite_Y {};
		static inline std::size_t m_Sprite_ID {};
	};
}