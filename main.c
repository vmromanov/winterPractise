#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "kramer.h"
#define returns 1


int main()
{
	int Size;
	printf("enter the size of the square matrix\n");
	scanf_s("%d", &Size);
	double** matrix = (double**)calloc(Size, sizeof(double*));
	if (matrix == NULL) {
		printf("memory allocation error\n");
		return returns;
	}
	for (int i = 0; i < Size; i++) {
		matrix[i] = (double*)calloc(Size, sizeof(double));
		if (matrix[i] == NULL) {
			printf("memory allocation error\n");
			return returns;
		}
	}
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			printf("enter %d element of %d row ",j,i);
			scanf_s("%lf", &matrix[i][j]); 
		}
	double** reverse = (double**)calloc(Size, sizeof(double*));
	if (reverse == NULL) {
		printf("memory allocation error\n");
		return returns;
	}
	for (int i = 0; i < Size; i++) {
		reverse[i] = (double*)calloc(Size, sizeof(double)); 
		if (reverse[i] == NULL) { 
			printf("memory allocation error\n");
			return returns;
		}
	}
	printf("inverse matrix:\n");
	reverseMatrix(matrix, reverse, Size);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			printf("%0.3f ", reverse[i][j]); 
		}
		printf("\n");
	}
	printf("\n\n");
	free(matrix); 
	free(reverse);





	int Amount = 0;
	printf("enter the amount of variables\n"); 
	scanf_s("%d", &Amount); 
	double** coefficientMatrix = (double**)calloc(Amount, sizeof(double*)); 
	if (coefficientMatrix == NULL) { 
		printf("memory allocation error\n");
		return returns;
	}
	for (int i = 0; i < Amount; i++) { 
		coefficientMatrix[i] = (double*)calloc(Amount, sizeof(double)); 
		if (coefficientMatrix[i] == NULL) {
			printf("memory allocation error\n");
			return returns;
		}
	}
	for (int i = 0; i < Amount; i++)
		for (int j = 0; j < Amount; j++)
		{
			printf("enter %d coefficient of %d row ", j, i);
			scanf_s("%lf", &coefficientMatrix[i][j]); 
		}
	double* freeMembersMatrix = (double*)calloc(Amount, sizeof(double));
	if (freeMembersMatrix == NULL) {
		printf("memory allocation error\n");
		return returns;
	}
		
		for (int i = 0; i < Amount; i++)
		{
			printf("enter %d free member", i);
			scanf_s("%lf", &freeMembersMatrix[i]);
		}

		kramerMethod(coefficientMatrix, freeMembersMatrix, Amount);

		free(coefficientMatrix);
		free(freeMembersMatrix);

	return 0;
}