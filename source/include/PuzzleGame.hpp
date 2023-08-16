///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once

namespace AE
{
	class PuzzleGame {
	private:
		bool Is_GameOver{};
		bool Win_Condition{};
	public:

		PuzzleGame(/* args */);
		~PuzzleGame();
		bool Get_GameOver()const;
		void Update_GameState(const double time)const;

		void Move_H(int val);
		void Move_V(int val);
	};
}
	