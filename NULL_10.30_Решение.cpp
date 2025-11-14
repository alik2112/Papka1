//////////////////////////////////////////////////////////////////////////////////////

// support : www.cs.usfca.edu/~galles/visualization/DPLCS.html

//////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

//////////////////////////////////////////////////////////////////////////////////////

auto find(std::vector < int > const & a, std::vector < int > const & b) 
{
	auto size_a = std::size(a);   // беззнаковый тип

	auto size_b = std::size(b);

	std::vector < std::vector < std::size_t > > ans
	(
		size_a + 1, std::vector < std::size_t > 
		(
			size_b + 1, 0  // базовый случай 0,0 поэтому индексация с 1
		)
	);

	for (auto i = 1uz; i < size_a + 1; ++i)   /// суффикс для size_t
	{
		for (auto j = 1uz; j < size_b + 1; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				ans[i][j] = ans[i - 1][j - 1] + 1;   // динамика
			}
			else
			{
				ans[i][j] = std::max(ans[i - 1][j], ans[i][j - 1]);
			}
		}
	}

	std::vector < int > main_vector;

	auto i = std::ssize(a) - 1, j = std::ssize(b) - 1;  // знаковый тип чтобы избежать переполнения при --

	while (i >= 0 && j >= 0)
	{
		if (a[i] == b[j])
		{
			main_vector.push_back(a[i]);
			
			--i;
			
			--j;
		}
		else 
		{
			ans[i][j + 1] > ans[i + 1][j] ? --i : --j;  // тернарное выражение
		}
	}

	std::ranges::reverse(main_vector);  // переворачиваем
	
	return main_vector;
}

//////////////////////////////////////////////////////////////////////////////////////

int main()
{
	assert(find({ 1, 2, 3, 4, 5 }, { 1, 2, 3 }) == std::vector < int > ({ 1, 2, 3 }));
}

////////////////////////////////////////////////////////////////////////////////////// что здесь происхожит