#include <stdio.h>

int count_vowels(char s[]) {
    int count = 0;
    int length = sizeof(s) / sizeof(s[0]);
    char vowels[5] = "aeiou";
    
    for (int i = 0; i < length; i++) {
        

    } 

    return count;
}

int main() {
    printf("%d\n", count_vowels("Programming is fun"));  // expect 5
    return 0;
}