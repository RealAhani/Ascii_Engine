#pragma once
namespace AE
{
    class GameTile;
    class PuzzleBoard {
    private:
        static const int m_width{ 4 }, m_height{ 4 };
        static const int const m_total{ m_width * m_height };
        std::array<GameTile*, m_total> m_tiles{};

    public:
        PuzzleBoard(/* args */);
        ~PuzzleBoard();

        GameTile& Get_Adjacent_Tile(const GPuzzle::GInput::Direction& dir);
        void Swap(GameTile& origin_tile, GameTile& destination_tile);
    };

}