#include "Engine_PCH.hpp"
#include "GInput.hpp"

//#include "PuzzleGame.hpp"


template<size_t size>
void A_E::GPuzzle::GInput::Input_Init(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, size>& keys)
{
	//sendinput(keys, &H_Move);
}

//TO DO 
//this func should give 2 axis key functor (fptr) one for up/down and second for right/left
//template <>
//void  A_E::GPuzzle::GInput::SendPlayerInput(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, 4>& keys,
//	void(A_E::PuzzleGame::* move_v)(int), void(A_E::PuzzleGame::* move_h)(int))
//{
//	A_E::PuzzleGame gm;
//	if (GetAsyncKeyState(VK_ESCAPE))
//		// game_over = true;
//		for (auto& i : keys)
//		{
//			if (GetAsyncKeyState(i.key))
//			{
//				//new code
//				if (i.key == A_E::GPuzzle::GInput::UP || i.key == A_E::GPuzzle::GInput::up
//					|| i.key == A_E::GPuzzle::GInput::DOWN || i.key == A_E::GPuzzle::GInput::down)
//					(gm.*move_v)(i.value);
//				else if (i.key == A_E::GPuzzle::GInput::RIGHT || i.key == A_E::GPuzzle::GInput::right
//					|| i.key == A_E::GPuzzle::GInput::LEFT || i.key == A_E::GPuzzle::GInput::left)
//					(gm.*move_h)(i.value);
//				//old code has just this part and no gaigantic if and else if
//				//input_fptr(i.value);
//				return;
//			}
//		}
//	(gm.*move_v)(0);
//	(gm.*move_h)(0);
//	/*input_fptr(0);*/
//}