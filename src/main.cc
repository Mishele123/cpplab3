

#include "header.h"
#include <random>
#include <string>

// 1 2 2 3 4 4

template <typename T>
std::vector<T> generateRandomVector(size_t size)
{
    std::vector<T> arr(size);
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<T> distr(0, 999);

    for (auto &i : arr)
    {
        i = distr(generator);
    }

    return arr;
}

template <typename T>
std::vector<T> generateSortedVector(size_t size)
{
    std::vector<T> arr(size);
    for (size_t i = 0; i < size; i++)
    {
        arr.push_back(static_cast<T>(i));
    }
    return arr;
}

template <typename T>
std::vector<T> generateReverseSortedVector(size_t size)
{
    std::vector<T> arr;
    for (size_t i = size - 1; int(i) >= 0; --i)
    {
        arr.push_back(static_cast<T>(i));
    }
    return arr;
}

int main() 
{
    std::vector<size_t> vector_lenghts = { 1000, 2000, 3000, 4000, 5000, 6000,
        7000, 8000, 9000, 10000, 25000, 50000 };

    //size_t count = 100;

    //for (size_t &size : vector_lenghts)
    //{   
    //    size_t comparison_count_average = 0;
    //    size_t copy_count_average = 0;

    //    for (size_t i = 0; i < count; i++)
    //    {
    //        std::vector<int> randomVector = generateRandomVector<int>(size);

    //        stats s;

    //        s = NaturalMergeSort(randomVector);


    //        /*std::cout << "Lenght = " << size << std::endl;
    //        std::cout << "Size arr = " << randomArray.size() << std::endl;
    //        std::cout << "Number of comparisons: " << s.comparison_count << std::endl;
    //        std::cout << "Number of copies: " << s.copy_count << std::endl;*/

    //        comparison_count_average += s.comparison_count;
    //        copy_count_average += s.copy_count;
    //    }

    //    comparison_count_average /= count;
    //    copy_count_average /= count;

    //    
    //    std::cout << "For vector size = " << size << std::endl;
    //    std::cout << "comparison_count_average = " << comparison_count_average << std::endl;
    //    std::cout << "copy_count_average = " << copy_count_average << std::endl;
    //    
    //    // Для отсортированного
    //    /*stats s1;
    //    std::vector<int> arr1 = generateSortedVector(size);
    //    s1 = NaturalMergeSort(arr1);
    //    std::cout << "generateSortedArray = " << size << std::endl;
    //    std::cout << "comparison_count_average = " << s1.comparison_count << std::endl;
    //    std::cout << "copy_count_average = " << s1.copy_count << std::endl;*/

    //    // Для реверснутого
    //    /*stats s2;
    //    std::vector<int> arr2 = generateReverseSortedVector(size);
    //    s2 = NaturalMergeSort(arr2);
    //    std::cout << "generateSortedArray = " << size << std::endl;
    //    std::cout << "comparison_count_average = " << s2.comparison_count << std::endl;
    //    std::cout << "copy_count_average = " << s2.copy_count << std::endl;*/
    //}

    /*std::vector<std::string> vec = { "banana", "apple", "abple", "orange", "grape", "kiwi"};

    for (auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    SelectionSort(vec);

    for (auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;*/

    std::vector<CustomClass> vec = { CustomClass(5), CustomClass(4), CustomClass(2), CustomClass(1), CustomClass(0) };
    for (auto& i : vec)
    {
        std::cout << i._value << " ";
    }
    std::cout << std::endl;

    SelectionSort(vec);

    for (auto& i : vec)
    {
        std::cout << i._value << " ";
    }


    return 0;
}




//For vector size = 1000
//comparison_count_average = 499500
//copy_count_average = 1983
//For vector size = 2000
//comparison_count_average = 1999000
//copy_count_average = 3981
//For vector size = 3000
//comparison_count_average = 4498500
//copy_count_average = 5979
//For vector size = 4000
//comparison_count_average = 7998000
//copy_count_average = 7976
//For vector size = 5000
//comparison_count_average = 12497500
//copy_count_average = 9974
//For vector size = 6000
//comparison_count_average = 17997000
//copy_count_average = 11972
//For vector size = 7000
//comparison_count_average = 24496500
//copy_count_average = 13972
//For vector size = 8000
//comparison_count_average = 31996000
//copy_count_average = 15970
//For vector size = 9000
//comparison_count_average = 40495500
//copy_count_average = 17968
//For vector size = 10000
//comparison_count_average = 49995000
//copy_count_average = 19965
//For vector size = 25000
//comparison_count_average = 312487500
//copy_count_average = 49934



    //for (auto& i : arr)
    //{
    //    std::cout << i << " ";
    //}
    //std::cout << std::endl;

    //stats s;

    //s = NaturalMergeSort(arr);

    //// s = SelectionSort(arr);

    //std::cout << "Sorted array: ";

    //for (auto &i : arr)
    //{
    //    std::cout << i << " ";
    //}
    //std::cout << std::endl;

    /*std::cout << "Size arr = " << arr.size() << std::endl;
    std::cout << "Number of comparisons: " << s.comparison_count << std::endl;
    std::cout << "Number of copies: " << s.copy_count << std::endl;*/