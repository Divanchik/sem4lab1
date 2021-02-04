#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "mysorts.h"

bool check(const int *data, const size_t size) // check if array is sorted
{
    if (size < 2)
        return true;
    for (size_t i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1])
            return false;
    return true;
}

void output(const int *data, const size_t size) // array output
{
    std::cout << "[";
    for (size_t i = 0; i < size - 1; i++)
        std::cout << data[i] << ", ";
    std::cout << data[size - 1] << "]" << std::endl;
}

int min_int(const int *data, const size_t size) // minimum element
{
    int min = data[0];
    for (size_t i = 1; i < size; i++)
        if (data[i] < min)
            min = data[i];
    return min;
}

size_t min_ind(const int *data, const size_t size) // index of minimum element
{
    size_t ind = 0;
    for (size_t i = 1; i < size; i++)
        if (data[i] < data[ind])
            ind = i;
    return ind;
}

void selection_sort(const int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // creating copy of initial array
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    // algorithm
    std::cout << "Executing selection sort..." << std::endl;
    for (size_t i = 0; i < size - 1; i++)
        std::swap(res[i], res[i + min_ind(res + i, size - i)]);
    std::cout << "Result: ";
    output(res, size);

    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime is equal zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4) << "runtime = " << 1.0 * (en_time-st_time)/CLOCKS_PER_SEC << "sec" << std::endl;

    std::cout << std::endl;
}

void bubble_sort(const int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // creating copy of initial array
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    // algorithm
    std::cout << "Executing bubble sort..." << std::endl;
    for (size_t i = size; i > 1; i--)
    {
        if (check(res, size))
            break;
        for (size_t j = 0; j < i - 1; j++)
            if (res[j] > res[j + 1])
                std::swap(res[j], res[j + 1]);
    }
    std::cout << "Result: ";
    output(res, size);

    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime is equal zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4) << "runtime = " << 1.0 * (en_time-st_time)/CLOCKS_PER_SEC << "sec" << std::endl;

    std::cout << std::endl;
}

void shell_sort(const int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // creating copy of initial array
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    // algorithm
    std::cout << "Executing shell sort..." << std::endl;
    for (size_t s = size; s > 0; s /= 2)
        for (size_t i = 0; i < size; i++)
            for (size_t j = i + s; j < size; j += s)
                if (res[i] > res[j])
                    std::swap(res[i], res[j]);
    std::cout << "Result: ";
    output(res, size);
    
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime is equal zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4) << "runtime = " << 1.0 * (en_time-st_time)/CLOCKS_PER_SEC << "sec" << std::endl;

    std::cout << std::endl;
}

void split(int* data, const size_t size)
{
    if (check(data, size))
        return;
    size_t piv = rand() % size;
    int tmp = data[piv];
    // std::cout << "Pivot: res[" << piv << "] = " << data[piv] << std::endl;
    size_t lind = 0, rind = size - 1;
    while (lind < rind)
    {
        if (data[lind] < data[piv] && data[rind] >= data[piv])
        {
            lind++;
            rind--;
        }
        else if (data[lind] >= data[piv] && data[rind] < data[piv])
        {
            std::swap(data[lind], data[rind]);
            lind++;
            rind--;
        }
        else if (data[lind] < data[piv] && data[rind] < data[piv])
            lind++;
        else if (data[lind] >= data[piv] && data[rind] >= data[piv])
            rind--;
    }
    size_t point = 0;
    while(data[point] < tmp) point++;
    split(data, point);
    split(data+point, size-point);
}

void quick_sort(const int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // creating copy of initial array
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    // algorithm
    std::cout << "Executing quick sort..." << std::endl;
    split(res, size);
    std::cout << "Result: ";
    output(res, size);
    
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime is equal zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(4) << "runtime = " << 1.0 * (en_time-st_time)/CLOCKS_PER_SEC << "sec" << std::endl;

    std::cout << std::endl;
}