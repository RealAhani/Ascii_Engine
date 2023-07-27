#pragma once
namespace AE
{
	class GTimer {
	public:
		using GMilisecond = std::chrono::milliseconds;
		using GSecond = std::chrono::seconds;
		using GTPoint = std::chrono::steady_clock::time_point;
		using GClock = std::chrono::steady_clock;
		enum class ETimer_Mode :uint8_t {
			Persice_Second, Normal_Second
		};
	private:
		GMilisecond m_deltatime{};
		GTPoint m_starttime{};
		GTPoint m_endtime{};
		static GTPoint s_elapsedtime;
		static ETimer_Mode s_Global_mode;
		GTPoint m_elapsedtime{};
		ETimer_Mode m_mode{};
		GTimer(const GTimer& timer) = delete;
		GTimer(const GTimer&& timer) = delete;
		void Calculate_DeltaTime();
		void Reset_Time();
		void Reset_Timer();
		static void Reset_Global_Timer();
		static double Update_Global_Timer();
		double Update_Timer();
	public:
		GTimer();
		~GTimer();

		int Get_DeltaTime();
		void Start_Time();
		void End_Time();

		static void Start_Global_Timer(const ETimer_Mode&& Gmode = GTimer::ETimer_Mode::Normal_Second);
		static double Get_Global_ElapsedTime();

		void Start_Timer(const ETimer_Mode&& mode = GTimer::ETimer_Mode::Persice_Second);
		double Get_ElapsedTime();
	};
}