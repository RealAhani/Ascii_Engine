#pragma once
#include "GLevel.hpp"
#include"GMap.hpp"
namespace AE
{
	namespace world
	{
		template<size_t size>
		class GWorld
		{
		public:
			GWorld()
			{
			}
			~GWorld()
			{
			}

			static GWorld* Init_Game_World()
			{
				static GWorld* m_world_instance { nullptr };
				if (!m_world_instance)
					m_world_instance = new GWorld();
				return m_world_instance;
			}
			static void Destroy_Game_World()
			{
				auto ptr = Init_Game_World();
				if (ptr)
					delete ptr;
			}
			static void Init_levels(const std::array<AE::lvl::GLevel, size>& levels)
			{
				m_levels = levels;
				Go_to_next_level();
			}
			static void Show_lvl()
			{
				//AE::GRender::Add_to_buffer(m_levels.at(s_current_lvl).Get_map()->Get_map_Shape().c_str(), AE::ERenderRow::Body);
			}
			inline static std::array< AE::lvl::GLevel, size>& Get_levels()
			{
				return m_levels;
			}

			static void Go_to_next_level()
			{
				CLS();
				Clean_level();
				Show_lvl();
				if (m_levels.size() - 1 > s_current_lvl)
					s_current_lvl++;
			}

			static void Clean_level()
			{
				AE::GRender::Clear_Buffer();
			}
			inline static std::array< AE::lvl::GLevel, size>& Get_all_levels()
			{
				return m_levels;
			}
		private:
			static inline std::array<AE::lvl::GLevel, size> m_levels {};
			static inline std::size_t s_current_lvl { 0 };
		};
	}
}

