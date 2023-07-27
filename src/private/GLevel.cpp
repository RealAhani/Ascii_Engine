#include "Engine_PCH.hpp"
#include "GLevel.hpp"
namespace AE
{
	namespace lvl
	{
		Lvl_state& GLevel::Set_lvl_state(const Lvl_state&& lvlstate)
		{
			switch (lvlstate)
			{
				case Lvl_state::Runing:
				{
					m_lvl_state = Lvl_state::Runing;
					break;
				}
				case Lvl_state::Opening:
				{
					m_lvl_state = Lvl_state::Opening;
					break;
				}
				case Lvl_state::Closing:
				{
					m_lvl_state = Lvl_state::Closing;
					break;
				}
				case Lvl_state::Closed:
				{
					m_lvl_state = Lvl_state::Closed;
					break;
				}
				default:
				{
					m_lvl_state = Lvl_state::Closed;
					break;
				}
			}
			return m_lvl_state;
		}
		void GLevel::init_map(const std::string_view& map_shape_str, std::string_view&& mapname)
		{
			if (!m_map)
				m_map = std::make_shared<GMap>();
			m_map->Set_map_Shape(map_shape_str);
			m_map->Set_map_name(std::move(mapname));
		}
		AE::GMap* GLevel::Get_map()
		{
			if (m_map)
				return m_map.get();
			return nullptr;
		}
	}
}