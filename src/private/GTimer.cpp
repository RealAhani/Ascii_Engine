#include "Engine_PCH.hpp"
#include "GTimer.hpp"
A_E::GTimer::ETimer_Mode A_E::GTimer::s_Global_mode{};
A_E::GTimer::GTPoint A_E::GTimer::s_elapsedtime{};

A_E::GTimer::GTimer()
{
}
A_E::GTimer::~GTimer()
{
}

/*
START Reset time func
*/
void A_E::GTimer::Reset_Time()
{
	m_starttime = {};
	m_endtime = {};
}
void A_E::GTimer::Reset_Global_Timer()
{
	s_elapsedtime = {};
}
void A_E::GTimer::Reset_Timer()
{
	m_elapsedtime = {};
}
/*
END
*/

/*
START this functions used for benchmark the code
*/
void  A_E::GTimer::Start_Time()
{
	Reset_Time();
	m_starttime = GClock::now();
}
void  A_E::GTimer::End_Time()
{
	m_endtime = GClock::now();
}
int A_E::GTimer::Get_DeltaTime()
{
	Calculate_DeltaTime();
	return static_cast<int>(m_deltatime.count());
}
void  A_E::GTimer::Calculate_DeltaTime()
{
	using namespace std::chrono;
	m_deltatime = duration_cast<GMilisecond>(m_endtime - m_starttime);
}
/*
END
*/

/*
START these functions used for Global time
e.x whole program running time
*/
double A_E::GTimer::Update_Global_Timer()
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
void A_E::GTimer::Start_Global_Timer(const ETimer_Mode&& Gmode)
{
	s_Global_mode = Gmode;
	Reset_Global_Timer();
	s_elapsedtime = GClock::now();
}
double A_E::GTimer::Get_Global_ElapsedTime()
{
	return Update_Global_Timer();
}
/*
END
*/

/*
START these functions used for creating normal timer
e.x little timer for running events
*/
double A_E::GTimer::Update_Timer()
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
void A_E::GTimer::Start_Timer(const ETimer_Mode&& mode)
{
	m_mode = mode;
	Reset_Timer();
	m_elapsedtime = GClock::now();
}
double A_E::GTimer::Get_ElapsedTime()
{
	return Update_Timer();
}
/*
END
*/
