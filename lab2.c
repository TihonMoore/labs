#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printMass(int lines, int columns, int array[][columns]);
void setMass(int lines, int columns, int arr[][columns]);
void bubbleSort(int num_lines, int columns, int arr[][columns]);

int lab2() {

    int l, c;

    printf("Enter number of array lines:  ");
    scanf("%d", &l);
    printf("Enter number of array columns:  ");
    scanf("%d", &c);

    int arr[l][c];

    setMass(l, c, arr);
    printf("\nSource matrix:");
    printMass(l, c, arr);

    int num_line;

    printf("\n\nEnter number of the line:  ");
    scanf("%d", &num_line);

    bubbleSort(num_line-1, c, arr);
    printf("\nFinal matrix:");
    printMass(l, c, arr);

    return 0;
}

void setMass(int lines, int columns, int arr[][columns]){
    srand(time(0));
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = rand() % (65 + 1 - 0) + 0;
        }
    }
}

void bubbleSort(int num_lines, int columns, int arr[][columns]){
    for(int i = 0; i < columns - 1; i++){
        for(int j = (columns - 1); j > i; j--){
            if (arr[num_lines][j-1] > arr[num_lines][j]){
                int temp = arr[num_lines][j-1];
                arr[num_lines][j-1] = arr[num_lines][j];
                arr[num_lines][j] = temp;
            }
        }
    }
}

void printMass(int lines, int columns, int array[][columns]){
    for (int i = 0; i < lines; i++) {
        printf("\n");
        for (int j = 0; j < columns; j++) {
            printf("%d ", array[i][j]);
        }
    }
}