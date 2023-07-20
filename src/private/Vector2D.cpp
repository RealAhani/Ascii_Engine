#include "Engine_PCH.hpp"
#include "Vector2D.hpp"

Vector2D::Vector2D(const int x, const int y) :m_vec_point{ x,y }, m_length{ AE::GMath::calc_length(*this) }
{
}
Vector2D::Vector2D(const AE::Point2D& point) :m_vec_point{ point }
{
}
Vector2D::Vector2D(const Vector2D& vec)
{
	if (this == &vec)
		return;
	*this = vec;
}

Vector2D& Vector2D::operator = (const Vector2D& rvec)
{
	if (this == &rvec)
		return *this;
	this->m_vec_point = rvec.m_vec_point;
	this->m_length = rvec.m_length;
	return *this;
}
Vector2D& Vector2D::operator + (const Vector2D& rvec)
{
	m_vec_point.x + rvec.m_vec_point.x;
	m_vec_point.y + rvec.m_vec_point.y;
	return *this;
}//vec+vec2
Vector2D& Vector2D::operator - (const Vector2D& rvec)
{
	m_vec_point.x - rvec.m_vec_point.x;
	m_vec_point.y - rvec.m_vec_point.y;
	return *this;
}
Vector2D& Vector2D::operator * (int scaler)
{
	m_vec_point.x* scaler;
	m_vec_point.y* scaler;
	return *this;
}
Vector2D& Vector2D::operator / (const int scaler)
{
	m_vec_point.x / scaler;
	m_vec_point.y / scaler;
	return *this;
}
//this is a friend function that implemented here
std::ostream& operator << (std::ostream& os, const Vector2D& rvec)
{
	return	os << rvec.m_vec_point.x << rvec.m_vec_point.x << rvec.get_length();
}

int Vector2D::get_length()const
{
	return m_length;
}
AE::Point2D Vector2D::get_info()
{
	return m_vec_point;
}
AE::Point2D Vector2D::get_info()const
{
	return m_vec_point;
}
float Vector2D::get_Rotation()
{
	return 0.f;
}