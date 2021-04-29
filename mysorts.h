#pragma once

bool check(const int *data, const size_t size);
void output(const int *data, const size_t size, const char* name);
size_t min_ind(const int *data, const size_t size);

void selection_sort(int* data, const size_t size);
void bubble_sort(int* data, const size_t size);
void shell_sort(int* data, const size_t size);

void split(int *data, const size_t size);
void quick_sort(int* data, const size_t size);

bool in_arr(int n, int size);
int *merge(const int *a_data, size_t a_size, const int *b_data, size_t b_size, int dai, int dbi, int dci);
void twoway_merge_sort(const int* data, size_t size);