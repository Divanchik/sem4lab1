#include <iostream>
#include <cstdlib>
#include "mysorts.h"

bool check(const int *data, const size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1])
            return false;
    return true;
}

void output(const int *data, const size_t size)
{
    std::cout << "[";
    for (size_t i = 0; i < size - 1; i++)
        std::cout << data[i] << ", ";
    std::cout << data[size - 1] << "]" << std::endl;
}

int min_int(const int *data, const size_t size)
{
    int min = data[0];
    for (size_t i = 1; i < size; i++)
        if (data[i] < min)
            min = data[i];
    return min;
}

size_t min_ind(const int *data, const size_t size)
{
    size_t ind = 0;
    for (size_t i = 1; i < size; i++)
        if (data[i] < data[ind])
            ind = i;
    return ind;
}

void selection_sort(const int *data, const size_t size)
{
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    std::cout << "Executing selection sort..." << std::endl;
    for (size_t i = 0; i < size - 1; i++)
    {
        std::swap(res[i], res[i + min_ind(res+i, size - i)]);
        if (check(res, size))
           break;
    }
    std::cout << "Done!" << std::endl;
    output(res,size);
}

void bubble_sort(const int* data, const size_t size)
{
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    std::cout << "Executing bubble sort..." << std::endl;
    for (size_t i = size;i>1;i--)
    {
        if (check(res, size))
            break;
        for(size_t j = 0;j<i-1;j++)
            if (res[j] > res[j+1])
                std::swap(res[j], res[j+1]);
    }
    std::cout << "Done!" << std::endl;
    output(res, size);
}

void shell_sort(const int* data, const size_t size)
{
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    std::cout << "Executing shell sort..." << std::endl;
    for (size_t s  = size;s > 0;s /= 2)
        for (size_t i = 0;i < size;i++)
            for (size_t j = i+s;j < size; j+= s)
                if (res[i] > res[j])
                    std::swap(res[i], res[j]);
    std::cout << "Done!" << std::endl;
    output(res, size);
}

void quick_sort(const int* data, const size_t size)
{
    auto res = new int[size];
    for (size_t i = 0; i < size; i++)
        res[i] = data[i];
    std::cout << "Executing quick sort..." << std::endl;
    size_t piv = rand() % size;
    std::cout << "Pivot: res[" << piv << "] = " << res[piv] << std::endl;
    size_t lind = 0, rind = size - 1;
    while (lind != rind)
    {
        std::cout << "start_of_cycle" << std::endl;
        output(res, size);
        std::cout << "Check: " << lind << " " << rind << std::endl;
        if (res[lind] < res[piv] && res[rind] >= res[piv])
        {
            std::cout << res[lind] << " < " << res[piv] << " && " << res[rind] << " >= " << res[piv] << std::endl;
            lind++;
            rind--;
        }
        else if (res[lind] >= res[piv] && res[rind] < res[piv])
        {
            std::cout << res[lind] << " >= " << res[piv] << " && " << res[rind] << " < " << res[piv] << std::endl;
            std::swap(res[lind], res[rind]);
            lind++;
            rind--;
        }
        else if (res[lind] < res[piv] && res[rind] < res[piv])
        {
            std::cout << res[lind] << " < " << res[piv] << " && " << res[rind] << " < " << res[piv] << std::endl;
            lind++;
        }
        else if (res[lind] >= res[piv] && res[rind] >= res[piv])
        {
            std::cout << res[lind] << " >= " << res[piv] << " && " << res[rind] << " >= " << res[piv] << std::endl;
            rind--;
        }
        output(res,size);
        std::cout << "end_of_cycle\n\n" << std::endl;
    }
    //output(res,size);
}