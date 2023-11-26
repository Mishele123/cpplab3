
#include "header.h"


stats sort(std::vector<int>& v)
{

	stats a;

	for (auto& i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	size_t n = v.size();

	for (size_t i = 0; i < n - 1; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < n; j++)
		{
			a.comparison_count++;
			if (v[minIndex] > v[j])
				minIndex = j;
		}
		if (i != minIndex)
		{
			std::swap(v[minIndex], v[i]);
			a.copy_count += 2;
		}
	}

	for (auto& i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::cout << "comparison_count = " << a.comparison_count << std::endl;
	std::cout << "copy_count = " << a.copy_count << std::endl;
	return a;
}
