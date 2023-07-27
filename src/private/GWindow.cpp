#include "Engine_PCH.hpp"
#include "GWindow.hpp"
#include "GRender.hpp"
namespace AE
{
	void GWindow::CreateWin(const std::wstring& win_name, int win_w, int win_h, int font_w, int font_h)
	{
		GRender::m_body_buffer.resize(win_w * win_h);
		m_win = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleActiveScreenBuffer(m_win);
		SMALL_RECT rect { 0, 0, ( short )(win_w - 1), ( short )(win_h - 1) };
		SetConsoleWindowInfo(m_win, TRUE, &rect);
		SetWinFont(font_w, font_h);
		SetConsoleMode(m_win, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		Fbuffersize win_buffer_size = { ( short )win_w, ( short )win_h };
		SetBufferWinConsole(win_buffer_size.buffer_w, win_buffer_size.buffer_h);
		SetWinCharInfo(win_w * win_h);
		wchar_t s[25];
		swprintf_s(s, 25, L"AE - %s ", win_name.c_str());
		SetConsoleTitle(s);
	}

	void GWindow::SetWinCharInfo(int size)
	{
		m_buffscreen = new CHAR_INFO[size];
	}

	void GWindow::SetWinFont(int fw, int fh)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = fw;
		cfi.dwFontSize.Y = fh;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		SetCurrentConsoleFontEx(m_win, false, &cfi);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(m_win, &csbi);
	}

	void GWindow::SetBufferWinConsole(short buffer_w, short buffer_h)
	{
		m_Buffer_size = { buffer_w, buffer_h };
	}

	void GWindow::WriteOnConsole(const std::string & buffer,COORD line_to_start_rendering)
	{
		SMALL_RECT srctWriteRect;
		srctWriteRect.Right = m_Buffer_size.X;
		srctWriteRect.Left = 0;
		srctWriteRect.Top = 0;
		srctWriteRect.Bottom = m_Buffer_size.Y;
		SetConsoleThem(EConsoleColor::BG_BLACK, EConsoleColor::FG_CYAN, buffer);
		WriteConsoleOutput(m_win, m_buffscreen, m_Buffer_size, { 0,0}, &srctWriteRect);
	}

	void GWindow::SetConsoleThem(const EConsoleColor& Background_color, const EConsoleColor& Forground_color ,const std::string& buffer)
	{
		for (size_t i { 0 }; i < buffer.size(); ++i)
			m_buffscreen[i].Attributes = static_cast< WORD >(Background_color) | static_cast< WORD >(Forground_color);
		InitconsoleCharacter(buffer.size(), buffer);
	}

	void GWindow::InitconsoleCharacter(const size_t buffersize, const std::string& buffer)
	{
		for (size_t i { 0 }; i < buffersize; ++i)
			m_buffscreen[i].Char.UnicodeChar = buffer.at(i);
	}

}