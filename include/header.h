
#include <vector>
#include <iostream>


// 2 2 1

struct stats
{
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

stats SelectionSort(std::vector<int>&v);