#include "Puzzle_PCH.hpp"
#include "GTimer.hpp"
GTimer::ETimer_Mode GTimer::s_Global_mode{};
GTimer::GTPoint GTimer::s_elapsedtime{};

GTimer::GTimer()
{
}
GTimer::~GTimer()
{	
}

/*
START Reset time func
*/
void GTimer::Reset_Time()
{
	m_starttime = {};
	m_endtime = {};
}
void GTimer::Reset_Global_Timer()
{
	s_elapsedtime = {};
}
void GTimer::Reset_Timer()
{
	m_elapsedtime = {};
}
/*
END
*/

/*
START this functions used for benchmark the code
*/
void  GTimer::Start_Time()
{
	Reset_Time();
	m_starttime = GClock::now();
}
void  GTimer::End_Time()
{
	m_endtime = GClock::now();
}
int GTimer::Get_DeltaTime()
{
	Calculate_DeltaTime();
	return static_cast<int>(m_deltatime.count());
}
void  GTimer::Calculate_DeltaTime()
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
double GTimer::Update_Global_Timer()
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
		dt = static_cast<double>(mili_seconds.count())/1000;
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
void GTimer::Start_Global_Timer(const ETimer_Mode&& Gmode)
{
	s_Global_mode = Gmode;
	Reset_Global_Timer();
	s_elapsedtime = GClock::now();
}
double GTimer::Get_Global_ElapsedTime()
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
double GTimer::Update_Timer()
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
		dt = static_cast<double>(mili_seconds.count()) / 1000;
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
void GTimer::Start_Timer(const ETimer_Mode&& mode )
{
	m_mode = mode;
	Reset_Timer();
	m_elapsedtime = GClock::now();
}
double GTimer::Get_ElapsedTime()
{
	return Update_Timer();
}
/*
END
*/
