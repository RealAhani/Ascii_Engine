#pragma once
namespace A_E
{
    namespace GPuzzle
    {
        namespace GInput
        {
#define UP 'W'
#define DOWN 'S'
#define LEFT 'A'
#define RIGHT 'D'
#define EXIT 'Q'
            // End defining Inputs

            enum class Direction : uint8_t {
                up,
                down,
                left,
                right,
                Max
            };
            struct Keyboard_Value {
                char key{};
                int value{};
            };
           // void Get_key(char ch);
            
            template<size_t size>
            void Input_Init(const std::array<A_E::GPuzzle::GInput::Keyboard_Value,size>& keys);
            
            template <size_t size>
            void sendinput(const std::array<A_E::GPuzzle::GInput::Keyboard_Value, size>& keys, void (*input_fptr)(int));
        }
    }

}