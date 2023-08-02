///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#include "Engine_PCH.hpp"
#include "GMap.hpp"
namespace AE
{
	std::size_t GMap::Get_map_id()noexcept
	{
		Generate_map_id();
		return m_mapId;
	}

	void GMap::Set_map_Shape(const std::string_view& shape)noexcept
	{
		if (shape.size() > 0)
		{
			m_mapstr = shape;
			m_map_size_by_char_count = shape.size();
		}
	}

	void GMap::Generate_map_id()
	{
		static std::size_t ID { 0 };
		m_mapId = ID;
		ID++;
	}

}
