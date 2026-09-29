#include <stdio.h>
#include <stdlib.h>

// Returns 1 if any two elements of a[] are equal, 0 otherwise.
int dup_chk(int a[], int length) {
    int i = length;
    while (i >= 0) {
        i --;
        int j = i - 1;
        while (j >= 0) {
            if (a[i] == a[j]) {
                return 1;
            }
            j--;
        }
    }
    return 0;
}


int main(int argc, char *argv[]) {
    int n = (argc > 1) ? atoi(argv[1]) : 20;
    int *arr = malloc(n * sizeof(int));

    // Fill with 0..n-1: every value is distinct
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int found = dup_chk(arr, n);
    printf("duplicate found: %s\n", found ? "yes" : "no");

    free(arr);
    return 0;
}