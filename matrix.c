#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  N  5
void deleteMatrix(double*** a_tab, int n);
double ** createMatrix(int n)
{
    double ** matrix = malloc(n*sizeof(double));
    if (matrix==NULL) return  NULL;

    for(int i = 0;i<n;i++)
    {
        matrix[i] = malloc(n*sizeof(double));
        if(matrix[i] == NULL)
        {
            deleteMatrix(&matrix,N);
            return NULL;
        }
    }
    return matrix;
}

void fillMatrix(double** tab, int n)
{
    int liczba = 1;
    for(double** x = tab;x < tab+n;x++)
    {
        for(double* y = *x;y < *x+n;y++)
        {
            *y = liczba++;
        }
    }
}

void printMatrix(double** tab, int n)
{
    for(double** x = tab;x < tab+n;x++)
    {
        for(double* y = *x;y < *x+n;y++)
        {
            printf("%lf | ",*y);
        }
        putchar('\n');
    }
}

void deleteMatrix(double*** a_tab, int n)
{
    for(int i = 0;i<n;i++)
    {
        free((*a_tab)[i]);
    }
    free(*a_tab);
    *a_tab = NULL;
}

int main()
{
    double ** matr;
    matr = createMatrix(N);
    fillMatrix(matr,N);
    printMatrix(matr,N);
    deleteMatrix(&matr,N);

}