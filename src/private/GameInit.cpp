#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "GRender.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"
#include "GWorld.hpp"


AE::GameInit::GameInit()
{
}
AE::GameInit::~GameInit()
{
}
int AE::GameInit::Initilize_Game(const AE::PuzzleGame& game)
{
	try
	{
		Start_Game(game);
	}
	catch (const std::exception& e)
	{
		LOG(e.what());
		return 1;
	}
	return 0;
}

void AE::GameInit::Start_Game(const AE::PuzzleGame& game)
{
	Init_window(260, 150, 10, 18);

	///init Timer and Time for using Delta time and FPS usage and thread Sleep
	AE::GTimer benchmark_game_time {};
	AE::GTimer::Start_Global_Timer();

	///init input keys that should use in the game 
	const std::array<AE::GPuzzle::GInput::Keyboard_Value, 4> mykeys { {{'W',1},{'S',-1},{'A',-1},{'D',1} } };

	World_init();

	while (!Get_GameOver(game))
	{
		///TODO we need threads for each primary function
		benchmark_game_time.Start_Time();

		/** TODO: puzzle game whole class name should change name and gave a generic name for inheritance*/
		///get input
		if (AE::GPuzzle::GInput::SendPlayerInput<4>(mykeys, &AE::PuzzleGame::Move_V, &AE::PuzzleGame::Move_H) < 0)
			return;

		///Rendering 
		AE::GRender::Draw(m_DeltaTime);

		///gamestate update (tick) for game
		Update_GameState(game, m_DeltaTime);

		benchmark_game_time.End_Time();
		m_DeltaTime = benchmark_game_time.Get_DeltaTime();
		///if vsync =on for 10fps
		///_DeltaTime =100;
		Pause_thread(m_DeltaTime);
	}
}
void AE::GameInit::Pause_thread(const int Delta_time)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast< int >(Delta_time)));
}
void AE::GameInit::Update_GameState(const AE::PuzzleGame& game, const int Delta_time)
{
	///TODO change update_gamestate of game memfunc to Tick
	game.Update_GameState(Delta_time);
}
void AE::GameInit::World_init()
{
	///init levels and maps
	Levels_init();

	///init setting for char color rendering
	Renderer_init();

	///fotter init 
	AE::GRender::Add_to_buffer("\n", AE::ERenderRow::Fotter);
	AE::GRender::Add_to_buffer("\n", AE::ERenderRow::Fotter);
	AE::GRender::Add_to_buffer("Press Scape for Exit .... \n", AE::ERenderRow::Fotter);

}
void AE::GameInit::Renderer_init()
{
	///init character that using on this game and specify each char is what color on screen
	const std::array<char, 7> symbols { '#','.','@','?','/','\\','|' };
	const std::array<Color::Code, 7> colors { Color::FG_BLUE,Color::FG_RED,Color::FG_WHITE ,
		Color::FG_BRIGHT_GREEN,Color::FG_BRIGHT_YELLOW,Color::FG_BLUE,Color::FG_BRIGHT_MAGENTA };
	AE::GRender::init_shapes<7>(symbols, colors);
}
void AE::GameInit::Levels_init()
{
	AE::lvl::GLevel m_lvl1, m_lvl2;
	m_lvl1.init_map(GPuzzle::prize::You_win, "You Win");
	m_lvl2.init_map("Hello ", "test");

	const std::array<AE::lvl::GLevel, 2> levels { m_lvl1,m_lvl2 };
	AE::world::GWorld<2>::Init_Game_World()->Init_levels(levels);
}
bool AE::GameInit::Get_GameOver(const AE::PuzzleGame& game)
{
	return  game.Get_GameOver();
}
void AE::GameInit::Init_window(int window_width, int window_heigth, int font_w, int font_h)
{
	HANDLE m_outhandle { GetStdHandle(STD_OUTPUT_HANDLE) };
	HANDLE m_inhandle { GetStdHandle(STD_INPUT_HANDLE) };

	std::wstring win_name { L"ASCII_ENGINE" };

	SMALL_RECT rect_win = { 0,0,( short )window_width,( short )window_heigth };
	SetConsoleWindowInfo(m_outhandle, TRUE, &rect_win);
	COORD coord = { ( short )window_width, ( short )window_heigth };
	SetConsoleScreenBufferSize(m_outhandle, coord);
	SetConsoleActiveScreenBuffer(m_outhandle);

	// Set the font size now that the screen buffer has been assigned to the console
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = font_w;
	cfi.dwFontSize.Y = font_h;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(m_outhandle, false, &cfi);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(m_outhandle, &csbi);

	rect_win = { 0, 0 ,( short )window_width - 1, ( short )window_heigth - 1 };
	SetConsoleWindowInfo(m_outhandle, TRUE, &rect_win);

	SetConsoleMode(m_outhandle, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	CHAR_INFO* m_bufScreen = new CHAR_INFO[window_width * window_heigth];
	memset(m_bufScreen, 0, sizeof(CHAR_INFO) * window_width * window_heigth);

	//Write_win_title(window_width, window_heigth);
	wchar_t s[25];
	swprintf_s(s, 25, L"AE - %s ", win_name.c_str());
	SetConsoleTitle(s);
	WriteConsoleOutput(m_outhandle, m_bufScreen, { ( short )window_width, ( short )window_heigth }, { 0,0 }, &rect_win);
}

