#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergesort_sort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesort_sort(array, l, m);
        mergesort_sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

void mergesort_sort_wrapper(int array[], int size){
    mergesort_sort(array, 0, size-1);
}