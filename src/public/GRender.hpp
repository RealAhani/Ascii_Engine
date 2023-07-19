#pragma once

namespace A_E
{
	class Frame_Setting;
	namespace GPuzzle::GInput
	{
		struct Keyboard_Value;
	}
	enum class ERenderRow:unsigned char
	{
		Header=0,
		Body,
		Fotter
	};
	class GRender
	{
	private:
		static inline std::string m_header_buffer {};
		static inline std::string m_body_buffer {};
		static inline std::string m_footer_buffer {};
	public:
		GRender() = default;
		~GRender() = default;

		static A_E::GPuzzle::GInput::Keyboard_Value s_pressedkey;
		static void Draw(const int Delta_time);
		static bool Add_to_buffer(const char* str,const A_E::ERenderRow &&render_row);
		static bool Clean_buffer();
	private:
		static void Clean();
		static void Render_game_details(const int Delta_time);
		/// info that we see in first line of the consol is Header
		static void Draw_Header(const int Delta_time);

		/// main buffer drawe for Game rendering is Body
		static void Draw_Body(const int Delta_time);

		/// the last line in the screen after body can start to draw
		static void Draw_footer(const int Delta_time);
	};
}
