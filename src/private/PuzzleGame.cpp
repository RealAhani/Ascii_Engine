#include "Engine_PCH.hpp"
#include "PuzzleGame.hpp"

AE::PuzzleGame::PuzzleGame() :Is_GameOver{ false }
{
}
AE::PuzzleGame::~PuzzleGame()
{
}
bool AE::PuzzleGame::Get_GameOver()const
{
	return Is_GameOver;
}
void AE::PuzzleGame::Update_GameState(const double time)const
{
	
}
void AE::PuzzleGame::Move_H(int val)
{
	//LOG(val);
}
void AE::PuzzleGame::Move_V(int val)
{
	//LOG(val);
}