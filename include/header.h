
#include <vector>
#include <iostream>


// 2 2 1

struct stats
{
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

stats SelectionSort(std::vector<int>&v);



int partition(std::vector<int>& arr, int low, int high, stats& s);

void QuickSort(std::vector<int>& arr, int low, int high, stats& s);

stats QuickSort(std::vector<int>& arr);