#pragma once
class PuzzleGame {
private:
	bool Is_GameOver{};
	bool Win_Condition();
public:
	PuzzleGame(/* args */) :Is_GameOver{ false }
	{
	}
	~PuzzleGame() {}
	bool Get_GameOver()const { return Is_GameOver; }
	void Update_GameState(const double time)const{}
};

