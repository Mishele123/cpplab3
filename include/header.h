
#include <vector>
#include <iostream>


// 2 2 1

struct stats
{
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

stats SelectionSort(std::vector<int>&v);



size_t partition(std::vector<int>& arr, size_t low, size_t high, stats& s);

void QuickSort(std::vector<int>& arr, size_t low, size_t high, stats& s);

stats QuickSort(std::vector<int>& arr);

void merge(std::vector<int>& arr, size_t left, size_t middle, size_t right, stats& s);
void NaturalMergeSort(std::vector<int>& arr, size_t left, size_t right, stats& s);

stats NaturalMergeSort(std::vector<int>& arr);