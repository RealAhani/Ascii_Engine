#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "GRender.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"

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
	catch (const std::exception&)
	{
		return 1;
	}
	return 0;
}

void AE::GameInit::Start_Game(const AE::PuzzleGame& game)
{
	AE::GTimer benchmark_game_time{};
	int _DeltaTime{ 0 };
	AE::GTimer::Start_Global_Timer();
	const std::array<AE::GPuzzle::GInput::Keyboard_Value, 4> mykeys{ {{'W',1},{'S',-1},{'A',-1},{'D',1} } };
	World_init();
	
	while (!Get_GameOver(game))
	{
		//TODO we need threads for each primary function
		benchmark_game_time.Start_Time();

		/** TODO: puzzle game whole class name should change name and gave a generic name for inheritance*/
		//get input
		if (AE::GPuzzle::GInput::SendPlayerInput<4>(mykeys, &AE::PuzzleGame::Move_V, &AE::PuzzleGame::Move_H) < 0)
			return;

		//Rendering 
		AE::GRender::Draw(_DeltaTime);

		//gamestate update (tick) for game
		Update_GameState(game, _DeltaTime);

		benchmark_game_time.End_Time();
		_DeltaTime = benchmark_game_time.Get_DeltaTime();
		//if vsync =on for 10fps
		//_DeltaTime =100;
		Pause_thread(_DeltaTime);
	}
}
void AE::GameInit::Pause_thread(const int Delta_time)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(Delta_time)));
}
void AE::GameInit::Update_GameState(const AE::PuzzleGame& game, const int Delta_time)
{
	//TODO change update_gamestate of game memfunc to Tick
	game.Update_GameState(Delta_time);
}
void AE::GameInit::World_init()
{
	//init the map
	AE::GRender::Add_to_buffer("Game is started .... \n", AE::ERenderRow::Body);
	AE::GRender::Add_to_buffer(GPuzzle::prize::You_win.data(), AE::ERenderRow::Body);

	///init character that using on this game and specify each char is what color on screen
	const std::array<char, 7> symbols { '#','.','@','?','/','\\','|' };
	const std::array<Color::Code, 7> colors { Color::FG_BLUE,Color::FG_RED,Color::FG_WHITE ,
		Color::FG_BRIGHT_GREEN,Color::FG_BRIGHT_YELLOW,Color::FG_BLUE,Color::FG_BRIGHT_MAGENTA };
	AE::GRender::init_shapes<7>(symbols, colors);

	//fotter init 
	AE::GRender::Add_to_buffer("\n", AE::ERenderRow::Fotter);
	AE::GRender::Add_to_buffer("\n", AE::ERenderRow::Fotter);
	AE::GRender::Add_to_buffer("Press Scape for Exit .... \n", AE::ERenderRow::Fotter);
}
bool AE::GameInit::Get_GameOver(const AE::PuzzleGame& game)
{
	return  game.Get_GameOver();
}