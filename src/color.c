#include <stdio.h>
#include "color.h"
void print_color(int ccode, char str){
    switch(ccode){
        case -1:
            printf("%c", str);
            break;
        case 0:
            printf("\033[31m%c\033[0m", str);
            break;
        case 1:
            printf("\033[32m%c\033[0m", str);
            break;
        case 2:
            printf("\033[33m%c\033[0m", str);
            break;
        case 3:
            printf("\033[34m%c\033[0m", str);
            break;
        case 4:
            printf("\033[35m%c\033[0m", str);
            break;
        case 5:
            printf("\033[36m%c\033[0m", str);
            break;
        case 6:
            printf("\033[91m%c\033[0m", str);
            break;
        case 7:
            printf("\033[92m%c\033[0m", str);
            break;
        case 8:
            printf("\033[93m%c\033[0m", str);
            break;
        case 9:
            printf("\033[94m%c\033[0m", str);
            break;
        case 10:
            printf("\033[95m%c\033[0m", str); 
            break;
        case 11:
            printf("\033[96m%c\033[0m", str);
            break; 
    }
}
