/* File: tileread.c */
/* Implementasi Pembacaan Konfigurasi Tile */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "words.h"
#include "filereads.h"

char currentChar;
static FILE * ftape; //Pita karakter untuk file
static int retval;

board * allocBoardMat(int rows, int cols){
    board *mat = (board *)malloc(rows * cols * sizeof(board));
    return mat;
}

void readDim(LinkedList *listWords, int *rows, int *cols){
   boolean bef = false; // Boolean periksa char sebelumnya enter
   boolean isBoard = true;
   boolean isWord = false;
   Address p;
   int len;
   *rows = 1;
   *cols = 0;
   
   /* Periksa dimensi Board */
   while (isBoard) {
      fscanf(ftape,"%c",&currentChar);
      if (currentChar == '\n'){         
         if (bef == true){
            isBoard = false;
         }
         else{
            bef = true;
         }
      }
      else if (currentChar != ' '){
         if (bef == true) {
            *rows += 1;
            *cols = 0;
         }
         bef = false;
         *cols += 1;
      }
   }
   p = *listWords;
   Address pin = NULL;
   Address ptrav = NULL;

   /* Set buffer linked list length */
   len = 0;
   while (fscanf(ftape,"%c",&currentChar) != EOF){
      if (currentChar == '\n') {
         isWord = false;
         pin = newNode(len);
         if (*listWords == NULL){
            *listWords = pin;
            ptrav = *listWords;
         }
         else{
            NEXT(ptrav) = pin;
            ptrav = NEXT(ptrav); 
         }
         len = 0;
      }
      else {
         isWord = true;
         len += 1;
      }
   }
   pin = newNode(len);
   NEXT(ptrav) = pin;
}

board * readMat (LinkedList *listWords, int *rows, int *cols){
   int i, j;
   boolean bef = false;
   boolean isBoard = true;
   board * mat;
   int pos;
   Address p;
   char fname[50];
   *listWords = NULL;

   /*File read*/
   do {
      printf("Masukkan nama file: ");
      scanf("%s", &fname);
      ftape = fopen(fname, "r");
      if (ftape == NULL){
         printf("File Not Found. Please Specify folder directory or check file name. Ex : test/small1.txt\n");
      }
   } while(ftape == NULL);
   
   readDim(listWords, rows, cols);
   mat = allocBoardMat(*rows, *cols);
   p = *listWords;  
   
   ftape = fopen(fname, "r");
   i = 0;
   j = 0;

   // Loop Set Matrix
   while (isBoard) {
      fscanf(ftape,"%c",&currentChar);
      if (currentChar == '\n'){
         i+= 1;
         j = 0;
         if (bef == true) {
            isBoard = false;
         }
         else{
            bef = true;
         }
      }
      else if (currentChar != ' '){
         bef = false;
         mat[i * (*cols) + j].ch = currentChar;
         mat[i * (*cols) + j].ccode = -1;
         j+= 1;

      }
      else {
         bef = false;
      }
   }
   //Set LinkedList Words
   p = *listWords;
   pos = 0;
   while (fscanf(ftape,"%c",&currentChar) != EOF){
      if (currentChar == '\n') {
         WORD(p)[pos] = '\0';
         pos = 0;
         p = NEXT(p);
      }
      else {
         WORD(p)[pos] = currentChar;
         pos += 1;
      }
   }
   WORD(p)[pos] = '\0';

   for (int i = 0 ; i < (*rows); i++){
      for (int j = 0; j < (*cols); j++){
         printf("%c ", mat[i*(*cols) +j].ch);
      }
      printf("\n");
   }

   printf("\n");
   
   p = *listWords;
   while(p != NULL){
      printf("%s\n", WORD(p));
      p = NEXT(p);
   }
   printf("\n");
   return mat;
}
