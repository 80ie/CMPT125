#include <stdio.h>

void reverse(int arr[], int n) {
    int * first = arr;
    int * last = arr + n; 
    int * until = arr + n / 2;

    for (int * i = first; i <= until; i++) {
        int mirror = last - i;
        arr[mirror-1] = *i;
        *i = mirror;
    }
    
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, n);

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}