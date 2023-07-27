#include "Engine_PCH.hpp"
#include "GTimer.hpp"
AE::GTimer::ETimer_Mode AE::GTimer::s_Global_mode{};
AE::GTimer::GTPoint AE::GTimer::s_elapsedtime{};

AE::GTimer::GTimer()
{
}
AE::GTimer::~GTimer()
{
}

#pragma region RESET_TIME
/*
START Reset the time for zeroing out the time elapsed and start time funcs
*/
void AE::GTimer::Reset_Time()
{
	m_starttime = {};
	m_endtime = {};
}
void AE::GTimer::Reset_Global_Timer()
{
	s_elapsedtime = {};
}
void AE::GTimer::Reset_Timer()
{
	m_elapsedtime = {};
}
/*
END
*/

#pragma endregion

#pragma region DELTA_TIME_FUNCTIONS
/*
START this functions used for benchmark the code need start and end to calculate time 
*/
void  AE::GTimer::Start_Time()
{
	Reset_Time();
	m_starttime = GClock::now();
}
void  AE::GTimer::End_Time()
{
	m_endtime = GClock::now();
}
int AE::GTimer::Get_DeltaTime()
{
	Calculate_DeltaTime();
	return static_cast<int>(m_deltatime.count());
}
void  AE::GTimer::Calculate_DeltaTime()
{
	using namespace std::chrono;
	m_deltatime = duration_cast<GMilisecond>(m_endtime - m_starttime);
}
/*
END
*/
#pragma endregion

#pragma region TIMER_SEC
/*
START these functions used for Global time
e.x whole program running time
*/
double AE::GTimer::Update_Global_Timer()
{
	using namespace std::chrono;
	double dt{};
	GMilisecond mili_seconds{};
	GSecond seconds{};
	GTPoint now = GClock::now();
	switch (s_Global_mode)
	{
	case GTimer::ETimer_Mode::Persice_Second:
		mili_seconds = duration_cast<GMilisecond>(now - s_elapsedtime);
		//dt = static_cast<double>(mili_seconds.count())/1000;
		dt = static_cast<double>(GSecond{ mili_seconds.count() }.count());
		break;
	case GTimer::ETimer_Mode::Normal_Second:
		seconds = duration_cast<GSecond>(now - s_elapsedtime);
		dt = static_cast<double>(seconds.count());
		break;
	default:
		break;
	}
	return dt;
}
void AE::GTimer::Start_Global_Timer(const ETimer_Mode&& Gmode)
{
	s_Global_mode = Gmode;
	Reset_Global_Timer();
	s_elapsedtime = GClock::now();
}
double AE::GTimer::Get_Global_ElapsedTime()
{
	return Update_Global_Timer();
}
/*
END
*/
#pragma endregion

#pragma region TIMER_MILI
/*
START these functions used for creating normal timer
e.x little timer for running events
*/
double AE::GTimer::Update_Timer()
{
	using namespace std::chrono;
	double dt{};
	GMilisecond mili_seconds{};
	GSecond seconds{};
	GTPoint now = GClock::now();
	switch (m_mode)
	{
	case GTimer::ETimer_Mode::Persice_Second:
		mili_seconds = duration_cast<GMilisecond>(now - s_elapsedtime);
		//dt = static_cast<double>(mili_seconds.count()) / 1000;
		dt = static_cast<double>(GSecond{ mili_seconds.count() }.count());
		break;
	case GTimer::ETimer_Mode::Normal_Second:
		seconds = duration_cast<GSecond>(now - s_elapsedtime);
		dt = static_cast<double>(seconds.count());
		break;
	default:
		break;
	}
	return dt;
}
void AE::GTimer::Start_Timer(const ETimer_Mode&& mode)
{
	m_mode = mode;
	Reset_Timer();
	m_elapsedtime = GClock::now();
}
double AE::GTimer::Get_ElapsedTime()
{
	return Update_Timer();
}
/*
END
*/
#pragma endregion