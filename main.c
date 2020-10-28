#include "stdio.h"

///Loader ver 0.1 in debug mode
///Next time it will be better :)
///It's my first time :c
///Wait 4 next updates!

int lab1();
int lab2();
int lab5();

int main(){

    int action;

    printf("To exit entered 100\n\n");

    while (action!=100){
        printf("Select lab to open: ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                lab1();
                printf("\n\nEnd of lab \n\n");
                break;
            case 2:
                lab2();
                printf("\n\nEnd of lab \n\n");
                break;
            case 5:
                lab5();
                printf("\n\nEnd of lab \n\n");
                break;
            default:
                printf("\n\nLab in progress\n\n");
        }
    }

    return 0;
};
