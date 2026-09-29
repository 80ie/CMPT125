#include <stdio.h>
#include <stdlib.h>


int fib(int n) { 
    if (n < 2) { return n; }
    int Fn = fib(n - 1) + fib(n - 2);
    return Fn;


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