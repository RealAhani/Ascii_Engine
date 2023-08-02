///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once
namespace AE
{
    class PuzzleTile {
    private:
        struct Point {
            int x{}, y{};
        };
        Point m_point{};
        uint8_t m_value{};
        void Set_Point();
        void Set_Value();
        void Set_Empty();
        bool m_empty{};

    public:
        explicit PuzzleTile(Point point = Point{ 0, 0 }, uint8_t value = 0) : m_point{ point }, m_value{ value }
        {
        }
        ~PuzzleTile();
        PuzzleTile(const PuzzleTile& tile) = delete;
        PuzzleTile& operator=(const PuzzleTile& tile) = delete;

        Point& Get_Point() const;
        uint8_t Get_Value() const;
        bool Get_Empty() const;
        friend std::ostream& operator<<(std::ostream& os, const PuzzleTile& t);
    };

}