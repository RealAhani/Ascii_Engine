///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once


// T is Result type this class give after call GetRandom
// K is minmax type for the range that this class is used to filter randoms
namespace AE::Rand
{
    template <typename T, typename K>
    class GRandom
    {
    public:
        GRandom() = delete;
        ~GRandom() = default;
        GRandom(K min, K max)
            : m_rand_distro { min, max }
        {
        }
        T GetRandom() const noexcept
        {
            return const_cast< GRandom& >(*this).GetRandom();
        }
        T GetRandom() noexcept
        {
            return Create_Random();
        }

    private:
        T Create_Random()
        {
            return m_rand_distro(m_rand_32);
        }
        static std::mt19937& Init_Rand_With_Seed()
        {
            std::random_device rd {};
            std::seed_seq seed { static_cast< std::mt19937::result_type >(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(),
                               rd(), rd(), rd(), rd() };
            static std::mt19937 rand { seed };
            return rand;
        }

    private:
        mutable std::uniform_real_distribution<> m_rand_distro {};
        static inline std::mt19937 m_rand_32 { Init_Rand_With_Seed() };
    };
}