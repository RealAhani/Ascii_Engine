#include "Engine_PCH.hpp"
#include "GRender.hpp"
#include "Fram.hpp"

//definition of a test static struct mem for know wich key with wich value is pressed (debugging perpuse)
A_E::GPuzzle::GInput::Keyboard_Value A_E::GRender::s_pressedkey{};


A_E::GRender::GRender()
{
}
A_E::GRender::~GRender()
{
}
void A_E::GRender::Draw(const int Delta_time)
{
	Clean();
	//draw fps
	Show_Game_Detail(Delta_time);

	//draw map
	LOG(GPuzzle::prize::You_win);
	//draw stuff
}
void A_E::GRender::Show_Game_Detail(const int Delta_time)
{
	BGCOLOR(Color::Modifier{ Color::BG_DEFAULT });
	FGCOLOR(Color::Modifier{ Color::FG_BLUE });
	LOG("Game Timer: ");
	LOG(GTimer::Get_Global_ElapsedTime());
	LOG("  ");
	LOG("  ");
	FGCOLOR(Color::Modifier{ Color::FG_BRIGHT_YELLOW });
	LOG(s_pressedkey.key);
	LOG(s_pressedkey.value);
	LOG("  ");
	FGCOLOR(Color::Modifier{ Color::FG_RED });
	LOG("FPS: ");
	LOG(Frame_Setting::Get_FPS(Delta_time));
	LOG(" Latency(ms): ");
	LOG_N(Delta_time);
	FGCOLOR(Color::Modifier{ Color::FG_GREEN });
}
void A_E::GRender::Clean()
{
	CLS();
}