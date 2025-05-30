#include "mysort.h"

// Function to swap two elements
static void swap(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare integers pointed by two pointers
static int default_compare(void *a, void *b) {
    int x = *((int *)a);
    int y = *((int *)b);
    return (x > y) - (x < y);
}

// Selection sort implementation
void select_sort(void *a[], int left, int right) {
    for (int i = left; i < right; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= right; j++) {
            if (default_compare(a[j], a[min_idx]) < 0) {
                min_idx = j;
            }
        }
        swap(&a[i], &a[min_idx]);
    }
}

// Helper function for quicksort (partition)
static int partition(void *a[], int left, int right, int (*cmp)(void*, void*)) {
    void *pivot = a[right];
    int i = (left - 1);
    for (int j = left; j < right; j++) {
        if (cmp(a[j], pivot) <= 0) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[right]);
    return (i + 1);
}

// Quick sort implementation
void quick_sort(void *a[], int left, int right) {
    if (left < right) {
        int pi = partition(a, left, right, default_compare);
        quick_sort(a, left, pi - 1);
        quick_sort(a, pi + 1, right);
    }
}

// Generic sort using a comparison function
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)) {
    // Implementing quick sort using the custom comparison function
    if (left < right) {
        int pi = partition(a, left, right, cmp);
        my_sort(a, left, pi - 1, cmp);
        my_sort(a, pi + 1, right, cmp);
    }
}
