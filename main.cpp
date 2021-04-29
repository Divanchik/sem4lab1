#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "mysorts.h"
#include "mergesort.h"

void shuffle (int* data, size_t size)
{
    for (int i = 0; i < size - 1; i++)
        std::swap(data[i], data[i + rand() % (size - i)]);
}

int main()
{
    std::clock_t st_time = std::clock();
    size_t SIZE;
    std::cout << "SIZE: ";
    std::cin >> SIZE;
    srand(time(NULL));
    auto a = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        a[i] = i;
    
    shuffle(a, SIZE);
    selection_sort(a, SIZE);
    shuffle(a, SIZE);
    bubble_sort(a, SIZE);
    shuffle(a, SIZE);
    shell_sort(a, SIZE);
    shuffle(a, SIZE);
    quick_sort(a, SIZE);

    std::clock_t en_time = std::clock();
    std::cout << std::fixed << std::setprecision(4) << "program runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    return 0;
}