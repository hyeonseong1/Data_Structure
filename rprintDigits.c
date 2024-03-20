#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void printDigits(int n);
void rprintDigits(int n);

int main() {
    int n;

    scanf("%d", &n);
    rprintDigits(n);

    return 0;
}

void printDigits(int n) {
    if(n < 0)
        printf("Negative number\n");
    else
        rprintDigits(n);
}

void rprintDigits(int n) {
    if (n < 10)
        printf("%d\n", n);
    else {
        rprintDigits(n / 10);
        printf("%d\n", n % 10);
    }
}