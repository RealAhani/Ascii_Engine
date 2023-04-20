#include "Puzzle_PCH.hpp"
#include "GameInit.hpp"
#include "GRender.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"
GameInit::GameInit()
{}
GameInit::~GameInit() 
{}
int GameInit::Initilize_Game(const PuzzleGame& game)
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

void GameInit::Start_Game(const PuzzleGame& game)
{
	GTimer benchmark_game_time{};
	int _DeltaTime{0};
	GTimer::Start_Global_Timer();

	while (!Get_GameOver(game))
	{
		benchmark_game_time.Start_Time();
		//get input
		GRender::Draw(_DeltaTime);
		Update_GameState(game, _DeltaTime);

		benchmark_game_time.End_Time();
		_DeltaTime = benchmark_game_time.Get_DeltaTime()*2;
		//if vsync =on for 10fps
		//_DeltaTime =100;
		Pause_thread(_DeltaTime);
	}
}
void GameInit::Pause_thread(const int Delta_time)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(Delta_time)));
}
void GameInit::Update_GameState(const PuzzleGame& game, const int Delta_time)
{
	game.Update_GameState(Delta_time);
}
bool GameInit::Get_GameOver(const PuzzleGame& game)
{
	return  game.Get_GameOver();
}