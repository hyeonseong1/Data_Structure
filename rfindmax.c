#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void rfindMax(int n, int arr[], int max);

int main() {
    int n, max;
    int arr[20];

    scanf("%d", &n);    //n<=20;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[n-1];
    rfindMax(n, arr, max);

    return 0;
}

void rfindMax(int n, int arr[20], int max) {
    if(n == 0) {
        printf("%d\n", max);
    }
    else {
        if(max < arr[n-1]) {
            max = arr[n-1];
        }
        rfindMax(n-1, arr, max);
    }
}