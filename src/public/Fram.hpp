#pragma once
namespace AE{

	class Frame_Setting {
	private:
		//TODO Create Vsync for frame rate functionality
		//60 fps ==> .016 sec|| 16 mili
		//30 fps ==> .033 sec|| 33 mili
		//20 fps ==> .05 sec|| 50 mili
		//10 fps ==> .1 sec|| 100 mili
		//const GPuzzle::EFPS_Setting m_vsync{};
		static inline int Calculate_FPS(const int Delta_time)
		{
			return static_cast<int>(1 / (static_cast<double>(Delta_time) / 1000));
		}
	public:
		Frame_Setting(/*const GPuzzle::EFPS_Setting& vsync*/) /*:m_vsync{ vsync }*/ {}
		~Frame_Setting() {}

		static inline int Get_FPS(const int Delta_time)
		{
			return Calculate_FPS(Delta_time);
		}
		/*const GPuzzle::EFPS_Setting& Get_Vsynced_Frame() const
		{
			return m_vsync;
		}*/
	};


}

