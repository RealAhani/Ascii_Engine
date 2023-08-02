///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
namespace AE{

	class Frame_Setting {
	private:
		//TODO Create Vsync for frame rate functionality
		//60 fps ==> .016 sec|| 16 mili
		//30 fps ==> .033 sec|| 33 mili
		//20 fps ==> .05 sec|| 50 mili
		//10 fps ==> .1 sec|| 100 mili
		static inline bool b_vsync { false };
		const GPuzzle::EFPS_Setting m_vsync{};
		static inline int Calculate_FPS(const int Delta_time)
		{
			return static_cast<int>(1 / (static_cast<double>(Delta_time) / 1000.f));
		}
	public:
		Frame_Setting(/*const GPuzzle::EFPS_Setting& vsync*/) /*:m_vsync{ vsync }*/ {}
		~Frame_Setting() {}

		static inline int Get_FPS(const int Delta_time)
		{
			return Calculate_FPS(Delta_time);
		}
		void Set_Vsync(const bool turn)
		{
			b_vsync = turn;
		}
		const bool Is_Vsync_On() const
		{
			return b_vsync;
		}
		const GPuzzle::EFPS_Setting& Get_Vsynced_Frame() const
		{
			return m_vsync;
		}
	};


}

