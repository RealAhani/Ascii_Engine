#pragma once
namespace AE
{
	class GMap
	{
	public:

		GMap()
		{
			Generate_map_id();
		}
		~GMap()
		{
		}
		GMap(const AE::GMap& map)
		{
			if (this != &map)
			{
				this->m_mapstr = map.m_mapstr;
				this->m_mapname = map.m_mapname;
				this->m_mapId = map.m_mapId;
				this->m_map_size_by_char_count = map.m_map_size_by_char_count;
			}
		}

		GMap& operator =(GMap& map)
		{
			if (this == &map)
				return *this;
			this->m_mapstr = map.m_mapstr;
			this->m_mapname = map.m_mapname;
			this->m_mapId = map.m_mapId;
			this->m_map_size_by_char_count = map.m_map_size_by_char_count;

			return *this;
		}

		inline void Set_map_name(const std::string_view&& mapname)noexcept
		{
			m_mapname = mapname;
		}
		inline std::string& Get_map_name()noexcept
		{
			return m_mapname;
		}
		inline std::size_t Get_id()noexcept
		{
			return m_mapId;
		}
		inline std::string& Get_map_Shape()noexcept
		{
			return m_mapstr;
		}
		void Set_map_Shape(const std::string_view& shape)noexcept;
		inline std::size_t Get_map_size()noexcept
		{
			return m_map_size_by_char_count;
		}
	private:
		std::string m_mapstr {};
		std::string m_mapname {};
		std::size_t m_mapId {};
		std::size_t m_map_size_by_char_count {};

		std::size_t Get_map_id()noexcept;
		void Generate_map_id();
	};
}


