#include "Engine_PCH.hpp"
#include "GHelper.hpp"
namespace A_E
{
	namespace GPuzzle::GHelper
	{
		int GHelper::Whatis_Y(int index, int width)
		{
			return (index / width == 1.0) ? 1 : ((index / width > 1.0) ? index / width : 0);
		}
		int GHelper::Whatis_X(int index, int width)
		{
			return index - (width * Whatis_Y(index, width));
		}
		int GHelper::Whatis_index(int width, int x, int y)
		{
			return x + (width * y);
		}
	}
}