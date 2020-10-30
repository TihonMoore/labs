#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lab4(){
    char *text;
    char name[50];
    int size;
    int *pS = &size;

    printf("Enter file name with (.txt) or file path:");
    scanf("%s", name);
    FILE *file = fopen(name, "r");
    text = malloc(sizeof(char));
    fgets(text, *pS, file);
    printf("\nText: %s\n", text);
    fclose(file);

    printf("\nAll numbers: ");

    int sum = 0;
    while (*text) {
        if (isdigit(*text) || ( (*text=='-'||*text=='+') && isdigit(*(text+1)) ) ) {
            int numb = strtol(text, &text, 10);
            printf("%d ", numb);
            sum = sum + numb;
        } else {
            text++;
        }
    }
    printf("\n\nSum of all numbers in the text: %d\n", sum);

    return 0;
}
