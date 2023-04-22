#pragma once
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
}