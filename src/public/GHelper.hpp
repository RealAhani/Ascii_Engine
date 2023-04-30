#pragma once

class Vector2D;
namespace A_E
{
	namespace GPuzzle
	{
		enum EFPS_Setting {
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
		float get_sin(float opposit, float hypotenus);
		float get_Cos(float adjucent, float hypotenus);
		float get_Tan(float opposit, float adjucent);
		float get_CoTan(float adjucent, float opposit);

		float get_ArcCos();
		float get_ArcSin();
		float get_ArcTan();
		float get_ArcCoTan();
		float get_ArcCsc();
		float get_ArcSec();
		float get_ArcCot();

		float get_CSC();
		float get_SEC();

		Vector2D& Scale_Vec(int scaler, Vector2D& vec);
		Vector2D& Neget_Vec(Vector2D& vec);
		Vector2D unit_Vec(const Vector2D& vec);

		int Dot_product(const Vector2D& vec1, const Vector2D& vec2);
		//Vector2D& Cross_Product(const Vector2D& vec1, const Vector2D& vec2);
		int calc_length(Vector2D& vec);
	}
}