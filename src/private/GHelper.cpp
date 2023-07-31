#include "Engine_PCH.hpp"
#include "GHelper.hpp"
#include "Vector2D.hpp"

namespace AE
{
	namespace GPuzzle::GHelper
	{
		//This function are helper for work with 1D array index if you need 2D array 
		/*int Whatis_Y(int index, int width)
		{
			return (index / width == 1.0) ? 1 : ((index / width > 1.0) ? index / width : 0);
		}
		int Whatis_X(int index, int width)
		{
			return index - (width * Whatis_Y(index, width));
		}
		auto Whatis_index(auto width, auto x, auto y)
		{
			return x + (width * y);
		}*/
	}
	namespace GMath
	{
#define MY_PI 3.14f
		float get_Rot_Deg(float Rad)
		{
			return Rad * 180 / MY_PI;
		}
		float get_Rot_Rad(float Deg)
		{
			return Deg * MY_PI / 180;
		}
		float get_sin(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )sin(v1.get_length() / v2.get_length());
		}
		float get_Cos(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )cos(v1.get_length() / v2.get_length());
		}
		float get_Tan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )tan(v1.get_length() / v2.get_length());
		}
		float get_CoTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )tan(v1.get_length() / v2.get_length());
		}

		float get_ArcCos(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return (float)acos(v1.get_length() / v2.get_length());
		}
		float get_ArcSin(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )asin(v1.get_length() / v2.get_length());
		}
		float get_ArcTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return ( float )atan(v1.get_length() / v2.get_length());
		}
		float get_ArcCoTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return  tanf(( float )v1.get_length() / ( float )v2.get_length());
		}
		float get_ArcCsc(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return 0.f;
		}
		float get_ArcSec(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return 0.f;
		}
		float get_ArcCot(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return 0.f;
		}
		float get_CSC(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return 0.f;
		}
		float get_SEC(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2)
		{
			return 0.f;
		}

		AE::GVector::Vector2D& Scale_Vec(int scaler, AE::GVector::Vector2D& vec)
		{
			return vec * scaler;
		}

		AE::GVector::Vector2D unit_Vec(const AE::GVector::Vector2D& vec)
		{
			return AE::GVector::Vector2D{ vec.get_info().x / vec.get_length(),vec.get_info().y / vec.get_length() };
		}
		AE::GVector::Vector2D Neget_Vec(const AE::GVector::Vector2D& vec)
		{
			AE::GVector::Point2D temp = vec.get_info();
			temp.x *= (-1);
			temp.y *= (-1);
			return AE::GVector::Vector2D{ temp };
		}
		int Dot_product(const AE::GVector::Vector2D& vec1, const AE::GVector::Vector2D& vec2)
		{
			return (vec1.get_info().x * vec2.get_info().x) + (vec1.get_info().y * vec2.get_info().y);
		}
		/*Vector2D& GMath::Cross_Product(const Vector2D& vec1, const Vector2D& vec2)
		{

		}*/
		int calc_length(AE::GVector::Vector2D& vec)
		{
			return (int)sqrt(pow(vec.get_info().x, 2) + pow(vec.get_info().y, 2));
		}
	}
}