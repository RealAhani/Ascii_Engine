#include "Engine_PCH.hpp"
#include "GInput.hpp"

template<size_t size>
void A_E::GPuzzle::GInput::Input_Init(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, size>& keys)
{
	//sendinput(keys, &H_Move);
}

template <size_t size>
void A_E::GPuzzle::GInput::sendinput(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, size>& keys, void (*input_fptr)(int))
{
    if (GetAsyncKeyState(VK_ESCAPE))
       // game_over = true;
    for (auto& i : keys)
    {
        if (GetAsyncKeyState(i.key))
        {
            input_fptr(i.value);
            return;
        }
    }
    input_fptr(0);
}