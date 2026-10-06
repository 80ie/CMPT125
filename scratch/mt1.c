#include <stdio.h>
#include <string.h>

// CORRECT
void q1(){
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a + 1;

    // prints 40
    printf("%d\n", *(p + 2));
}

// CORRECT
void q2(){
    int total = 7;
    float avg = total / 2;
    printf("%.1f\n", avg);
}

int is_palindrome(char s[]) {
    int n = strlen(s);

    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 - i]){
            return 0;
        }
    }
    return 1;
}

void a1(){
    int x = 5;
    int *p = &x;
    *p = *p * 2;
    printf("%d %d\n", x, *p);
}


int main() {
    a1(); 
    printf("%.1f\n", (float)7 / 2);
    printf("%.1f\n", (float)(7 / 2)); 
    
    return 0;
}