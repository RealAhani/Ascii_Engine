#include <Engine_PCH.hpp>
#include "GColision.hpp"

template<size_t size>
bool AE::GColision<size>::Is_collide(const AE::GVector::Point2D& destination_point)
{
	return Is_it_runable(size, destination_point);
}

template<size_t size>
bool AE::GColision<size>::Is_it_runable(const AE::GVector::Point2D& destination)
{
	///look through the bitset and search for this position and return the  value
	int index = AE::GPuzzle::GHelper::Whatis_index(size, destination.x, destination.y);
	return ( bool )map_colision_info[index];
}
