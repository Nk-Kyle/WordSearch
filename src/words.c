#include "words.h"
#include <stdlib.h>

Address newNode(int len){
    Address pnew;
    pnew = (Address) malloc(sizeof(Node));
    LEN(pnew) = len;
    NEXT(pnew) = NULL;
    WORD(pnew) = (char *) malloc(sizeof(char) * (len+1));  
    return pnew;  
}

void delNode(Address *p, Address *pbef, LinkedList *listWords){
    Address pout;
    pout = *p;
    if (*pbef != NULL){
        NEXT(*pbef) = NEXT(*p);
        *p = NEXT(*p);
    }
    else{
        *listWords = NEXT(*p);
        *p = NULL;
    }
    free(pout);
}