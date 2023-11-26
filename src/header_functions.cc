
#include "header.h"

// ���������� ������� 
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


// ������� ����������
size_t partition(std::vector<int>& arr, size_t low, size_t high, stats& s) 
{
	int pivot = arr[high];
	size_t i = low;

	for (size_t j = low; j < high; j++) 
	{
		s.comparison_count++;
		if (arr[j] < pivot) 
		{
			std::swap(arr[i], arr[j]);
			s.copy_count += 2;
			i++;
		}
	}

	std::swap(arr[i], arr[high]);
	s.copy_count += 2;

	return i;
}

void QuickSort(std::vector<int>& arr, size_t low, size_t high, stats& s)
{
	if (low < high) {
		size_t pivotIndex = partition(arr, low, high, s);

		if (pivotIndex > 0) 
		{
			QuickSort(arr, low, pivotIndex - 1, s);
		}

		QuickSort(arr, pivotIndex + 1, high, s);
	}
}

stats QuickSort(std::vector<int>& arr)
{
    stats s;
    size_t n = arr.size();
    QuickSort(arr, 0, n - 1, s);
    return s;
}

// ���������� ����������� ��������

stats NaturalMergeSort(std::vector<int>& array)
{
	stats s;

	return s;
}