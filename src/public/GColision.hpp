#pragma once
#include "Vector2D.hpp"
#include "GWorld.hpp"
namespace AE
{
	template<size_t size>
	class GColision
	{
	public:
		GColision()=default;
		~GColision() = default;


		bool Is_collide(const AE::GVector::Point2D& destination_point);
		inline bool Get_block_effect()noexcept
		{
			return can_block;
		}
		inline void Set_block_effect(bool block = false)noexcept
		{
			can_block = block;
		}

		/// fill the bitse
		void Init_map_colisions()
		{
			//logic to fill bitset based on map chars
			//eg. if its # set this position to 1 etc...
		}
		bool Is_it_runable(const AE::GVector::Point2D& destination);
	private:
		bool can_block {};
		/// 1 is colide
		/// 0 is not colide
		/// 0001
		/// 1100 ====>00011100==>1 is blockable 0 is not
		std::bitset<size> map_colision_info {};
	};
}