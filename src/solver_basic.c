#include <stdio.h>
#include "solver.h"
#include "words.h"
#include "boolean.h"
#include <stdint.h>
#include <time.h>

boolean checkWord(board * mat, Address *p, int rows, int cols, int currow, int curcol, int horinc, int vertinc, int * n_checked){
    int i = currow;
    int j = curcol;
    int k = 0;
    while (i < rows && j < cols && i >= 0 && j >= 0 &&  k < LEN(*p)){
        *n_checked = *n_checked+1;
        if (mat[i*cols + j].ch != WORD(*p)[k]){
            return false;
        }
        else {
            i = i + vertinc;
            j = j + horinc;
            k = k +1;
        }
    }
    if (k != LEN(*p)){
        return false;
    }
    else {
        return true;
    }
}

void setColour( board * mat, int currow, int curcol, int horinc, int vertinc, int colorcode, int k, int cols){
    int r = currow;
    int c = curcol;
    for(int i = 0; i < k; i++){
        mat[r * cols + c].ccode = colorcode;
        r = r + vertinc;
        c = c + horinc;
    }
}

void solve(board * mat, LinkedList * listWords, int rows, int cols){
    Address p, pbef;
    char * cur_word;
    int cur_len;
    int tot_perb;
    int n_checked;
    int i,j,k;
    int codeColor;
    boolean isFound, isEq;
    tot_perb = 0;
    n_checked = 0;
    i =0;
    j = 0;
    codeColor = -1; 
    struct timespec begin;
    struct timespec end;
    struct timespec tprint;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    
    while (i < rows && *listWords != NULL){
        j = 0;
        while (j < cols && *listWords != NULL){
            p = *listWords;
            pbef = NULL;
            while (p != NULL){
                isFound = false;
                cur_word = WORD(p);
                cur_len = LEN(p);
                
                // Kanan
                isFound = checkWord(mat, &p, rows, cols,i, j, 1,0, &n_checked);
                if (isFound){
                    codeColor = (codeColor+1)%12;
                    setColour(mat, i, j, 1,0,codeColor, LEN(p), cols);
                    delNode(&p,&pbef,listWords);
                }

                // Kanan Bawah
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j, 1,1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, 1,1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                //bawah
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,0,1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, 0,1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                //kiri bawah
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,-1,1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, -1,1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                //kiri 
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,-1,0, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, -1,0,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                // kiri atas
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,-1,-1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, -1,-1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                // atas
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,0,-1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, 0,-1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                // kanan atas
                if (!isFound){
                    isFound = checkWord(mat, &p, rows, cols,i, j,1,-1, &n_checked);
                    if (isFound){
                        codeColor = (codeColor+1)%12;
                        setColour(mat, i, j, 1,-1,codeColor, LEN(p), cols);
                        delNode(&p,&pbef,listWords);
                    }
                }

                // Kasus tidak ditemukan
                if (!isFound) {
                    pbef = p;
                    p = NEXT(p);
                }
                
            }
            j += 1;
        }
        i += 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    for (i = 0 ; i < rows; i++){
        for(j = 0 ; j < cols ; j++){
            print_color(mat[i*cols + j].ccode, mat[i*cols + j].ch);
            printf(" ");
        }
        printf("\n");
    }
    clock_gettime(CLOCK_MONOTONIC, &tprint);

    uint64_t end_ns = (end.tv_sec * 1000000000) + end.tv_nsec;
    uint64_t begin_ns = (begin.tv_sec * 1000000000) + begin.tv_nsec;
    uint64_t tprint_ns = (tprint.tv_sec * 1000000000) + tprint.tv_nsec;
    int64_t elapsed = end_ns - begin_ns;
    int64_t elapsprint = tprint_ns - begin_ns;
    printf("\nCharacter Comparisons: %d\n", n_checked);
    printf("Algorithm Time: %ld nanoseconds (%lf seconds)\n",elapsed, (double)elapsed/1000000000);
    printf("Algorithm Time + Print: %ld nanoseconds (%lf seconds)\n",elapsprint, (double)elapsprint/1000000000);
}