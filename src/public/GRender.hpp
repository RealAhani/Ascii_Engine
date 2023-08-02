///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
#include "GBuffer.hpp"


//temp include bd dont have seperation translation unit for GRender at the time 
#include "GWindow.hpp"
namespace AE
{
	class Frame_Setting;
	namespace GPuzzle::GInput
	{
		struct Keyboard_Value;
	}

	class GRender
	{
		friend class GWindow;
	public:
		using s_uint = unsigned int;
	public:
		GRender() = delete;

		void Start_Rendere(int delta_time);

		GBuffer* Get_Buffer();

		void Change_Buffer(GBuffer* buf);
		static GRender* CreatInstance();
		static void DestroyInstance();


		///Debuger that show on the header of the terminal that wich key is currently pressed
		static AE::GPuzzle::GInput::Keyboard_Value s_pressedkey;
		
		///main function for draw every thing on the screen (terminal)
		static void Clear_Buffer();

	private:
		GRender(s_uint w, s_uint h);
		~GRender();
		GBuffer* Init_Buffer(s_uint w, s_uint h);
		

		void Draw_On_Screen();
		void Clear_Screen();

	private:
		static inline GBuffer* m_buffer { nullptr };
	};
}
