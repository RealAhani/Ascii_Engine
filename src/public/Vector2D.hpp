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
		Vector2D& operator * (const Vector2D& rvec);
		Vector2D& operator / (const Vector2D& rvec);
		friend std::ostream& operator << (std::ostream& os, const Vector2D& rvec);
	public:
		Point2D m_vec{};
		int m_length{};
	private:
		Point2D& get_info()const;
		int get_length()const;
	private:
		int calc_length(const Vector2D& vec)const;
		Vector2D& unit_Vec(Vector2D& vec)const;
		Vector2D& Neget_Vec(Vector2D& vec)const;
		friend int Dot_product(const Vector2D& vec1, const Vector2D& vec2);
		friend Vector2D& Cross_Product(const Vector2D& vec1, const Vector2D& vec2);
		float get_Rotation();
		float get_Rot_Deg(float Rad);
		float get_Rot_Rad(float Deg);
		float get_sin();
		float get_Cos();
		float get_Tan();
		float get_CoTan();
		float get_ArcCos();
		float get_ArcSin();
		float get_ArcTan();
		float get_ArcCoTan();
		float get_ArcCsc();
		float get_ArcSec();
		float get_ArcCot();
		float get_CSC();
		float get_SEC();
		int Scale_Vec(int scaler, const Vector2D& vec);
	};
}