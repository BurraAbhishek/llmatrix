/**
 * Using single linked lists, 
 * we make immutable matrices 
 */
#include "llmatrix.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Test case. Replace if necessary
int main()
{
    double a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    struct matrix *m = NULL;
    m = arrayToMatrix(3, 3, a);
    display(m);
    double **b;
    b = MatrixToArray(m);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%lf\n", b[i][j]);
        }
    }
}
