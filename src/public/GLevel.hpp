#pragma once
#include "GMap.hpp"
namespace AE
{
	namespace lvl
	{
		enum class Lvl_state :unsigned char
		{
			Runing = 0,
			Opening,
			Closing,
			Closed,
		};

		class GLevel
		{
		public:
			GLevel() = default;
			~GLevel() = default;

			inline Lvl_state& Get_lvl_state()noexcept
			{
				return m_lvl_state;
			}

			Lvl_state& Set_lvl_state(const Lvl_state&& lvlstate);

			void init_map(const std::string_view& map_shape_str, std::string_view&& mapname);

		private:
			std::unique_ptr<GMap>m_map {};
			Lvl_state m_lvl_state {};

		};
	}
}

