#pragma once
#include <memory>
#include <iostream>

namespace cpp
{

    template <typename Iterator>
    void merge(Iterator a_start, Iterator a_end, Iterator b_start, Iterator b_end, Iterator c_data, bool fwd)
    {
        --b_end;
        --b_start;
        while (a_start != a_end || b_start != b_end)
        {
            if (a_start == a_end && b_start != b_end)
            {
                *c_data = *b_end;
                --b_end;
            }
            else if (a_start != a_end && b_start == b_end)
            {
                *c_data = *a_start;
                ++a_start;
            }
            else if (*a_start < *b_end)
            {
                *c_data = *a_start;
                ++a_start;
            }
            else
            {
                *c_data = *b_end;
                --b_end;
            }
            if (fwd)
                ++c_data;
            else
                --c_data;
        }
    }

    template <typename Iterator>
    void mergesort(Iterator data, Iterator data_end, Iterator buffer, Iterator buffer_end)
    {
        while (true)
        {
            Iterator left = data;
            Iterator right = data_end;
            --right;
            while (*left < *(++left))
                std::cout << "left: " << *left << std::endl;
            while (*right < *(--right))
                std::cout << "right: " << *right << std::endl;
            merge(data, ++left, right, data_end, buffer, true);
            break;
        }
    }
}