#pragma once
namespace AE
{
	class GMap
	{
	public:
		
		GMap() = default;
		~GMap() = default;


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
		void Set_map_Shape(const std::string_view& shape)noexcept;
	private:
		std::string m_mapstr {};
		std::string m_mapname {};
		std::size_t m_mapId {};

		std::size_t Get_map_id()noexcept;
		void Generate_map_id();
	};
}


