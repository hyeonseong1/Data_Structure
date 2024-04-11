#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int *X, int n) {
    int sum;
    int *A = NULL;  //output

    A = (int *)malloc(sizeof(int) * n);
    if (A == NULL) return -1;

    for (int i = 0; i < n; i++) {   //range expression difference between 
        sum = 0;                    //C(include last digit) & pseudo code(not include last digit)
        for (int j = 0; j < i + 1; j++) {
            sum += X[j];
        }
        A[i] = (int)(sum / (double)(i + 1) + 0.5);  //rounding by integer
    }

    return A;
}

int* prefixAverages2(int *X, int n) {
    int sum = 0;
    int *A = NULL;

    A = (int *)malloc(sizeof(int) * n);
    if (A == NULL) return -1;

    for (int i = 0; i < n; i++) {   //very simple??
        sum += X[i];
        A[i] = (int)(sum / (double)(i + 1) + 0.5);
    }

    return A;
}

int main() {
    int n;  //arr x's size
    int *X = NULL;  //input
    int *A1 = NULL, *A2 = NULL; //output

    scanf("%d", &n);
    X = (int *)malloc(sizeof(int) * n);
    if (X == NULL) return -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    A1 = prefixAverages1(X, n);
    A2 = prefixAverages2(X, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A1[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A2[i]);
    }
    printf("\n");

    free(A2);
    free(A1);
    free(X);

    return 0;
}
