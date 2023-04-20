#pragma once
namespace GPuzzle
{
	namespace GInput
	{
#define UP 'w'
#define UP 'W'
#define DOWN 's'
#define DOWN 'S'
#define LEFT 'a'
#define LEFT 'A'
#define RIGHT 'd'
#define RIGHT 'D'
#define EXIT 'Q'
#define EXIT 'q'
        // End defining Inputs

        enum class Direction : uint8_t {
            up,
            down,
            left,
            right,
            Max
        };

        void Get_key(char ch);
	}
}

