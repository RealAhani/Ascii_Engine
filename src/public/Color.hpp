///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
namespace AE
{
	namespace Color
	{
		
		//color ansi code link= https://en.wikipedia.org/wiki/ANSI_escape_code#Terminal_output_sequences
		enum Code
		{
			FG_RED = 31,
			FG_GREEN = 32,
			FG_BLUE = 34,
			FG_BLACK = 30,
			FG_YELLOW = 33,
			FG_MAGENTA = 35,
			FG_CYAN = 36,
			FG_WHITE = 37,
			FG_GREY = 90,
			FG_BRIGHT_RED = 91,
			FG_BRIGHT_GREEN = 92,
			FG_BRIGHT_YELLOW = 93,
			FG_BRIGHT_BLUE = 94,
			FG_BRIGHT_MAGENTA = 95,
			FG_BRIGHT_CYAN = 96,
			FG_BRIGHT_WHITE = 97,
			FG_DEFAULT = 39,

			BG_RED = 41,
			BG_GREEN = 42,
			BG_BLUE = 44,
			BG_BLACK = 40,
			BG_YELLOW = 43,
			BG_MAGENTA = 45,
			BG_CYAN = 46,
			BG_WHITE = 47,
			BG_GREY = 100,
			BG_BRIGHT_RED = 101,
			BG_BRIGHT_GREEN = 102,
			BG_BRIGHT_YELLOW = 103,
			BG_BRIGHT_BLUE = 104,
			BG_BRIGHT_MAGENTA = 105,
			BG_BRIGHT_CYAN = 106,
			BG_BRIGHT_WHITE = 107,
			BG_DEFAULT = 49
		};
		class Modifier
		{
		private:
			Code m_code {};
		public:
			Modifier()
			{
				this->set_color_code(Code::FG_DEFAULT);
			}
			explicit Modifier(Code pCode) : m_code { pCode }
			{
			}
			inline void set_color_code(Code code)noexcept
			{
				m_code = code;
			}
			friend std::ostream& operator<<(std::ostream& os, const Modifier& mod)
			{
				return os << "\033[" << mod.m_code << "m";
			}
			static std::string Create_Color_String(const char& strv, const Modifier& mod)
			{
				std::string temp { "\033[" + std::to_string(mod.m_code) + "m" + strv };
				/// "\033[34m#"
				return temp;
			}
			
		};
		
	}
}