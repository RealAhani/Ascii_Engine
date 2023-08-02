#include "Engine_PCH.hpp"
#include "GRender.hpp"
#include "Fram.hpp"
#include "GWindow.hpp"
//definition of a test static struct mem for know wich key with wich value is pressed (debugging perpuse)
AE::GPuzzle::GInput::Keyboard_Value AE::GRender::s_pressedkey {};

/// <summary>
/// TODO TEST Remove this include 
#include "GSprite.hpp"
namespace AE
{
	void GRender::Start_Rendere(int delta_time)
	{

		Clear_Screen();
		if (m_buffer)
		{
			std::string test = "Game Timer: " + std::to_string(( int )GTimer::Get_Global_ElapsedTime()) + "    " + s_pressedkey.key + std::to_string(s_pressedkey.value)
				+ "  " + "FPS: " + std::to_string(Frame_Setting::Get_FPS(( int )delta_time)) + " Latency(ms): " + std::to_string(( int )delta_time);
			test.resize(test.size() + 7);
			//std::array<short, 10> arr_colors { {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}} };

			GSprite sp1(test, test.size(), 1, AE::GVector::Point2D { 1, 0 });

			GSprite sp2(AE::GPuzzle::prize::You_win, AE::GPuzzle::prize::You_win.size() / 16, 16, AE::GVector::Point2D { 0,2 });
			//GSprite sp2(str, str.size() / 12, 12, AE::GVector::Point2D { 0,3 });
			//mem leak
			m_buffer->Add_Sprite(sp1);
			m_buffer->Add_Sprite(sp2);
			m_buffer->Fill_Pixels_Symboles();
			m_buffer->Fill_Pixels_Color();
		}
		
		Draw_On_Screen();
	}

	GBuffer* GRender::Get_Buffer()
	{
		return nullptr;
	}

	void GRender::Change_Buffer(GBuffer* buf)
	{
		///TODO CREATE COPY CTOR AND COPY OPERATOR OVERLOAD FOR AVOID SHALLOW COPY
		*m_buffer = *buf;
	}

	GRender* GRender::CreatInstance()
	{
		static GRender* instance { nullptr };
		if (!instance)
		{
			int te = GScreen::Get_heigth();
			int e3 = GScreen::Get_with();
			instance = new GRender(GScreen::Get_heigth(), GScreen::Get_with());

		}
		return instance;
	}
	void GRender::DestroyInstance()
	{
		GRender* tes = GRender::CreatInstance();
		delete tes;
		tes = nullptr;
	}


	///Debuger that show on the header of the terminal that wich key is currently pressed
	static AE::GPuzzle::GInput::Keyboard_Value s_pressedkey;

	///main function for draw every thing on the screen (terminal)
	void GRender::Clear_Buffer()
	{
		if (m_buffer)
		{
			delete m_buffer;
			m_buffer = nullptr;
		}
	}

	GRender::GRender(s_uint w, s_uint h)
	{
		Init_Buffer(w, h);
	}
	GRender::~GRender()
	{
		Clear_Buffer();
	}
	GBuffer* GRender::Init_Buffer(s_uint w, s_uint h)
	{
		if (!m_buffer)
			m_buffer = new GBuffer {};
		return m_buffer;
	}

	void GRender::Draw_On_Screen()
	{
		if(m_buffer)
		GWindow::WriteOnConsole(m_buffer->Get_Buffer_Symboles_Array(), m_buffer->Get_Buffer_Color_Array());
	}
	void GRender::Clear_Screen()
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0,0 });
		if (m_buffer)
		{
			if (m_buffer->Get_Sprites().size() > 0)
				m_buffer->Clear_Sprite();
		}
	}
}

//void AE::GRender::Clean()
//{
//	//CLS();
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0,0 });
//}
//
//void AE::GRender::Draw_Header(const int Delta_time)
//{
//
//	m_header_buffer = "Game Timer: " + std::to_string(GTimer::Get_Global_ElapsedTime()) + "    " + s_pressedkey.key + std::to_string(s_pressedkey.value)
//		+ "  " + "FPS: " + std::to_string(Frame_Setting::Get_FPS(Delta_time)) + " Latency(ms): " + std::to_string(Delta_time);
//	m_header_buffer += m_body_buffer;
//	GWindow::WriteOnConsole(m_header_buffer, COORD { 1,0 });
//}