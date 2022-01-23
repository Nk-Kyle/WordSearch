#ifndef WORDS_H
#define WORDS_H

#include <stdlib.h>
/* Node Address for Word Linked List */
typedef struct node * Address;
typedef struct node {
    char* word;
    int len;
    Address next;
} Node;

typedef Address LinkedList;

Address newNode(int len);
void delNode(Address *p, Address *pbef, LinkedList *listWords);
#define WORD(p) (p)->word
#define LEN(p) (p)->len
#define NEXT(p) (p)->next

#endif
