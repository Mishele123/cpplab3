

#include "header.h"
#include <random>

// 1 2 2 3 4 4




int main() {
    std::vector<int> arr = { 9, 5, 2, 2, 7, 1, 8, 3, 3 };


    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distr(0, INT_MAX);

    for (int n = 0; n < 1000; ++n) 
    {
        arr.push_back(distr(generator));
    }


    for (auto& i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    stats s;
    // s = QuickSort(arr);

    s = SelectionSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Size arr = " << arr.size() << std::endl;
    std::cout << "Number of comparisons: " << s.comparison_count << std::endl;
    std::cout << "Number of copies: " << s.copy_count << std::endl;
    

    return 0;
}