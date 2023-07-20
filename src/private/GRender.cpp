#include "Engine_PCH.hpp"
#include "GRender.hpp"
#include "Fram.hpp"

//definition of a test static struct mem for know wich key with wich value is pressed (debugging perpuse)
AE::GPuzzle::GInput::Keyboard_Value AE::GRender::s_pressedkey {};

void AE::GRender::Draw(const int Delta_time)
{
	//clean the frame 
	Clean();
	//Render the game
	Render_game_details(Delta_time);
}
bool AE::GRender::Add_to_buffer(const char* str, const AE::ERenderRow&& render_row)
{
	if (str == nullptr)
		return false;
	switch (render_row)
	{
		case ERenderRow::Header:
			m_header_buffer += str;
			break;
		case ERenderRow::Body:
			m_body_buffer += str;
			break;
		case ERenderRow::Fotter:
			m_footer_buffer += str;
			break;
	}
	return true;
}
bool AE::GRender::Clean_buffer()
{
	if (m_body_buffer.size() > 0
		and m_footer_buffer.size() > 0)
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

	for (const auto& chr : m_body_buffer)
	{
		for (const auto& res : m_shapes)
		{
			if (res.symbole == chr)
				FGCOLOR(*res.m_color_code_FG.get());
		}
		LOG(chr);
	}
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
	CLS();
}

void AE::GRender::Draw_Header(const int Delta_time)
{
	BGCOLOR(Color::Modifier { Color::BG_DEFAULT });
	FGCOLOR(Color::Modifier { Color::FG_BLUE });
	LOG("Game Timer: ");
	LOG(GTimer::Get_Global_ElapsedTime());
	LOG("  ");
	LOG("  ");
	FGCOLOR(Color::Modifier { Color::FG_BRIGHT_YELLOW });
	LOG(s_pressedkey.key);
	LOG(s_pressedkey.value);
	LOG("  ");
	FGCOLOR(Color::Modifier { Color::FG_RED });
	LOG("FPS: ");
	LOG(Frame_Setting::Get_FPS(Delta_time));
	LOG(" Latency(ms): ");
	LOG_N(Delta_time);
	FGCOLOR(Color::Modifier { Color::FG_GREEN });

	LOG(m_header_buffer);
}

void AE::GRender::Draw_Body(const int Delta_time)
{
	/*FGCOLOR(Color::Modifier { Color::FG_BRIGHT_CYAN });
	LOG(m_body_buffer);*/
	Log_based_on_shapes();
}

void AE::GRender::Draw_footer(const int Delta_time)
{
	FGCOLOR(Color::Modifier { Color::FG_BRIGHT_RED });
	LOG(m_footer_buffer);
}
