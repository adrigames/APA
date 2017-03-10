

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void borrar(int ** matriz, int f, int c)
{
	//1 hacia arriba

	if (matriz[f][c] == matriz[f - 1][c] && (f - 1) >= 0)
	{
		//caso dos hacia arriba
		if (matriz[f][c] == matriz[f - 2][c] && (f - 2) >= 0)
		{
			eliminacion_vertical(matriz, f - 2, c);
			return;
		}
		//caso uno arriba uno abajo
		if (matriz[f][c] == matriz[f + 1][c] && (f + 1)<f)
		{
			eliminacion_vertical(matriz, f - 1, c);
			return;
		}
	}
	if (matriz[f][c] == matriz[f + 1][c] && (f + 1)<f)
	{
		//caso dos abajo.
		if (matriz[f][c] == matriz[f + 2][c] && (f + 2)<f)
		{
			eliminacion_vertical(matriz, f, c);
			return;
		}
	}
	//1 izquierda
	if (matriz[f][c] == matriz[f][c - 1] && (c - 1) >= 0)
	{
		//caso dos izda.
		if (matriz[f][c] == matriz[f][c - 2] && (c - 2) >= 0)
		{
			eliminacion_horizontal(matriz, f, c - 2);
			return;
		}

		//caso uno izda uno dcha
		if (matriz[f][c] == matriz[f][c + 1] && (c + 1)<c)
		{
			eliminacion_horizontal(matriz, f, c - 1);
			return;
		}
	}
	if (matriz[f][c] == matriz[f][c + 1] && (c + 1)<c)
	{
		if (matriz[f][c] == matriz[f][c + 2] && (c + 2)<c)
		{
			eliminacion_horizontal(matriz, f, c)
				return;
		}
	}
}

void eliminacion_vertical(int ** matriz, int f, int c)
{
	int aux = -1;
	int val = matriz[f][c];
	int auxf = f;
	while (c>0)
	{
		while (val == matriz[f][c])
		{
			aux = matriz[f][c];
			matriz[f][c] = matriz[f][c - 1];
			matriz[f][c - 1] = aux;
			f++;
		}
		f = auxf;
		c--;
	}
	while (val == matriz[f][c])
	{
		matriz[f][c] = rand() % 8 + 1;
		f++;
	}
}
void eliminacion_horizontal(int ** matriz, int f,int c)
{
	int aux = -1;
	int val = matriz[f][c];
	int auxc = c;
	while (f>0)
	{
		while (val == matriz[f][c])
		{
			aux = matriz[f][c];
			matriz[f][c] = matriz[f - 1][c];
			matriz[f - 1][c] = aux;
			c++;
		}
		c = auxc;
		f--;
	}
	while (val == matriz[f][c])
	{
		matriz[f][c] = rand() % 8 + 1;
		c++;
	}
}

void pedirComando(int *comando)
{
	int opcion;
	do
	{
		printf("\nSi desea hacer un movimiento estandar introduzca 1.\nSi desea ayuda introduzca 2.\nSi quiere salir de la partida introduzca 3.\n");
		scanf_s("%d", &opcion);
	} while (opcion!=1 && opcion!=2 && opcion!=3);
	*comando = opcion;
}

