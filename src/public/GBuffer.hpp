#pragma once
namespace AE
{
	class GSprite;
	class GBuffer
	{
		using ushort = unsigned short;
		using s_uint = unsigned int;

	public:
		GBuffer(s_uint width, s_uint height)
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
			m_buffer_pixles_symboles = new short(width * height);
			m_buffer_pixles_colors = new short(width * height);
		}
		void Clear_Buffer()
		{
			delete m_buffer_pixles_symboles;
			delete m_buffer_pixles_colors;
			m_buffer_pixles_symboles = m_buffer_pixles_colors = nullptr;
			m_width = m_height = 0;
		}
		// Add to Sprite

		// Sort Sprite Array

		// Set pixels buffer based on sorted sprite array

		// Get pixles buffer

		// Correct empty pixles and get all thing to gether and send to GRendere

	private:
		std::vector<GSprite> m_Sprites {};
		short* m_buffer_pixles_symboles { nullptr };
		short* m_buffer_pixles_colors { nullptr };
		s_uint m_width {};
		s_uint m_height {};
	};
}
