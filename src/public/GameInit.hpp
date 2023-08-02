///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
namespace AE
{
	class PuzzleGame;
	class GameInit
	{
	public:
		GameInit();
		~GameInit();
		static int Initilize_Game(const AE::PuzzleGame& game);
		static void Start_Game(const AE::PuzzleGame& game);
		static void Pause_thread(const int Delta_time);
		static void Update_GameState(const AE::PuzzleGame& game, const int Delta_time);
		static void World_init();
		static void Renderer_init();
		static void Levels_init();
	private:
		static inline int m_DeltaTime { 0 };
		GameInit(const AE::GameInit& gi) = delete;
		static bool Get_GameOver(const AE::PuzzleGame& game);
		static void Init_window(const std::wstring& win_name, int window_width, int window_heigth, int font_w, int font_h);
	};
}