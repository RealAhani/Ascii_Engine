#include "Engine_PCH.hpp"
#include "GHelper.hpp"
#include "Vector2D.hpp"

namespace A_E
{
	namespace GPuzzle::GHelper
	{
		//This function are helper for work with 1D array index if you need 2D array 
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
		float get_sin(const Vector2D& v1, const Vector2D& v2)
		{
			return sin(v1.get_length() / v2.get_length());
		}
		float get_Cos(const Vector2D& v1, const Vector2D& v2)
		{
			return cos(v1.get_length() / v2.get_length());
		}
		float get_Tan(const Vector2D& v1, const Vector2D& v2)
		{
			return tan(v1.get_length() / v2.get_length());
		}
		float get_CoTan(const Vector2D& v1, const Vector2D& v2)
		{
			return tan(v1.get_length() / v2.get_length());
		}

		float get_ArcCos(const Vector2D& v1, const Vector2D& v2)
		{
			return acos(v1.get_length() / v2.get_length());
		}
		float get_ArcSin(const Vector2D& v1, const Vector2D& v2)
		{
			return asin(v1.get_length() / v2.get_length());
		}
		float get_ArcTan(const Vector2D& v1, const Vector2D& v2)
		{
			return atan(v1.get_length() / v2.get_length());
		}
		float get_ArcCoTan(const Vector2D& v1, const Vector2D& v2)
		{
			return  tanf(v1.get_length() / v2.get_length());
		}
		float get_ArcCsc(const Vector2D& v1, const Vector2D& v2)
		{
			return 0.f;
		}
		float get_ArcSec(const Vector2D& v1, const Vector2D& v2)
		{
			return 0.f;
		}
		float get_ArcCot(const Vector2D& v1, const Vector2D& v2)
		{
			return 0.f;
		}
		float get_CSC(const Vector2D& v1, const Vector2D& v2)
		{
			return 0.f;
		}
		float get_SEC(const Vector2D& v1, const Vector2D& v2)
		{
			return 0.f;
		}

		Vector2D& Scale_Vec(int scaler, Vector2D& vec)
		{
			return vec * scaler;
		}

		Vector2D unit_Vec(const Vector2D& vec)
		{
			return Vector2D{ vec.get_info().x / vec.get_length(),vec.get_info().y / vec.get_length() };
		}
		Vector2D Neget_Vec(const Vector2D& vec)
		{
			A_E::Point2D temp = vec.get_info();
			temp.x *= (-1);
			temp.y *= (-1);
			return Vector2D{ temp };
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
			return sqrt(pow(vec.get_info().x, 2) + pow(vec.get_info().y, 2));
		}
	}
}