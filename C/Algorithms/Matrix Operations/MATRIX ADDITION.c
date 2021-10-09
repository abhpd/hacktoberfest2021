#include <stdio.h>

int main(){
	printf("\t\tMATRIX ADDITION\n");
	int m, n, i = 0, j = 0;
	printf("Enter the Order of Matrix\nm:");
	scanf("%d", &m);
	printf("n:");
	scanf("%d", &n);
	int mat1[m][n], mat2[m][n], mat3[m][n];
	
	for(i = 0; i < m; i++){
	
		for(j = 0; j < n; j++){
			printf("\na%d%d: ", i+1,j+1);
			scanf("%d", &mat1[i][j]);
	
		}
	
	}
	
	for(i = 0; i < m; i++){
	
		for(j = 0; j < n; j++){
			printf("\nb%d%d: ", i+1,j+1);
			scanf("%d", &mat2[i][j]);
	
		}
	
	}
	
	for(i = 0; i < m; i++){
	
		for(j = 0; j < n; j++){
			mat3[i][j] = mat1[i][j] + mat2[i][j];
	
		}
	
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("\nc%d%d: %d",i+1, j+1, mat3[i][j]);
	
		}
	
	}
	
	return 0;

}
