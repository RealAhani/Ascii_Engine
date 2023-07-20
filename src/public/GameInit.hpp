#pragma once
namespace A_E
{
	class PuzzleGame;
	class GRender;
	class Frame_Setting;
	class GameInit {
	public:
		GameInit();
		~GameInit();
		static int Initilize_Game(const A_E::PuzzleGame& game);
		static void Start_Game(const A_E::PuzzleGame& game);
		static void Pause_thread(const int Delta_time);
		static void Update_GameState(const A_E::PuzzleGame& game, const int Delta_time);
		static void World_init();
	private:
		GameInit(const A_E::GameInit& gi) = delete;
		static bool Get_GameOver(const A_E::PuzzleGame& game);
	};
}