///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
namespace AE
{
	class GWindow
	{
	public:
		enum class EConsoleColor : WORD
		{
			FG_BLACK = 0x0000,
			FG_DARK_BLUE = 0x0001,
			FG_DARK_GREEN = 0x0002,
			FG_DARK_CYAN = 0x0003,
			FG_DARK_RED = 0x0004,
			FG_DARK_MAGENTA = 0x0005,
			FG_DARK_YELLOW = 0x0006,
			FG_GREY = 0x0007,
			FG_DARK_GREY = 0x0008,
			FG_BLUE = 0x0009,
			FG_GREEN = 0x000A,
			FG_CYAN = 0x000B,
			FG_RED = 0x000C,
			FG_MAGENTA = 0x000D,
			FG_YELLOW = 0x000E,
			FG_WHITE = 0x000F,
			BG_BLACK = 0x0000,
			BG_DARK_BLUE = 0x0010,
			BG_DARK_GREEN = 0x0020,
			BG_DARK_CYAN = 0x0030,
			BG_DARK_RED = 0x0040,
			BG_DARK_MAGENTA = 0x0050,
			BG_DARK_YELLOW = 0x0060,
			BG_GREY = 0x0070,
			BG_DARK_GREY = 0x0080,
			BG_BLUE = 0x0090,
			BG_GREEN = 0x00A0,
			BG_CYAN = 0x00B0,
			BG_RED = 0x00C0,
			BG_MAGENTA = 0x00D0,
			BG_YELLOW = 0x00E0,
			BG_WHITE = 0x00F0,
		};
		struct Fbuffersize
		{
			short buffer_w;
			short buffer_h;
		};
		static void CreateWin(const std::wstring& win_name, int win_w, int win_h, int font_w, int font_h);
		static void SetWinCharInfo(int size);
		static void SetWinFont(int fw, int fh);
		static void SetBufferWinConsole(short buffer_w, short buffer_h);
		static void WriteOnConsole(short* arr_symbole, short* arr_color /*, COORD line_to_start_rendering*/);
		static void SetConsoleThem(short* arr_color);
		static void InitconsoleCharacter(short* arr_symbole);
	private:
		GWindow() = default;
		~GWindow() = default;
		static inline HANDLE m_win;
		static inline COORD m_Buffer_size;
		static inline CHAR_INFO* m_buffscreen;
	};

	///helper class for accesing width and height of the window(rendere,buffer,etc ...) for knowing the size of window staticly
	class GScreen
	{
	public:
		//GScreen() = delete;
		//~GScreen() = delete;

		static void Set_Size(int screen_width, int screen_height)
		{
			m_screen_width = screen_width;

			m_screen_height = screen_height;

		}

		static int Get_with()
		{
			return m_screen_width;
		}
		static int Get_heigth()
		{
			return m_screen_height;
		}
	private:
		static inline int m_screen_width {};
		static inline int m_screen_height {};
	};
}