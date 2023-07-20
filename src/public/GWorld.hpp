#pragma once
#include "GLevel.hpp"
namespace AE
{
	namespace world
	{
		template<size_t size>
		class GWorld
		{
		public:
			GWorld() = delete;
			~GWorld() = delete;

			static void Init_levels(const std::array<AE::lvl::GLevel, size>& levels)
			{
				m_levels = levels;
			}
			inline static std::array< AE::lvl::GLevel, size>& Get_levels()
			{
				return m_levels;
			}

		private:
			static inline std::array<AE::lvl::GLevel, size> m_levels {};
		};

	}
}

