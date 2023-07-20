#pragma once

class Vector2D;
namespace AE
{
	namespace GPuzzle
	{
		enum class EFPS_Setting:uint8_t {
			fps_60, fps_30, fps_20, fps_10
		};
		namespace GHelper
		{
			class PuzzleTile;
			std::array<PuzzleTile, 16>& Randomizer(std::array<PuzzleTile, 16>& t_arr);
			PuzzleTile& Filler_tiles(std::array<PuzzleTile, 16>& t_arr);
			int Whatis_Y(int index, int width);
			int Whatis_X(int index, int width);
			int Whatis_index(int width, int x, int y);
		}
		namespace prize
		{
			static constexpr std::string_view You_win = "      \\\\    //      ____                                            [  ]                              \n       \\\\  //     //     \\\\      ||     ||         \\\\            //  ||  ||\\\\   ||             \n         ||      ||      ||      ||     ||          \\\\          //   ||  || \\\\  ||                 \n         ||      ||      ||      \\\\     //           \\\\  //\\\\  //    ||  ||  \\\\ ||             \n         ||       \\\\____//        \\\\___//             \\\\//  \\\\//    [  ] ||   \\\\||           \n";
		}
	}
	namespace GMath
	{
		float get_Rot_Deg(float Rad);
		float get_Rot_Rad(float Deg);
		float get_sin(const Vector2D& v1, const Vector2D& v2);
		float get_Cos(const Vector2D& v1, const Vector2D& v2);
		float get_Tan(const Vector2D& v1, const Vector2D& v2);
		float get_CoTan(const Vector2D& v1, const Vector2D& v2);

		float get_ArcCos(const Vector2D& v1, const Vector2D& v2);
		float get_ArcSin(const Vector2D& v1, const Vector2D& v2);
		float get_ArcTan(const Vector2D& v1, const Vector2D& v2);
		float get_ArcCoTan(const Vector2D& v1, const Vector2D& v2);
		float get_ArcCsc(const Vector2D& v1, const Vector2D& v2);
		float get_ArcSec(const Vector2D& v1, const Vector2D& v2);
		float get_ArcCot(const Vector2D& v1, const Vector2D& v2);

		float get_CSC(const Vector2D& v1, const Vector2D& v2);
		float get_SEC(const Vector2D& v1, const Vector2D& v2);

		Vector2D& Scale_Vec(int scaler, Vector2D& vec);
		Vector2D Neget_Vec(const Vector2D& vec);
		Vector2D unit_Vec(const Vector2D& vec);

		int Dot_product(const Vector2D& vec1, const Vector2D& vec2);
		//Vector2D& Cross_Product(const Vector2D& vec1, const Vector2D& vec2);
		int calc_length(Vector2D& vec);
	}
}