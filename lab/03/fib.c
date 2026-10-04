#include <stdio.h>
#include <stdlib.h>


int fib(unsigned int n) { 
    if (n < 2) { return n; }
    return fib(n - 1) + fib(n - 2);
}


int main(int argc, char *argv[]) {
    int n = (argc > 1) ? atoi(argv[1]) : 20;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i <= n; i++) {
        printf("F%d  ", i);
        printf("%d  \n", fib(i));
    }
    //int result = fib(n);
    //printf("Result: %s\n", result);

    return 0;
}