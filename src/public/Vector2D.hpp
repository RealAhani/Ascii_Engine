#pragma once
namespace A_E
{
	struct Point2D {
		int x{}, y{};
	};
	class Vector2D {
	public:
		Vector2D(const int x, const int y);
		Vector2D(const Vector2D& vec);
		~Vector2D() = default;

		Vector2D& operator = (const Vector2D& rvec);
		Vector2D& operator + (const Vector2D& rvec);//vec+vec2
		Vector2D& operator - (const Vector2D& rvec);
		Vector2D& operator * (int scaler);
		Vector2D& operator / (const int scaler);
		friend std::ostream& operator << (std::ostream& os, const Vector2D& rvec);
	public:
		int get_length()const
		{
			return m_length;
		}
		void set_length(int length)
		{
			m_length = length;
		}
		Point2D get_info()
		{
			return m_vec_point;
		}
		Point2D get_info()const
		{
			return m_vec_point;
		}
	private:
		Point2D m_vec_point{};
		int m_length{};
	private:
		
		float get_Rotation();
	};
}