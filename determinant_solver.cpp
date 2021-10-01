#include<iostream>
#include<math.h>
using namespace std;
int determinant( int matrix[10][10], int n) {
   int det = 0;
   int submatrix[10][10];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}
int main() {
   int n, i, j;
   int matrix[10][10];
   cout << "Enter the size of the matrix:\n";
   cin >> n;
   cout << "Enter the elements of the matrix:\n";
   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   cin >> matrix[i][j];
   cout<<"The entered matrix is:"<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
      cout << matrix[i][j] <<" ";
      cout<<endl;
   }
   cout<<"Determinant of the matrix is "<< determinant(matrix, n);
   return 0;
}
