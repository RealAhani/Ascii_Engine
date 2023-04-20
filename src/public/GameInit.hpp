#pragma once
class GRender;
class PuzzleGame;
class Frame_Setting;
class GameInit {
public:
	GameInit();
	~GameInit();
	static int Initilize_Game(const PuzzleGame& game);
	static void Start_Game(const PuzzleGame& game);
	static void Pause_thread(const int Delta_time);
	static void Update_GameState(const PuzzleGame& game, const int Delta_time);
private:
	GameInit(const GameInit& gi) = delete;
	static bool Get_GameOver(const PuzzleGame& game);
};

