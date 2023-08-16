///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#include "PuzzleGame.hpp"
#include "GWorld.hpp"
AE::PuzzleGame::PuzzleGame() :Is_GameOver { false }
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