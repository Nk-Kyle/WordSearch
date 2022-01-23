/* File: fileread.h */
/* Header Pembacaan Konfigurasi File */
#ifndef FILEREAD_H
#define FILEREAD_H

#include "words.h"
typedef struct {
    int ccode;
    char ch;
} board;

board * allocBoardMat(int rows, int cols);
void readDim(LinkedList *listWords, int *rows, int *cols);
board * readMat (LinkedList *listWords, int *rows, int *cols);

#endif