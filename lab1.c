#include <stdio.h>

int lab1(){
    char name[255];
    char text[255];
    char *pt = text;
    char lett[26];
    int arrRepit[26];

    printf("\n");
    printf("Enter file name with .txt or file path:");
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    fgets(pt, 255, file);
    printf("\nText: %s\n", pt);
    fclose(file);

    int count = 0;
    while (pt[count]) count++;
    printf("\nNumber of characters in a line: %d\n", count);

    for(int i = 0; i <sizeof(lett)/sizeof(lett[0]) ; i++){
        lett[i] = (char)('a' + i);
    }

    for(int i=0; i<sizeof(arrRepit)/sizeof(arrRepit[0]);i++){
        arrRepit[i] = 0;
    }

    for(int j=0; j< sizeof(lett)/sizeof(lett[0]) ; j++){
        for(int i = 0; i < count; i++){
            if(lett[j] == text[i]){
                arrRepit[j]++;
            }
        }
    }

    int max = arrRepit[0];
    char maxChar;

    for (int i = 0; i < sizeof(arrRepit)/sizeof(arrRepit[0]); i++){
        if(arrRepit[i] > max) {
            max = arrRepit[i];
            maxChar = lett[i];
        } else {
            arrRepit[i] = 1;
        }
    }
    printf("\nNumber of repetitions: %d\n", max);
    printf("Letter: %c\n", maxChar);

    return 0;
}