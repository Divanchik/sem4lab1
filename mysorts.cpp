#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "mysorts.h"

const char* default_name = "Array";
bool check(const int *data, const size_t size) // check if array is sorted
{
    if (size < 2)
        return true;
    for (size_t i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1])
            return false;
    return true;
}

void output(const int *data, const size_t size, const char* name = nullptr) // array output
{
    if (name == nullptr)
        name = default_name;
    std::cout << name << ": [";
    for (size_t i = 0; i < size - 1; i++)
        std::cout << data[i] << ", ";
    std::cout << data[size - 1] << "]" << std::endl;
}

size_t min_index(const int *data, const size_t size) // index of minimum element
{
    size_t ind = 0;
    for (size_t i = 1; i < size; i++)
        if (data[i] < data[ind])
            ind = i;
    return ind;
}

void selection_sort(int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // algorithm
    std::cout << "Executing selection sort..." << std::endl;
    for (size_t i = 0; i < size - 1; i++)
        std::swap(data[i], data[i + min_index(data + i, size - i)]);
    // calculate runtime
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime equals zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(3) << "runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    std::cout << std::endl;
}

void bubble_sort(int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // algorithm
    std::cout << "Executing bubble sort..." << std::endl;
    for (size_t i = size; i > 1; i--)
        for (size_t j = 0; j < i - 1; j++)
            if (data[j] > data[j + 1])
                std::swap(data[j], data[j + 1]);
    // calculate runtime
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime equals zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(3) << "runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    std::cout << std::endl;
}

void shell_sort(int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // algorithm
    std::cout << "Executing shell sort..." << std::endl;
    for (size_t s = size; s > 0; s /= 2)
        for (size_t i = 0; i < size; i++)
            for (size_t j = i + s; j < size; j += s)
                if (data[i] > data[j])
                    std::swap(data[i], data[j]);
    // calculate runtime
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime equals zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(3) << "runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    std::cout << std::endl;
}

void split(int *data, const size_t size)
{
    if (check(data, size))
        return;
    size_t piv = rand() % size;
    int tmp = data[piv];
    size_t lind = 0, rind = size - 1;
    while (lind < rind)
    {
        if (data[lind] < tmp && data[rind] >= tmp)
        {
            lind++;
            rind--;
        }
        else if (data[lind] >= tmp && data[rind] < tmp)
        {
            std::swap(data[lind], data[rind]);
            lind++;
            rind--;
        }
        else if (data[lind] < tmp && data[rind] < tmp)
            lind++;
        else if (data[lind] >= tmp && data[rind] >= tmp)
            rind--;
    }
    size_t point = 0;
    while (data[point] < tmp)
        point++;
    split(data, point);
    split(data + point, size - point);
}

void quick_sort(int *data, const size_t size)
{
    std::clock_t st_time = std::clock(); // start time
    // algorithm
    std::cout << "Executing quick sort..." << std::endl;
    split(data, size);
    // calculate runtime
    std::clock_t en_time = std::clock(); // end time
    if (en_time - st_time == 0)
        std::cout << "runtime equals zero or can't be measured" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(3) << "runtime = " << 1.0 * (en_time - st_time) / CLOCKS_PER_SEC << "sec" << std::endl;
    std::cout << std::endl;
}

bool in_arr(int n, int size)
{
    if (n >= 0 && n < size)
        return true;
    return false;
}

int *merge(const int *a_data, size_t a_size, const int *b_data, size_t b_size, int dai, int dbi, int dci)
{
    size_t c_size = a_size + b_size;
    int *c_data = new int[c_size];
    // set indexes
    int ai = 0, bi = 0, ci = 0;
    if (dai == -1)
        ai = a_size - 1;
    if (dbi == -1)
        bi = b_size - 1;
    if (dci == -1)
        ci = c_size - 1;
    // algorithm
    for (; in_arr(ci, c_size); ci+=dci)
    {
        if (!(in_arr(ai, a_size)) && in_arr(bi, b_size))
        {
            c_data[ci] = b_data[bi];
            bi += dbi;
        }
        else if (in_arr(ai, a_size) && !(in_arr(bi, b_size)))
        {
            c_data[ci] = a_data[ai];
            ai += dai;
        }
        else if (a_data[ai] < b_data[bi])
        {
            c_data[ci] = a_data[ai];
            ai += dai;
        }
        else
        {
            c_data[ci] = b_data[bi];
            bi += dbi;
        }
    }
    return c_data;
}

void twoway_merge_sort(const int *data, size_t size)
{
    // copy initial array
    auto res = new int[size];
    std::memcpy(res, data, size * sizeof(int));
    auto buf = new int[size];
    int* merged;
    int* cache = new int[size];
    std::memcpy(cache, res, size * sizeof(int));
    while (true)
    {
        // search sequences
        size_t asc = 0;
        size_t desc = size - 1;
        for (; res[asc] < res[asc + 1]; asc++);
        for (; res[desc - 1] > res[desc]; desc--);
        // merge sequences
        size_t smerg_len = size - desc + asc + 1;                        // straight merge length
        merged = merge(res, asc + 1, res + desc, size - desc, 1, -1, 1); // merge
        output(merged, smerg_len, "straight merge");                     // straight merge output
        std::memcpy(buf, merged, smerg_len * sizeof(int));               // copy merge to buf
        delete[] merged;
        // search sequences
        auto st = ++asc;
        auto en = --desc;
        for (; res[asc] < res[asc + 1]; asc++);
        for (; res[desc - 1] > res[desc]; desc--);
        // merge sequences
        size_t bmerg_len = asc - st + 1 + en - desc + 1;                              // backwards merge lenght
        merged = merge(res + st, asc - st + 1, res + desc, en - desc + 1, 1, -1, -1); // merge
        output(merged, bmerg_len, "backwards merge");                                 // backwards merge output
        std::memcpy(buf + size - bmerg_len, merged, bmerg_len * sizeof(int));         // copy merge to buf
        delete[] merged;
        // everything else
        std::memcpy(buf + smerg_len, res + asc + 1, (desc - asc - 1) * sizeof(int));
        output(buf, size, "buf");
        std::cout << std::endl;
        std::memcpy(res, buf, size * sizeof(int));
        // error check
        if (!check(res, size) && memcmp(cache, res, size) == 0)
        {
            std::cout << "Error: cache == res but res is NOT sorted!" << std::endl;
            return;
        }
        else
            std::memcpy(cache, res, size * sizeof(int));
    }
    output(res, size, "res");
}