#include "Puzzle_PCH.hpp"
#include "GameInit.hpp"
#include "PuzzleGame.hpp"
#include "Fram.hpp"

int main(int argc, char** argv)
{
	PuzzleGame game{};
	int code=GameInit::Initilize_Game(game);
	LOG_CODE(code);

	WAIT();
	return 0;
}
//random
//input
//map
//array puzzle