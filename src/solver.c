#include <stdio.h>
#include "solver.h"
#include "words.h"
#include "boolean.h"
#include <stdint.h>
#include <time.h>
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
                if (cur_word[0] == mat[i * cols + j].ch){
                    // cek kanan
                    if (j + cur_len <= cols){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[i * cols + j+k].ch != cur_word[k]){
                                isEq = false;
                            }
                        else k += 1;
                        }
                        if(isEq){
                        
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[i * cols + j+k].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // cek kanan-bawah
                    if (j + cur_len <= cols && i + cur_len <= rows && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i+k) * cols + j+k].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i+k) * cols + j+k].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // cek bawah
                    if (i + cur_len <= rows && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i+k) * cols + j].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i+k) * cols + j].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // cek bawah-kiri
                    if (i + cur_len <= rows && j - cur_len >= -1 && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i+k) * cols + j-k].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i+k) * cols + j-k].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // cek kiri
                    if (j - cur_len >= -1 && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[i * cols + j-k].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[i * cols + j-k].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // cek kiri-atas
                    if (j - cur_len >= -1 && i-cur_len >= -1 && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i-k) * cols + j-k].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i-k) * cols + j-k].ccode = codeColor;
                            }
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // atas
                    if (i-cur_len >= -1 && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i-k) * cols + j].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i-k) * cols + j].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }

                    // atas-kanan
                    if (i-cur_len >= -1 && j+cur_len <= rows && !(isFound)){
                        k = 0;
                        isEq = true;
                        while (k < cur_len && isEq){
                            n_checked++;
                            if (mat[(i-k) * cols + j+k].ch != cur_word[k]){
                                isEq = false;
                            }
                            else k += 1;
                        }
                        if(isEq){
                            // Set Warna
                            codeColor = (codeColor+1)%12;
                            isFound = true;
                            for(k = 0; k < cur_len; k++){
                                mat[(i-k) * cols + j + k].ccode = codeColor;
                            }
                            // Hapus
                            delNode(&p,&pbef,listWords);
                        }
                    }
                
                }
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