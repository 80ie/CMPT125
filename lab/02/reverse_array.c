#include <stdio.h>

void reverse(int arr[], int n) {
    int * first = arr;
    int * last = arr + n;
    for (int * i = first; i < last - n/2; i++) {
        int tmp = last-i;
        arr[tmp-1] = *i;
        arr[*i-1] = tmp;
    
        printf("[i] %d  ", i);
        printf("[*i] %d  ", *i);
        printf("[&i] %d  ", &i);
        printf("[tmp] %d    ", tmp);
        printf("arr[tmp] %d\n", arr[tmp-1]);
    }
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    reverse(arr, 6);
    for (int i = 0; i < 6; i++) 
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}