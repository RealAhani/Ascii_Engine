#include "Engine_PCH.hpp"
#include "PuzzleGame.hpp"

A_E::PuzzleGame::PuzzleGame() :Is_GameOver{ false }
{
}
A_E::PuzzleGame::~PuzzleGame()
{
}
bool A_E::PuzzleGame::Get_GameOver()const
{
	return Is_GameOver;
}
void A_E::PuzzleGame::Update_GameState(const double time)const
{
	
}
void A_E::PuzzleGame::Move_H(int val)
{
	//LOG(val);
}
void A_E::PuzzleGame::Move_V(int val)
{
	//LOG(val);
}