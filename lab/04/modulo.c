#include <stdio.h>
#include <stdlib.h>  // for strtol


int mystery(int n) { 
    if (n == 0) {
        return 0;
    }
    return (n % 10) + mystery(n / 10);
}

int main() {
    int n;
    scanf("mystery(%d)", &n);
    printf(" = %d\n", mystery(n));
}