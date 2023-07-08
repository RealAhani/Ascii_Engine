#pragma once

namespace A_E
{
	class Frame_Setting;
	namespace GPuzzle
	{
		namespace GInput
		{
			struct Keyboard_Value;
		}
	}
	class GRender {
	private:
	public:
		GRender();
		~GRender();
		static A_E::GPuzzle::GInput::Keyboard_Value s_pressedkey;
		static void Draw(const int Delta_time);
		static void Show_Game_Detail(const int Delta_time);
		static void Clean();
	};
}
