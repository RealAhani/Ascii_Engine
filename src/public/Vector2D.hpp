#pragma once

//TODO remove this include 
#include"GHelper.hpp"

namespace AE::GVector
{
	struct Point2D {
		int x{}, y{};
	};
	class Vector2D
	{
	public:
		Vector2D(const int x, const int y);
		Vector2D(const Vector2D& vec);
		Vector2D(const Point2D& point);
		~Vector2D() = default;

		Vector2D& operator = (const Vector2D& rvec);
		Vector2D& operator + (const Vector2D& rvec);//vec+vec2
		Vector2D& operator - (const Vector2D& rvec);
		Vector2D& operator * (int scaler);

		Vector2D& operator / (const int scaler);
		friend std::ostream& operator << (std::ostream& os, const Vector2D& rvec);
	public:
		int get_length()const;
		Point2D get_info();
		Point2D get_info()const;
	private:
		Point2D m_vec_point {};
		int m_length {};
	private:
		float get_Rotation();
	};
}

