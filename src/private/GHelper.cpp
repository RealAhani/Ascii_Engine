#include "Engine_PCH.hpp"
#include "GHelper.hpp"
#include "Vector2D.hpp"

namespace A_E
{
	namespace GPuzzle::GHelper
	{
		int Whatis_Y(int index, int width)
		{
			return (index / width == 1.0) ? 1 : ((index / width > 1.0) ? index / width : 0);
		}
		int Whatis_X(int index, int width)
		{
			return index - (width * Whatis_Y(index, width));
		}
		int Whatis_index(int width, int x, int y)
		{
			return x + (width * y);
		}
	}
	namespace GMath
	{
#define MY_PI 3.14
		float get_Rot_Deg(float Rad)
		{
			return Rad * 180 / MY_PI;
		}
		float get_Rot_Rad(float Deg)
		{
			return Deg * MY_PI / 180;
		}
		float get_sin(float opposit, float hypotenus)
		{
			return sin(opposit / hypotenus);
		}
		float get_Cos(float adjucent, float hypotenus)
		{
			return cos(adjucent / hypotenus);
		}
		float get_Tan(float opposit, float adjucent)
		{
			return tan(opposit / adjucent);
		}
		float get_CoTan(float adjucent, float opposit)
		{
			return tan(adjucent/ opposit);
		}
		
		float get_ArcCos();
		float get_ArcSin();
		float get_ArcTan();
		float get_ArcCoTan();
		float get_ArcCsc();
		float get_ArcSec();
		float get_ArcCot();
		float get_CSC();
		float get_SEC();

		Vector2D& Scale_Vec(int scaler, Vector2D& vec)
		{
			return vec * scaler;
		}

		Vector2D unit_Vec(const Vector2D& vec)
		{
			return Vector2D{vec.get_info().x / vec.get_length(),vec.get_info().y / vec.get_length()};
		}
		Vector2D& Neget_Vec(Vector2D& vec)
		{
			vec.get_info().x * -1;
			vec.get_info().y * -1;
			return vec;
		}
		int Dot_product(const Vector2D& vec1, const Vector2D& vec2)
		{
			return (vec1.get_info().x * vec2.get_info().x) + (vec1.get_info().y * vec2.get_info().y);
		}
		/*Vector2D& GMath::Cross_Product(const Vector2D& vec1, const Vector2D& vec2)
		{

		}*/
		int calc_length(Vector2D& vec)
		{
			vec.set_length(sqrt(pow(vec.get_info().x,2) + pow(vec.get_info().y,2)));
			return vec.get_length();
		}
	}
}