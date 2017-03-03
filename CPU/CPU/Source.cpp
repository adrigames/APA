#include <stdio.h>
#include <stdlib.h>


int main()
{
	int arraySize;
	int opcion = 0;
	int i, j, k;
	int **a, **b, **c;
	int f1, c1, f2, c2, f3, c3;
	int pruductoEscalar = 0;

	printf("Bienvenido a Jewels no se cuantos.\n\n");
	do
	{
		printf("Quiere tablero estandar o prefiere personalizado? (introduzca 1 o 2)\n\n");
		scanf_s("%d", &opcion);
	} while (opcion != 1 && opcion != 2);

	if (opcion == 1)
	{
		f1 = 10;
		f2 = 50;
	}
	else {
		printf("\nIntroduzca las filas del tablero:\n");
		scanf_s("%d", &f1);
		printf("Introduzca las columnas del tablero:\n");
		scanf_s("%d", &c1);
	}

	//asignas la memoria al tablero
	a = (int **)malloc(f1 * sizeof(int*)); //asignas memoria a la matriz = tamaño de un puntero int X numero de filas

	for (i = 0; i<c1; i++)
	{
		a[i] = (int *)malloc(c1 * sizeof(int)); //en cada fila reservas memoria = tamaño de un int X numero de columnas
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


	system("pause");

	free(a);

	return 0;
}