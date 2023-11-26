
#include "header.h"


stats SelectionSort(std::vector<int>& v)
{

	stats a;

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


int partition(std::vector<int>& arr, int low, int high, stats& s)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        s.comparison_count++;
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
            s.copy_count += 2;
        }
    }


    std::swap(arr[i + 1], arr[high]);
    s.copy_count += 2;

    return i + 1;
}

void QuickSort(std::vector<int>& arr, int low, int high, stats& s)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, s);
        QuickSort(arr, low, pivotIndex - 1, s);
        QuickSort(arr, pivotIndex + 1, high, s);
    }
}

stats QuickSort(std::vector<int>& arr)
{
    stats s;
    int n = arr.size();
    QuickSort(arr, 0, n - 1, s);
    return s;
}

