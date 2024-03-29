#include "GameInit.hpp"
#include "PuzzleGame.hpp"
#include "osconfig.h"

/// mem leak preprosesor only for msvc++
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif
/// mem leak preprosesor only for msvc++

int main(int argc, char *argv[])
{
#if (OS == 1)
#ifdef _DEBUG
    // this is show mem leak if its on debug
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // DEBUG

    // A_E stands for Ascii Engine
    using namespace AE;
    PuzzleGame game{};
    int code = GameInit::Initilize_Game(game);
    LOG_CODE(code);

    WAIT();

#elif (OS == 2)
    mloge::print("LINUX");
#elif (OS == 3)
    mloge::print("MAC");
#endif
    std::cin.get();
    return 0;
}
/// TODO
///  A. (PROBLEM) BUFFER HAS AN ARRAY OF SPRITE => SHOUT ADD SPRITE JUST ONE TIME IF ITS EMPTY (CURRENT STATE IS ADD AND REMOVE EVERY FRAME) ...IT CAN BE DONE WITH OBSERVER DP
///  B. (SOLUTION) SPRITE ADD IN INIT_WORLD METHOS THEN UPDATE THEIR STATE IN TICK (LOOP)=>NEED OBSERVER PATTERN
///  C. ADD ONLY COLOR SPRITE OR CHOSING OPTION FOR CREATE ASCII AND PIXLE (COLOR ONLY) WITH HIGHER RESOLUTION ===>CHANGING LOAD CHAR_INFO PTR WITH
///  INTERPRET ASCII SYMBOL TO DESIRE PIXLE COLOR IT MEAN WE SPECIFY SOME SYMBOLE TO BE AND SPECIFIC COLOR THEN WE JUDGE WICH INDEX OF BUFFER SHOULD BE WICH COLOR
///  BASED ON THE SPRITE SYMBOLES //E.G (#) IS WHITE ;(!) IS BLUE ; ETC ...
///  D.ADD BETTER COMENTING AND DOCUMENTATION
///  F.BETTER DOCUMENTATION
///  E.BUILD SYSTEM SUPPORT (CMAKE)
///  G.
///
///  1. DELETE RAW POINTER AND REPLACE THEM WHIT SMART POINTERS
///  2. REWORK ON INPUT HANDLING WITH BETTER DP
///  3. CREATE ENTITY COMPONENT SYSTEM
///  4. CREATE BETTER ENTRY POINT AND MICRO DLLEXPORT
///  5. EVENT SYSTEM FOR COLLISION DETECTION AND ETC...
///  6. ADDING DIFFRENT TYPE OF COLLISION DETECTION ALGO LIKE A.A.B.B
///  7. distingushing threading
/// AI PATH FINDING A STAR AND DIGSTRA
/// audio FOR MUSIC
///  SPRITE EDITORE AND SAVE AND LOAD SPRITE WITH PIXLE DRAWING
/// network support
