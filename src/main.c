#include "filereads.h"
#include "words.h"
#include "color.h"
#include "solver.h"
#include <stdio.h>
#include <time.h>
int main() {
    board * mat= 0;
    int rows;
    int cols;
    int boxes;
    LinkedList listWords;
    mat = readMat(&listWords, &rows, &cols);
    solve(mat, &listWords, rows, cols);
    if(listWords == NULL) {
        printf("\nAll found");
    }
    else{
        Address p;
        p = listWords;
        printf("\nMissing Words:\n");
        while (p != NULL){
            printf("%s\n",WORD(p));
            p = NEXT(p);
        }
    }
    return 0;
}