void imprimirMatriz(int ** matriz, int f, int c)
{
	int i, j;
	printf("\nTablero:\n");
	for (i = 0; i<f; i++)
	{
		for (j = 0; j<c; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void eliminarColumna(int ** matriz, int f, int c)
{
	int columna;
	int i;
	printf("\nIntroduzca la columna que desea eliminar: ");
	scanf_s("%d",&columna);
	columna--;
	for (i = 0; i < f; i++)
	{
		matriz[i][columna] = 0;
	}
	imprimirMatriz(matriz, f, c);
}

void eliminarFila(int ** matriz, int f, int c)
{
	int fila;
	int j;
	printf("\nIntroduzca la fila que desea eliminar: ");
	scanf_s("%d", &fila);
	fila--;
	for (j = 0; j < f; j++)
	{
		matriz[fila][j] = 0;
	}
	imprimirMatriz(matriz, f, c);
}

void mover(int ** matriz, int f, int c)
{
	char direccion = 'Z';
	bool salir = false;
	int fc, cc;
	int auxiliar;
	do
	{
		printf("\nIntroduzca las coordenadas de la ficha a mover.\n");
		scanf_s("%d",&fc);
		scanf_s("%d",&cc);
		fc--;
		cc--;
		if (fc >= 0 && fc < f)
		{
			if (cc >= 0 && cc < c)
			{
				//dentro de la matriz
				auxiliar = matriz[fc][cc];
				salir = true;
			}
		}
	} while (!salir);

	salir = false;

	do
	{
		printf("\nIntroduzca la direccion de la ficha a mover.\nArriba (U) - Abajo (D) - Izquierda (L) - Derecha (R)\n");
		scanf_s("%c", &direccion);

		switch (direccion)
		{
		case 'U':
			if (fc-1 >= 0 && fc-1 < f)
			{
				if (cc >= 0 && cc < c)
				{
					//dentro del rango
					matriz[fc][cc] = matriz[fc - 1][cc];
					matriz[fc - 1][cc] = auxiliar;
					salir = true;
				}
			}
			break;
		case 'D':
			if (fc+1 >= 0 && fc+1 < f)
			{
				if (cc >= 0 && cc < c)
				{
					//dentro del rango
					matriz[fc][cc] = matriz[fc + 1][cc];
					matriz[fc + 1][cc] = auxiliar;
					salir = true;
				}
			}
			break;
		case 'L':
			if (fc >= 0 && fc < f)
			{
				if (cc-1 >= 0 && cc-1 < c)
				{
					//dentro del rango
					matriz[fc][cc] = matriz[fc][cc-1];
					matriz[fc][cc-1] = auxiliar;
					salir = true;
				}
			}
			break;
		case 'R':
			if (fc >= 0 && fc < f)
			{
				if (cc+1 >= 0 && cc+1 < c)
				{
					//dentro del rango
					matriz[fc][cc] = matriz[fc][cc+1];
					matriz[fc][cc+1] = auxiliar;
					salir = true;
				}
			}
			break;
		default:
			salir = false;
		}

		if (!salir) {
			printf("\nMovimiento no permitido.\n");

	}
	} while (!salir);
	printf("\nmovimiento permitido\n");
}

int main()
{
	int arraySize;
	int opcion = 0;
	int i, j, k;
	int **a, **b, **c;
	int f1, c1, f2, c2, f3, c3;
	int pruductoEscalar = 0;
	bool salir = false;

	printf("Bienvenido a Jewels no se cuantos.\n\n");
	do
	{
		printf("Quiere tablero estandar o prefiere personalizado? (introduzca 1 o 2)\n\n");
		scanf_s("%d", &opcion);
	} while (opcion != 1 && opcion != 2);

	if (opcion == 1)
	{
		f1 = 10;
		c1 = 50;
	}
	else {
		printf("\nIntroduzca las filas del tablero:\n");
		scanf_s("%d", &f1);
		printf("Introduzca las columnas del tablero:\n");
		scanf_s("%d", &c1);
	}

	//asignas la memoria al tablero
	a = (int **)malloc(f1 * sizeof(int*)); //asignas memoria a la matriz = tamaño de un puntero int X numero de filas

	for (i = 0; i<f1; i++)
	{
		a[i] = (int *)malloc(c1 * sizeof(int)); //en cada fila reservas memoria = tamaño de un int X numero de columnas
	}

	//printf("Rellene matriz 1:\n");

	for (i = 0; i < f1; i++)
	{
		//printf("\nFila %d",i);
		for (j = 0; j < c1; j++)
		{
			do {
				a[i][j] = (int) rand() % 8 + 1;

			} while (a[i][j] < 1 || a[i][j] > 8);
		}
	}


	//modo automatico o normal?

	

	do
	{
		imprimirMatriz(a,f1,c1);
		pedirComando(&opcion);
		if (opcion == 3)
		{
			salir = true;
		}
		else {
			if (opcion == 1)
			{
				//mover
				mover(a,f1,c1);
			}
			else {
				if (opcion == 2)
				{
					eliminarColumna(a, f1, c1);
					eliminarFila(a,f1,c1);
				}
				//pedir ayuda
			}
		}
	} while (!salir);

	/*
	printf("\nMatriz 1:\n");
	for (i = 0; i<f1; i++)
	{
		for (j = 0; j<c1; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}*/

	free(a);

	system("pause");


	return 0;
}