#include <stdio.h>
#include "lib/minmax.h"

int main() {
    int arr[6] = {7, 2, 9, 4, 1, 8};
    int lo, hi;
    find_min_max(arr, 6, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
    return 0;
}
