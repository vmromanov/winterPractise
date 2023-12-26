#include <stdlib.h>
#include <stdio.h>


double determenantsearch(const int size, double** matrix) {
	double det = 0;
	if (size == 1)
		det = matrix[0][0];
	if (size == 2) {
		det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		return det;
	}

	double** submatrix = (double**)calloc(size - 1, sizeof(double*));
	if (submatrix == NULL) {
		printf("memory allocation errorn");
		return 1;
	}

	for (int i = 0; i < size - 1; i++) {
		submatrix[i] = (double*)calloc(size - 1, sizeof(double));
		if (submatrix[i] == NULL) {
			printf("memory allocation errorn");
			return 1;
		}
	}

	for (int i = 0; i < size; i++) { 
		int subi = 0;
		for (int j = 0; j < size; j++) { 
			int subj = 0;
			if (j == i)
				continue;
			for (int x = 1; x < size; x++) { 
				submatrix[subi][subj] = matrix[x][j];
				subj++;
			}
			subi++;
		}
		det = det + (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determenantsearch(size - 1, submatrix);
	}
	
	for (int i = 0; i < size - 1; i++) { 
		free(submatrix[i]); 
	}
	free(submatrix); 

	return det;
}

void kramerMethod(double** coefficientMatrix, double* freeMembersMatrix, int Size)
{
	double determCoeffMat = 0;
	double* answers = (double*)calloc(Size, sizeof(double));
	if (answers == NULL)
	{
		printf("memory allocation errorn\n");
		return ;
	}
	determCoeffMat = determenantsearch(Size, coefficientMatrix);
	if (determCoeffMat == 0)
	{
		printf("The system has no solutions\n ");
		return;
	}
	double** submatrix = (double**)calloc(Size, sizeof(double));
	if (submatrix == NULL)
	{
		printf("memory allocation errorn\n");
		return;
	}
	for (int i = 0; i < Size; i++)
	{
		 submatrix[i] = (double*)calloc(Size, sizeof(double));
		if (submatrix[i] == NULL)
		{
			printf("memory allocation errorn\n");
			return;
		}
	}
	for (int i = 0; i < Size; i++)
	{
		for (int x = 0; x < Size; x++) {
			for (int j = 0; j < Size; j++) {
				submatrix[x][j] = coefficientMatrix[x][j];
			}
		}
		for (int j = 0; j < Size; j++)
			submatrix[j][i] = freeMembersMatrix[j];
		answers[i] = determenantsearch(Size, submatrix) / determCoeffMat;
	}
	for (int i = 0; i < Size; i++)
	{
		printf("x[%d] = %lf\n", i, answers[i]+1);
	}
	
	for (int i = 0; i < Size; i++)
		free(submatrix[i]);
	free(submatrix);
	free(answers);
}

