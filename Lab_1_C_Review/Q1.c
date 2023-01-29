//#include "ex1.h"

void update(int *a, int *b){
    // TODO
    int c = *a; 
    *a = *a-*b;

    if ((c-*b) % 2 == 0)
    {
        *b = (c) * (*b);
    }
    else
    {
        *b = abs((*b)-(c));
    }
}
