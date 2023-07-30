#include "Engine_PCH.hpp"
#include "GRender.hpp"
#include "Fram.hpp"
#include "GWindow.hpp"
//definition of a test static struct mem for know wich key with wich value is pressed (debugging perpuse)
AE::GPuzzle::GInput::Keyboard_Value AE::GRender::s_pressedkey {};

void AE::GRender::Draw(const int Delta_time)
{
	//clean the frame 
	Clean();
	//Render the game
	Render_game_details(Delta_time);
}
bool AE::GRender::Add_to_buffer(std::string&& str, const AE::ERenderRow&& render_row)
{
	if (str.size()==0)
		return false;
	switch (render_row)
	{
		case ERenderRow::Header:

			m_header_buffer += str;
			break;
		case ERenderRow::Body:
			//m_body_buffer += String_analyzer(str);
			m_body_buffer += str;
			break;
		case ERenderRow::Fotter:
			m_footer_buffer += str;
			break;
	}
	return true;
}
std::string& AE::GRender::String_analyzer(std::string& str)
{
	for (std::size_t i{0};i<str.size();++i)
	{
		for (const auto& res : m_shapes)
		{
			if (res.symbole == str.at(i))
			{
				std::string test = AE::Color::Modifier::Create_Color_String(str.at(i), *res.m_color_code_FG.get()).data();
				str=str.replace(i,1,test);
	//for some reason after we replace the specific char with a string coler code the size increase to 6===> char +5 so this 5 is for extera added length
				i += 5;
			}
		}
	}
	return str;
}
bool AE::GRender::Clean_buffer()
{
	///just body is important for cleaning buffer
	if (m_body_buffer.size() > 0)
	{
		m_header_buffer.clear();
		m_body_buffer.clear();
		m_footer_buffer.clear();
		return true;
	}
	return false;
}

void AE::GRender::Log_based_on_shapes()
{

	/*for (const auto& chr : m_body_buffer)
	{
		for (const auto& res : m_shapes)
		{
			if (res.symbole == chr)
				FGCOLOR(*res.m_color_code_FG.get());
		}
	}*/
		//LOG(m_body_buffer);
}
void AE::GRender::Render_game_details(const int Delta_time)
{
	//Header 
	Draw_Header(Delta_time);
	//Body
	Draw_Body(Delta_time);
	//footer
	Draw_footer(Delta_time);
}
void AE::GRender::Clean()
{
	//CLS();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0,0 });
}

void AE::GRender::Draw_Header(const int Delta_time)
{
	//BGCOLOR(Color::Modifier { Color::BG_DEFAULT });
	//FGCOLOR(Color::Modifier { Color::FG_BLUE });
	//LOG("Game Timer: ");
	//LOG(GTimer::Get_Global_ElapsedTime());
	//LOG("  ");
	//LOG("  ");
	//FGCOLOR(Color::Modifier { Color::FG_BRIGHT_YELLOW });
	//LOG(s_pressedkey.key);
	//LOG(s_pressedkey.value);
	//LOG("  ");
	//FGCOLOR(Color::Modifier { Color::FG_RED });
	//LOG("FPS: ");
	/*LOG(Frame_Setting::Get_FPS(Delta_time));
	LOG(" Latency(ms): ");
	LOG_N(Delta_time);*/
	//FGCOLOR(Color::Modifier { Color::FG_GREEN });
	m_header_buffer = "Game Timer: " + std::to_string(GTimer::Get_Global_ElapsedTime()) + "    " + s_pressedkey.key + std::to_string(s_pressedkey.value)
		+ "  " + "FPS: " + std::to_string(Frame_Setting::Get_FPS(Delta_time)) + " Latency(ms): " + std::to_string(Delta_time);
}

void AE::GRender::Draw_Body(const int Delta_time)
{
	/*FGCOLOR(Color::Modifier { Color::FG_BRIGHT_CYAN });
	LOG(m_body_buffer);*/
	//Log_based_on_shapes();
	//LOG(m_body_buffer);
	m_header_buffer += m_body_buffer;
	GWindow::WriteOnConsole(m_header_buffer,COORD{1,0});
}

void AE::GRender::Draw_footer(const int Delta_time)
{
	/*FGCOLOR(Color::Modifier { Color::FG_BRIGHT_RED });
	LOG(m_footer_buffer);*/
}
