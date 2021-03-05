#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "mysorts.h"

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
    for (int i = 0; i < SIZE - 1; i++)
        std::swap(a[i], a[i + rand() % (SIZE - i)]);

    selection_sort(a, SIZE);
    bubble_sort(a, SIZE);
    shell_sort(a, SIZE);
    quick_sort(a, SIZE);

    int a1[] = {5, 3, 0};
    int b1[] = {4, 2, 1};
    int* c = merge(a1,3,b1,3, false, false, false);
    std::cout << std::endl;
    for (int i=0;i<5;i++)
        std::cout << c[i] << ", ";
    std::cout << c[5] << std::endl;

    std::clock_t en_time = std::clock();
    std::cout << std::fixed << std::setprecision(4) << "program runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    return 0;
}