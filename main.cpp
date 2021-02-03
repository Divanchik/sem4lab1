#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mysorts.h"
#define SIZE 10

int main()
{
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
    std::cout << "Program is over!" << std::endl;
    //getchar();
    return 0;
}