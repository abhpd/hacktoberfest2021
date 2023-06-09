#include <stdio.h>

int main(){
	printf("\t\tMATRIX MULTIPLICATION\nEnter the Order of M1");
	int m1, n1, m2, n2, i = 0, j = 0, k = 0;
	printf("\nm1:");
	scanf("%d", &m1);
	printf("\nn1:");
	scanf("%d", &n1);
	printf("\nEnter the Order of M2");
	printf("\nm2:");
	scanf("%d", &m2);
	printf("\nn2:");
	scanf("%d", &n2);
	int mat1[m1][n1], mat2[m2][n2], mat3[m1][n2];
	if(n1 == m2){
		//mat3 is initialized as zero
	for(i = 0; i < m1; i++){
	
		for(j = 0; j < n2; j++){
			mat3[i][j] = 0;
	
		}
	
	}
	
		//mat1 values initialized
	for(i = 0; i < m1; i++){
	
		for(j = 0; j < n1; j++){
			printf("\na%d%d: ", i+1,j+1);
			scanf("%d", &mat1[i][j]);
	
		}
	
	}
		//mat2 values initialized	
	for(i = 0; i < m2; i++){
	
		for(j = 0; j < n2; j++){
			printf("\nb%d%d: ", i+1,j+1);
			scanf("%d", &mat2[i][j]);
	
		}
	
	}
		//mat3 is calculated
	for(i = 0; i < m1; i++){
		
		for(j = 0; j < n2; j++){
			
			for(k = 0; k < n1; k++){
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
		//print mat3
	for(i = 0; i < m1; i++){
	
		for(j = 0; j < n2; j++){
		printf("\nc%d%d: %d", i+1, j+1, mat3[i][j]);
		}
	
	}
	}
	else
	{
		printf("MATRIX MULTIPLICATION IS NOT POSSIBLE BETWEEN THE MATRICES.");
	}
	
	return 0;
}
