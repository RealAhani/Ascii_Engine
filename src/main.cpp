#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "PuzzleGame.hpp"

int main(int argc, char** argv)
{
	//A_E stands for Ascii Engine
	using namespace A_E;
	PuzzleGame game{};
	int code = GameInit::Initilize_Game(game);
	LOG_CODE(code);

	WAIT();
	return 0;
}
//random
//input
//map
//array puzzle
