#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "mysorts.h"
#define SIZE 1000

int main()
{
    std::clock_t st_time = std::clock();
    srand(time(NULL));
    auto a = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        a[i] = i;
    for (int i = 0; i < SIZE - 1; i++)
        std::swap(a[i], a[i + rand() % (SIZE - i)]);
    
    std::cout << "Initial array: ";
    output(a, SIZE);
    selection_sort(a, SIZE);
    bubble_sort(a, SIZE);
    shell_sort(a, SIZE);
    quick_sort(a, SIZE);

    std::clock_t en_time = std::clock();
    std::cout << std::fixed << std::setprecision(4) << "program runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    return 0;
}