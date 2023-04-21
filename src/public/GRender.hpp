#pragma once
namespace A_E
{
	class Frame_Setting;
	class GRender {
	private:

	public:
		GRender();
		~GRender();
		static void Draw(const int Delta_time);
		static void Show_Game_Detail(const int Delta_time);
		static void Clean();
	};
}