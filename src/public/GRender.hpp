#pragma once
#include<Color.hpp>

namespace AE
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
	struct Shape
	{
		char symbole {'\0'};
		///you should define the color later with set_color_code member function
		std::unique_ptr<Color::Modifier>m_color_code_FG;
	};
	class GRender
	{
	private:
		///buffer for render on terminal that devide the screen to three parts 
		///Header => for detail of the game performance(we can disable it based on build configuration later ...)
		///Body   => for game map and game details
		///Footer => somting for scores ui/hud or etc...
		static inline std::string m_header_buffer {};
		static inline std::string m_body_buffer {};
		static inline std::string m_footer_buffer {};

		///every shape that we can use in the game with ascii rendere and specific color
		static inline std::vector<Shape> m_shapes {};
	public:
		GRender() = default;
		~GRender() = default;

		///Debuger that show on the header of the terminal that wich key is currently pressed
		static AE::GPuzzle::GInput::Keyboard_Value s_pressedkey;
		
		///main function for draw every thing on the screen (terminal)
		static void Draw(const int Delta_time);
		
		///add to specific buffer array like body or header or footer 
		static bool Add_to_buffer(const char* str,const AE::ERenderRow &&render_row);
		
		///clean the all buffer 
		static bool Clean_buffer();

		///fill the array of shapes with each character and color 
		template<std::size_t size>
		static void init_shapes(const std::array<char, size>& symbols, const std::array<Color::Code, size>& colors)
		{
			m_shapes.reserve(size);
			for (size_t i = 0; i < size; i++)
			{
				m_shapes.emplace_back(Shape { .symbole{symbols.at(i)},.m_color_code_FG{std::make_unique<Color::Modifier>(colors.at(i))} });
			}
		}

		///log the shapes with color specifics (IT IS FOR DEBUG)
		static void Log_based_on_shapes();

	private:
		///clean the screen 
		static void Clean();
		///  Call all of the Draw functions
		static void Render_game_details(const int Delta_time);
		/// info that we see in first line of the consol is Header
		static void Draw_Header(const int Delta_time);

		/// main buffer drawe for Game rendering is Body
		static void Draw_Body(const int Delta_time);

		/// the last line in the screen after body can start to draw
		static void Draw_footer(const int Delta_time);
	};
}
