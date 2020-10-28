#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void firstMatrix(int size, int arr_1[][size]);
void secondMatrix(int size, int arr_2[][size]);
void maxValues(int size, int arr_2[][size]);
void matrixA(int size, int arr_1[][size], int arr_2[][size], int arr_a[][size]);
void elements(int size, int arr_2[][size], int multElement[]);
void matrixB(int size, int arr_a[][size], int multElements[], int arr_b[][size]);
int lab5() {

    int size;

    printf("Enter matrix size: ");
    scanf("%d", &size);

    int arr_1[size][size];
    int arr_2[size][size];
    int arr_a[size][size];
    int multElements[size];
    int arr_b[size][size];

    printf("\nFirst matrix: ");
    firstMatrix(size, arr_1);

    printf("\n\nSecond matrix: ");
    secondMatrix(size, arr_2);

    printf("\n\nMaximum column values of the second matrix: ");
    maxValues(size, arr_2);

    printf("\n\nMatrix A: ");
    matrixA(size, arr_1, arr_2, arr_a);

    printf("\n\nElements:");
    elements(size, arr_2, multElements);

    printf("\n\nMatrix B:");
    matrixB(size, arr_a, multElements, arr_b);
    return 0;
}
void firstMatrix(int size, int arr_1[][size]){


    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr_1[i][j] = rand() % (65 + 1 - 0) + 0;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("\n");
        for (int j = 0; j < size; j++) {
            printf("%d ", arr_1[i][j]);
        }
    }
}
void secondMatrix(int size, int arr_2[][size]){


    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr_2[i][j] = rand() % (64 + 1 - 0) + 0;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("\n");
        for (int j = 0; j < size; j++) {
            printf("%d ", arr_2[i][j]);
        }
    }
}
void maxValues(int size, int arr_2[][size]){

    for (int i=0; i<size; i++) {
        int max = arr_2[i][0];
        for (int j=1; j<size; j++)
            if (arr_2[i][j] > max)
                max = arr_2[i][j];
        printf("%d ", max);
    }

}
void matrixA(int size, int arr_1[][size], int arr_2[][size], int arr_a[][size]){

    int min = 0;
    for(int j=0;j<size;j++){
        for(int i=0;i<size;i++){
            if(min > arr_2[j][i]) {
                min = arr_2[j][i];
            }
        }
    }
    int max;
    for(int j=0;j<size;j++){
        printf("\n");
        for(int i=0;i<size;i++){
            max = min;
            for(int l=0;l<size;l++){
                if(arr_2[j][l] > max) {
                    max = arr_2[j][l];
                }
            }
            arr_a[j][i] = arr_1[j][i] * max;
            printf("%d ", arr_a[j][i]);
        }
    }
}
void elements(int size, int arr_2[][size], int multElements[]){

    for(int i = 0; i < size; i++){
        multElements[i] = arr_2[i][0];
        for(int j = 1; j < size; j++)
            multElements[i] = multElements[i] * arr_2[i][j];
        printf("%d ", multElements[i]);
    }
}
void matrixB(int size, int arr_a[][size], int multElements[], int arr_b[][size]){

    for(int i = 0; i < size; i++){
        printf("\n");
        for(int j = 0; j < size; j++){
            arr_b[i][j] = multElements[i] + arr_a[i][j];
            printf("%d ", arr_b[i][j]);
        }
    }
}