#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int **add(int **a, int **b, int n);
void matrix_print( int **a, int n);
int **matrix_allocate(int n) 
{
    int **matrix = malloc(n * sizeof(*matrix));
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = calloc(n, sizeof(*matrix[i]));
    }
    return matrix;
}
int** multiply(int** a,int** b,int n)
{
    int **result=matrix_allocate(n);
    if (n == 1) {
        result[0][0] = a[0][0] * b[0][0];
    }
    else
    {
        int n2=n/2;
        int **a11 = matrix_allocate(n2);
        int **a12 = matrix_allocate(n2);
        int **a21 = matrix_allocate(n2);
        int **a22 = matrix_allocate(n2);
        int **b11 = matrix_allocate(n2);
        int **b12 = matrix_allocate(n2);
        int **b21 = matrix_allocate(n2);
        int **b22 = matrix_allocate(n2);

        for (int i = 0; i < n2; i++) 
        {
            for (int j = 0; j < n2; j++) 
            {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + n2];
                a21[i][j] = a[i + n2][j];
                a22[i][j] = a[i + n2][j + n2];
                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + n2];
                b21[i][j] = b[i + n2][j];
                b22[i][j] = b[i + n2][j + n2];
            }
        }

        int **c11 = add(multiply(a11, b11, n2),multiply(a12, b21, n2), n2);
        int **c12 = add(multiply(a11, b12, n2),multiply(a12, b22, n2), n2);
        int **c21 = add(multiply(a21, b11, n2),multiply(a22, b21, n2), n2);
        int **c22 = add(multiply(a21, b12, n2),multiply(a22, b22, n2), n2);

        for (int i = 0; i < n2; i++)
         {
            for (int j = 0; j < n2; j++) 
            {
                result[i][j] = c11[i][j];
                result[i][j + n2] = c12[i][j];
                result[i + n2][j] = c21[i][j];
                result[i + n2][j + n2] = c22[i][j];
            }
        }
        
    }
    return result;

}
int **add(int **a, int **b, int n) {
    int **c = matrix_allocate(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
void matrix_print( int **a, int n) {
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             printf("%d ",a[i][j]);
         }
         printf("\n");
     } 
}
int isPowerOfTwo (int x)
{
  return x && (!(x&(x-1)));
}
int main  () {
    printf("Enter the order of matrix:-\n");
    int n;
    scanf("%d",&n);
    if(isPowerOfTwo(n)==0)
    {
        printf("please give the order of the matrix as a power of 2 only\n");
    }
    else
    {
        
    int **matrix1,**matrix2,**ans;
    matrix1=matrix_allocate(n);
    matrix2=matrix_allocate(n);
    ans=matrix_allocate(n);
    printf("Enter the matrix 1:-\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the matrix 2:-\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    clock_t start=clock();
    printf("The multiplication of both the matrices are as follows:-\n");
    ans=multiply(matrix1,matrix2,n);
    matrix_print(ans,n);
    clock_t end=clock();
    printf("\nTotal time in ms :-%u",end-start);
    }
return 0;
}