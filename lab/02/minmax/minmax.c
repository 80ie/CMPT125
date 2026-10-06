#include "lib/minmax.h"

void find_min_max(int arr[], int n, int *min_out, int *max_out) {
    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }
    *min_out = min_val;
    *max_out = max_val;
}
