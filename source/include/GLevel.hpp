///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

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
			GLevel()
			{
			}
			~GLevel()
			{
			}
			GLevel(const AE::lvl::GLevel& lvl)
			{
				if (this != &lvl)
				{
					this->m_lvl_state = lvl.m_lvl_state;
					this->m_map = lvl.m_map;
				}
			}
			AE::lvl::GLevel& operator =(const AE::lvl::GLevel& lvl)
			{
				if (this == &lvl)
				{
					return *this;
				}
				this->m_lvl_state = lvl.m_lvl_state;
				this->m_map = lvl.m_map;
				return *this;
			}

			Lvl_state& Set_lvl_state(const Lvl_state&& lvlstate);
			void init_map(const std::string_view& map_shape_str, std::string_view&& mapname);
			AE::GMap* Get_map();
			inline Lvl_state& Get_lvl_state()noexcept
			{
				return m_lvl_state;
			}

		private:
			std::shared_ptr<GMap>m_map {};
			Lvl_state m_lvl_state {};
		};
	}
}

