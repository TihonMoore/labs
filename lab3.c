#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void newMatrix(int* pS, int** arr);
void diagSort(int* pS, int** arr);
int lab3() {
    int **arr;
    int size;
    int *pS = &size;
    printf("Enter square matrix size: ");
    scanf("%d", &*pS);
    arr = (int**)malloc(*pS * sizeof(int*));

    printf("Original matrix:\n");
    newMatrix(pS, arr);

    printf("\n\nMain diagonal sort:\n");
    diagSort(pS, arr);

    return 0;
}
void newMatrix(int* pS, int** arr){
    srand(time(0));
    for (int i = 0; i < *pS; i++) {
        arr[i] = (int*)malloc(*pS * sizeof(int*));
        for (int j = 0; j < *pS; j++) {
            arr[i][j] = rand() % (65 + 1 - 0) + 0;
        }
    }

    for (int i = 0; i < *pS; i++) {
        printf("\n");
        for (int j = 0; j < *pS; j++) {
            printf("%d ", arr[i][j]);
        }
    }

}
void diagSort(int* pS, int** arr){
    for(int j = 0; j < *pS; j++){
        for (int i = 0; i < *pS - 1; i++) {
            if (arr[i][i] < arr[i + 1][i + 1]) {
                int temp = arr[i][i];
                arr[i][i] = arr[i + 1][i + 1];
                arr[i + 1][i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < *pS; i++){
        printf("\n");
        for (int j = 0; j < *pS; j++){
            printf("%d ", arr[i][j]);
        }
    }
}
