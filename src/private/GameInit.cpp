#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "GRender.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"



A_E::GameInit::GameInit()
{
}
A_E::GameInit::~GameInit()
{
}
int A_E::GameInit::Initilize_Game(const A_E::PuzzleGame& game)
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

void A_E::GameInit::Start_Game(const A_E::PuzzleGame& game)
{
	A_E::GTimer benchmark_game_time{};
	int _DeltaTime{ 0 };
	A_E::GTimer::Start_Global_Timer();
	const std::array<A_E::GPuzzle::GInput::Keyboard_Value, 4> mykeys{ {{'W',1},{'S',-1},{'A',-1},{'D',1} } };
	while (!Get_GameOver(game))
	{
		//TODO we need threads for each primary function
		benchmark_game_time.Start_Time();

		//TODO puzzle game whole class name should change name and gave a generic name for inheritance
		//get input
		A_E::GPuzzle::GInput::SendPlayerInput<4>(mykeys, &A_E::PuzzleGame::Move_V, &A_E::PuzzleGame::Move_H);

		//Rendering 
		A_E::GRender::Draw(_DeltaTime);

		//gamestate update (tick) for game
		Update_GameState(game, _DeltaTime);

		benchmark_game_time.End_Time();
		_DeltaTime = benchmark_game_time.Get_DeltaTime() * 2;
		//if vsync =on for 10fps
		//_DeltaTime =100;
		Pause_thread(_DeltaTime);
	}
}
void A_E::GameInit::Pause_thread(const int Delta_time)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(Delta_time)));
}
void A_E::GameInit::Update_GameState(const A_E::PuzzleGame& game, const int Delta_time)
{
	//TODO change update_gamestate of game memfunc to Tick
	game.Update_GameState(Delta_time);
}
bool A_E::GameInit::Get_GameOver(const A_E::PuzzleGame& game)
{
	return  game.Get_GameOver();
}