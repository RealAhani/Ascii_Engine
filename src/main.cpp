#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"

int main(int argc, char** argv)
{
	//A_E stands for Ascii Engine
	A_E::PuzzleGame game{};
	int code= A_E::GameInit::Initilize_Game(game);
	LOG_CODE(code);

	WAIT();
	return 0;
}
//random
//input
//map
//array puzzle