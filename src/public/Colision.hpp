#pragma once
namespace A_E
{
	class Colision
	{
	public:
		Colision()=default;
		~Colision() = default;


		bool is_collide(/*positon*/);
		inline bool get_block_effect()noexcept
		{
			return can_block;
		}
		inline void set_block_effect(bool block = false)noexcept
		{
			can_block = block;
		}
	private:
		bool can_block {};
	};
}