#ifndef MYSORT_H
#define MYSORT_H

#include <stddef.h> // For size_t definition

// Selection sort function prototype
void select_sort(void *a[], int left, int right);

// Quick sort function prototype
void quick_sort(void *a[], int left, int right);

// Generic sort function prototype using a comparison function
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*));
int default_compare(void *a, void *b);
#endif // MYSORT_H
