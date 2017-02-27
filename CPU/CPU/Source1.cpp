#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int arraySize;
	int i, j, k;
	int **a, **b, **c;
	int f1, c1, f2, c2, f3, c3;
	int pruductoEscalar = 0;

	printf("Multiplicador de matrices\n\n");

	printf("(La matriz 2 debe tener las mismas filas que columnas tenga la matriz 1)\nIntroduzca las filas de las matriz 1:\n");
	scanf("%d", &f1);
	printf("Introduzca las columnas de la matriz 1:\n");
	scanf("%d", &c1);

	//asignas memoria al vector igual al tamaño de un puntero int * la dimension del vector
	a = (int **)malloc(f1 * sizeof(int*)); //asignas memoria a la matriz igual al tamaño de un puntero int * el numero de filas

	for (i = 0; i<c1; i++)
	{
		a[i] = (int *)malloc(c1 * sizeof(int)); //en cada fila reservas memoria igual al tamaño de un int * el numero de columnas
	}

	printf("Rellene matriz 1:\n");

	for (i = 0; i<f1; i++)
	{
		printf("Fila %d\n", i + 1);
		for (j = 0; j<c1; j++)
		{
			a[i][j] = 0;
		}
	}



	printf("\nMatriz 1:\n");
	for (i = 0; i<f1; i++)
	{
		for (j = 0; j<c1; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


	scanf("%d", &c[0]);

	free(a);

	return 0;
}