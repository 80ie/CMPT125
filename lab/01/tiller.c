#include <stdio.h>

int main() {
    int price;
    int paid;
    int total;
    int change;

    printf("Price (cents): ");
    scanf("%d", &price);

    printf("Customer paid (cents): ");
    scanf("%d", &paid);

    if (paid/price < 1.0) {
        printf("The customer is short %d cents.", price-paid);
    } else {
        total = price-paid;
        printf("total leftover: %d", &total);
        printf("$2 - %d", total/200);
        
    }

}