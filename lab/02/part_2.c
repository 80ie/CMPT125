#include <stdio.h>

int flip() {
    int a = 0;
    unsigned int b = a;   // same bits, reinterpreted
    printf("a = %d\n", a);
    printf("b = %u\n", b);   // %u prints unsigned
    return 0;
}
// RESULT: <write your result here for later reference>
// a = -1     b = 4294967295
// a = -2     b = 4294967294
// a = 0      b = 0

int main() {
    double sum = 0.1 + 0.2;
    printf("%.17f\n", sum);           // print with 17 digits of precision
    printf("%s\n", sum == 0.3 ? "equal" : "NOT equal");
    return 0;
} 
// 0.30000000000000004
// NOT equal

