#include <stdio.h>
#include <string.h>

int main() {
    char password[4] = "abc";
    char answer[4];

    printf("Enter 3-char code: ");
    scanf("%4s", answer);
    if (strcmp(password, answer) != 0) {
        printf("Incorrect password!\n");
    }
}