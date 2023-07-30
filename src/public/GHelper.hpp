#pragma once
namespace AE::GVector
{
	class Vector2D;

}
namespace AE
{
	namespace GPuzzle
	{
		enum class EFPS_Setting :uint8_t
		{
			fps_60, fps_30, fps_20, fps_10
		};
		namespace GHelper
		{
			class PuzzleTile;
			std::array<PuzzleTile, 16>& Randomizer(std::array<PuzzleTile, 16>& t_arr);
			PuzzleTile& Filler_tiles(std::array<PuzzleTile, 16>& t_arr);

			template<typename T>
			T Whatis_Y(T index, T width)
			{
				return (index / width == 1.0) ? 1 : ((index / width > 1.0) ? index / width : 0);
			}

			template<typename T>
			T Whatis_X(T index, T width)
			{
				return index - (width * Whatis_Y(index, width));
			}
			
			template<typename T>
			T Whatis_index(T width, T x, T y)
			{
				return x + (width * y);
			}
		}
		namespace prize
		{
			static constexpr std::string_view You_win = "\\\\    //        ____                                                  [  ]            "
				" \\\\  //      //      \\\\      ||     ||         \\\\              //  ||  ||\\\\   ||"
				"     ||        ||      ||        ||     ||          \\\\            //   ||  || \\\\  ||"
				"     ||        ||      ||      \\\\     //           \\\\  //\\\\  //    ||  ||  \\\\ ||"
				"     ||       \\\\____//        \\\\___//             \\\\//  \\\\//    [  ] ||   \\\\||";
		}
	}
	namespace GMath
	{

		float get_Rot_Deg(float Rad);
		float get_Rot_Rad(float Deg);
		float get_sin(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_Cos(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_Tan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_CoTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);

		float get_ArcCos(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcSin(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcCoTan(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcCsc(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcSec(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_ArcCot(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);

		float get_CSC(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);
		float get_SEC(const AE::GVector::Vector2D& v1, const AE::GVector::Vector2D& v2);

		AE::GVector::Vector2D& Scale_Vec(int scaler, AE::GVector::Vector2D& vec);
		AE::GVector::Vector2D Neget_Vec(const AE::GVector::Vector2D& vec);
		AE::GVector::Vector2D unit_Vec(const AE::GVector::Vector2D& vec);

		int Dot_product(const AE::GVector::Vector2D& vec1, const AE::GVector::Vector2D& vec2);
		//Vector2D& Cross_Product(const Vector2D& vec1, const Vector2D& vec2);
		int calc_length(AE::GVector::Vector2D& vec);
	}
}