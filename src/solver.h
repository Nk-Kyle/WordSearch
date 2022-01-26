/* Header File solver.h */
#include "filereads.h"
#include "color.h"
#include "boolean.h"
void solve(board * mat,LinkedList * listWords, int rows, int cols);
boolean checkWord(board * mat, Address *p, int rows, int cols, int currow, int curcol, int horinc, int vertinc, int * checked);
void setColour( board * mat, int currow, int curcol, int horinc, int vertinc, int colorcode, int k, int cols);