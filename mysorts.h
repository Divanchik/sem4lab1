#pragma once

bool check(const int *data, const size_t size);
void output(const int *data, const size_t size);
int min_int(const int *data, const size_t size);
size_t min_ind(const int *data, const size_t size);

void selection_sort(const int* data, const size_t size);
void bubble_sort(const int* data, const size_t size);
void shell_sort(const int* data, const size_t size);
void quick_sort(const int* data, const size_t size);