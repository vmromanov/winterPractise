#include <stdlib.h>
#include <stdio.h>


double determ(const int n, double** matrix) { 
	double det = 0;
	if (n == 1)
		det = matrix[0][0];
	if (n == 2) {
		det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		return det;
	}

	double** submatrix = (double**)calloc(n - 1, sizeof(double*));
	if (submatrix == NULL) {
		printf("memory allocation errorn");
		return 1;
	}

	for (int i = 0; i < n - 1; i++) {
		submatrix[i] = (double*)calloc(n - 1, sizeof(double));
		if (submatrix[i] == NULL) {
			printf("memory allocation errorn");
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int subi = 0;
		for (int j = 0; j < n; j++) {
			int subj = 0;
			if (j == i)
				continue;
			for (int x = 1; x < n; x++) {
				submatrix[subi][subj] = matrix[x][j];
				subj++;
			}
			subi++;
		}
		det = det + (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determ(n - 1, submatrix);
	}

	for (int i = 0; i < n - 1; i++) {
		free(submatrix[i]);
	}
	free(submatrix);

	return det;
}

void findMinor(double** matrix, int size, int row_, int col_, double** minor) {
	int i = 0;
	int j = 0;
	for (int row = 0; row < size; row++) {
		for (int collumn = 0; collumn < size; collumn++) {
			if (row != row_ && collumn != col_) {
				minor[i][j++] = matrix[row][collumn];
				if (j == (size - 1)) {
					j = 0;
					i++;
				}
			}
		}
	}
}

void reverseMatrix(double** matrix_, double** reverse_, int size_)
{
	double determinant = 0;
	determinant = determ(size_, matrix_);
	if (determinant != 0)
	{
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				int minor_size = size_ - 1;
				double** minor = calloc(minor_size, sizeof(double));
				if (minor == NULL) {
					printf("memory allocation errorn");
					return ;
				}
				for (int i = 0; i < minor_size; i++) {
					minor[i] = calloc(minor_size, sizeof(double));
					if (minor[i] == NULL) {
						printf("memory allocation errorn");
						return ;
					}
				}
				findMinor(matrix_, size_, i, j, minor);
				reverse_[i][j] = (((i + j) % 2 == 0 ? 1 : -1) * determ(minor_size, minor) / determinant);
				for (int g = 0; g < minor_size; g++)
				{
					free(minor[g]);
				}
				free(minor);
			}
		}
	}
	else
	{
		printf("reverse matrix doesnt exsist.");
	}
}


