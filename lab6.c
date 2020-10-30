#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void identif(char* arr, char* ident);
void reverse(int count_ident, char* ident);
void alphabet(int count_ident, char* ident);
int lab6() {
    char file_name[50];
    int size;
    int *pS = &size;
    char *arr;

    printf("Enter filename with (.txt) or file path:");
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "r");

    arr = malloc(sizeof(char));

    fgets(arr, *pS, file);
    printf("\nText: %s\n", arr);
    fclose(file);

    char *ident;
    ident = malloc(sizeof(char));

    printf("Identifiers:\n");

    identif(arr, ident);

    int count_ident = 0;
    while (ident[count_ident]) count_ident++;

    printf("\nReverse:\n");

    reverse(count_ident, ident);
    alphabet(count_ident, ident);

    printf("\nAlphabetically: \n");
    for(int i = 0; i < count_ident - 1; i++)
        printf("%c ", ident[i]);


    return 0;
}
void identif(char* arr, char* ident){


    int count_text = 0;
    while (arr[count_text]) count_text++;

    int count = 0;
    for(int i = 0; i < count_text; i++){
        if (islower(arr[i])) {
            ident[count] = arr[i];
            arr[i]++;
            printf("%c ", ident[count]);
            count++;
        }

    }

}
void reverse(int count_ident, char* ident){
    for(int i = count_ident - 1; i >= 0; i--){
        printf("%c ", ident[i]);
    }

}
void alphabet(int count_ident, char* ident){
    for(int i = 0; i < count_ident - 1; i++) {
        for(int j = 0; j < count_ident - i - 1; j++) {
            if(ident[j] > ident[j + 1]) {
                char tmp = ident[j];
                ident[j] = ident[j + 1];
                ident[j + 1] = tmp;
            }
        }
    }

}
