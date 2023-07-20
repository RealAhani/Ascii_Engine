#pragma once
#include "GRender.hpp"

namespace A_E
{
	class PuzzleGame;
	namespace GPuzzle
	{
		namespace GInput
		{
			constexpr auto UP = 'W';
			constexpr auto up = 'w';

			constexpr auto DOWN = 'S';
			constexpr auto down = 's';

			constexpr auto LEFT = 'A';
			constexpr auto left = 'a';

			constexpr auto RIGHT = 'D';
			constexpr auto right = 'd';

			constexpr auto EXIT = 'Q';
			constexpr auto exit = 'q';

			// End defining Inputs

			enum class Direction : uint8_t
			{
				E_up,
				E_down,
				E_left,
				E_right,
				E_Max
			};
			struct Keyboard_Value
			{
				char key {};
				int value {};
			};

			// void Get_key(char ch);
			template<size_t size>
			void Input_Init(const std::array<Keyboard_Value, size>& keys);


			template <size_t size>
			static int SendPlayerInput(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, size>& keys,
									   void(A_E::PuzzleGame::* move_v)(int), void(A_E::PuzzleGame::* move_h)(int))
			{
				A_E::PuzzleGame gm;
				if (GetAsyncKeyState(VK_ESCAPE))
					return -1;
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					A_E::GRender::s_pressedkey.key = 'i';
					A_E::GRender::s_pressedkey.value = 5;
					(gm.*move_v)(5);
					return 1;
				}
				else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT))
				{
					A_E::GRender::s_pressedkey.key = 'i';
					A_E::GRender::s_pressedkey.value = -5;
					(gm.*move_v)(-5);
					return 1;
				}
				for (auto& i : keys)
				{
					if (GetAsyncKeyState(i.key))
					{
						//new code
						if (i.key == A_E::GPuzzle::GInput::UP || i.key == A_E::GPuzzle::GInput::up
							|| i.key == A_E::GPuzzle::GInput::DOWN || i.key == A_E::GPuzzle::GInput::down
							)
						{
							A_E::GRender::s_pressedkey.key = i.key;
							A_E::GRender::s_pressedkey.value = i.value;
							(gm.*move_v)(i.value);
							return 1;
						}
						else if (i.key == A_E::GPuzzle::GInput::RIGHT || i.key == A_E::GPuzzle::GInput::right
								 || i.key == A_E::GPuzzle::GInput::LEFT || i.key == A_E::GPuzzle::GInput::left
								 )
						{
							A_E::GRender::s_pressedkey.key = i.key;
							A_E::GRender::s_pressedkey.value = i.value;
							(gm.*move_h)(i.value);
							return 1;
						}
						//old code has just this part and no gaigantic if and else if
						//input_fptr(i.value);
						return 1;
					}
				}

				A_E::GRender::s_pressedkey.key = 'N';
				A_E::GRender::s_pressedkey.value = 0;
				(gm.*move_v)(0);
				(gm.*move_h)(0);
				return 1;
			}
		}
	}

}