#pragma once
#include "GRender.hpp"
#include "GWorld.hpp"

namespace AE
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

			constexpr auto VSYNC = 'V';
			constexpr auto vsync = 'v';
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
			static int SendPlayerInput(const std::array<AE::GPuzzle::GInput::Keyboard_Value, size>& keys,
									   void(AE::PuzzleGame::* move_v)(int), void(AE::PuzzleGame::* move_h)(int))
			{
				AE::PuzzleGame gm;
				if (GetAsyncKeyState(VK_ESCAPE))
					return -1;
				if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
				{
					AE::GRender::s_pressedkey.key = 'i';
					AE::GRender::s_pressedkey.value = 5;
					(gm.*move_v)(5);
					return 1;
				}
				/**
				///TODO its for test
				**/
				if(GetAsyncKeyState(VK_RETURN))
					AE::world::GWorld<2>::Go_to_next_level();
				/**
				///TODO its for test
				**/
				else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT))
				{
					AE::GRender::s_pressedkey.key = 'i';
					AE::GRender::s_pressedkey.value = -5;
					(gm.*move_h)(-5);
					return 1;
				}
				for (auto& i : keys)
				{
					if (GetAsyncKeyState(i.key))
					{
						//new code
						if (i.key == AE::GPuzzle::GInput::UP || i.key == AE::GPuzzle::GInput::up
							|| i.key == AE::GPuzzle::GInput::DOWN || i.key == AE::GPuzzle::GInput::down
							)
						{
							AE::GRender::s_pressedkey.key = i.key;
							AE::GRender::s_pressedkey.value = i.value;
							(gm.*move_v)(i.value);
							return 1;
						}
						else if (i.key == AE::GPuzzle::GInput::RIGHT || i.key == AE::GPuzzle::GInput::right
								 || i.key == AE::GPuzzle::GInput::LEFT || i.key == AE::GPuzzle::GInput::left
								 )
						{
							AE::GRender::s_pressedkey.key = i.key;
							AE::GRender::s_pressedkey.value = i.value;
							(gm.*move_h)(i.value);
							return 1;
						}
						else if (i.key == AE::GPuzzle::GInput::VSYNC || i.key == AE::GPuzzle::GInput::vsync)
						{
							AE::GRender::s_pressedkey.key = i.key;
							AE::GRender::s_pressedkey.value = i.value;
							Frame_Setting fm;
							fm.Set_Vsync(true);
							return 1;
						}
						//old code has just this part and no gaigantic if and else if
						//input_fptr(i.value);
						return 1;
					}
				}

				AE::GRender::s_pressedkey.key = 'N';
				AE::GRender::s_pressedkey.value = 0;
				(gm.*move_v)(0);
				(gm.*move_h)(0);
				return 1;
			}
		}
	}

}