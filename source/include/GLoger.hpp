///Copyright(c) 2023 Alireza Ahani all rigth reserved
///MIT License
/// 

#pragma once

namespace AE
{
	namespace GPuzzle
	{
		namespace GLoger
		{
#define BGCOLOR(b)\
std::cout<<b

#define FGCOLOR(f)\
std::cout<<f

#define LOG(a) std::cout << a
#define LOG_N(a) std::cout << a << '\n'
#define LOG_DN(a) std::cout << #a << "=" << a << '\n'
#define LOG_D(a) std::cout << #a << "=" << a
#define LOG_CODE(a) \
((int)a>0)? std::cout << "Succses ":((int)a==0)?std::cout <<"END ":std::cout <<"Failed "
#define LOG_FN(n)               \
    for (int i = 0; i < n; ++i) \
    std::cout << '\n';
#define WAIT() std::cin.get()
#define CLS() system("CLS")


		}
	}
}