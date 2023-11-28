
#include <vector>
#include <iostream>


// 2 2 1

struct stats
{
	size_t comparison_count = 0;
	size_t copy_count = 0;
};


class CustomClass
{
public:
	int _value;
	CustomClass(int value) : _value(value) {}

	bool operator<(const CustomClass& other) const
	{
		return _value < other._value;
	}
	bool operator>(const CustomClass& other) const
	{
		return !(_value < other._value);
	}
};

// Сортировка выбором
template <typename T>
stats SelectionSort(std::vector<T>& v)
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
	return a;
}


// Быстрая сортировка
template <typename T>
size_t partition(std::vector<T>& arr, size_t low, size_t high, stats& s)
{
	T pivot = arr[high];
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

template <typename T>
void QuickSort(std::vector<T>& arr, size_t low, size_t high, stats& s)
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

template <typename T>
stats QuickSort(std::vector<T>& arr)
{
	stats s;
	size_t n = arr.size();
	QuickSort(arr, 0, n - 1, s);
	return s;
}


// Сортировка слиянием
template <typename T>
stats NaturalMergeSort(std::vector<T>& arr)
{
	stats s;
	MergeSort(arr, 0, arr.size() - 1, s);
	return s;
}

template <typename T>
void MergeSort(std::vector<T>& arr, size_t left, size_t right, stats& s)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		MergeSort(arr, left, mid, s);
		MergeSort(arr, mid + 1, right, s);
		merge(arr, left, mid, right, s);
	}
}

template <typename T>
void merge(std::vector<T>& arr, size_t left, size_t middle, size_t right, stats& s)
{
	size_t i = left;
	size_t j = middle + 1;
	std::vector<T> temp;
	while (i <= middle && j <= right)
	{
		s.comparison_count++;
		if (arr[i] < arr[j])
		{
			temp.push_back(arr[i++]);
			s.copy_count++;
		}
		else
		{
			temp.push_back(arr[j++]);
			s.copy_count++;
		}
	}

	while (i <= middle)
	{
		temp.push_back(arr[i++]);
		s.copy_count++;
	}
	while (j <= right)
	{
		temp.push_back(arr[j++]);
		s.copy_count++;
	}

	for (size_t i = left; i <= right; i++)
	{
		arr[i] = temp[i - left];
		s.copy_count++;
	}
}
