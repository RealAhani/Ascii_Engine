#pragma once
namespace AE
{
	class PuzzleGame;
	class GRender;
	class Frame_Setting;
	class GameInit {
	public:
		GameInit();
		~GameInit();
		static int Initilize_Game(const AE::PuzzleGame& game);
		static void Start_Game(const AE::PuzzleGame& game);
		static void Pause_thread(const int Delta_time);
		static void Update_GameState(const AE::PuzzleGame& game, const int Delta_time);
		static void World_init();
	private:
		GameInit(const AE::GameInit& gi) = delete;
		static bool Get_GameOver(const AE::PuzzleGame& game);
	};
}