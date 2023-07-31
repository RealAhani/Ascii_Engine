#include "Engine_PCH.hpp"
#include "GameInit.hpp"
#include "PuzzleGame.hpp"

///mem leak preprosesor only for msvc++
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
///mem leak preprosesor only for msvc++

int main(int argc, char** argv)
{
#ifdef _DEBUG
	//this is show mem leak if its on debug
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // DEBUG

	
	//A_E stands for Ascii Engine
	using namespace AE;
	PuzzleGame game{};
	int code = GameInit::Initilize_Game(game);
	LOG_CODE(code);

	WAIT();
	return 0;
}
//AI
//network
//audio
