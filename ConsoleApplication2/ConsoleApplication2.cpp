

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void borrar(int ** matriz, int f, int c, int niveldificultad)
{
	//1 hacia arriba

	if (matriz[f][c] == matriz[f - 1][c] && (f - 1) >= 0)
	{
		//caso dos hacia arriba
		if (matriz[f][c] == matriz[f - 2][c] && (f - 2) >= 0)
		{
			eliminacion_vertical(matriz, f - 2, c, niveldificultad);
			return;
		}
		//caso uno arriba uno abajo
		if (matriz[f][c] == matriz[f + 1][c] && (f + 1)<f)
		{
			eliminacion_vertical(matriz, f - 1, c, niveldificultad);
			return;
		}
	}
	if (matriz[f][c] == matriz[f + 1][c] && (f + 1)<f)
	{
		//caso dos abajo.
		if (matriz[f][c] == matriz[f + 2][c] && (f + 2)<f)
		{
			eliminacion_vertical(matriz, f, c, niveldificultad);
			return;
		}
	}
	//1 izquierda
	if (matriz[f][c] == matriz[f][c - 1] && (c - 1) >= 0)
	{
		//caso dos izda.
		if (matriz[f][c] == matriz[f][c - 2] && (c - 2) >= 0)
		{
			eliminacion_horizontal(matriz, f, c - 2, niveldificultad);
			return;
		}

		//caso uno izda uno dcha
		if (matriz[f][c] == matriz[f][c + 1] && (c + 1)<c)
		{
			eliminacion_horizontal(matriz, f, c - 1, niveldificultad);
			return;
		}
	}
	if (matriz[f][c] == matriz[f][c + 1] && (c + 1)<c)
	{
		if (matriz[f][c] == matriz[f][c + 2] && (c + 2)<c)
		{
			eliminacion_horizontal(matriz, f, c, niveldificultad);
				return;
		}
	}
}

void eliminacion_vertical(int ** matriz, int f, int c, int niveldificultad)
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
		matriz[f][c] = rand() % niveldificultad + 1;
		f++;
	}
}

void eliminacion_horizontal(int ** matriz, int f,int c, int niveldificultad)
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
		matriz[f][c] = rand() % niveldificultad + 1;
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

void eliminarColumna(int ** matriz, int f, int c, int niveldificultad)
{
	int columna;
	int i, j;
	printf("\nIntroduzca la columna que desea eliminar: ");
	scanf_s("%d",&columna);
	columna--;
	for (i = 0; i < f; i++)
	{
		matriz[i][columna] = 0;
	}

	imprimirMatriz(matriz, f, c);

	for (j = 0; j < c; j++) //mueve los numeros a la derecha cuando se elimina una columna
	{
		for (i = columna; i > 0; i--)
		{
			matriz[i][j] = matriz[i][j-1];
		}
	}

	imprimirMatriz(matriz, f, c);

	for (i = 0; i < f; i++) //genera la nueva columna al principio, una vez se ha eliminado la deseada
	{
		matriz[i][0] = (int)rand() % niveldificultad + 1;
	}

	imprimirMatriz(matriz, f, c);
}

void eliminarFila(int ** matriz, int f, int c, int niveldificultad)
{
	int fila;
	int j, i;
	printf("\nIntroduzca la fila que desea eliminar: ");
	scanf_s("%d", &fila);
	fila--;
	for (j = 0; j < f; j++)
	{
		matriz[fila][j] = 0;
	}
	imprimirMatriz(matriz, f, c);
	for (j = 0; j < c; j++) //mueve los numeros abajo
	{
		for (i = fila; i > 0; i--)
		{
			matriz[i][j] = matriz[i-1][j];
		}
	}

	imprimirMatriz(matriz, f, c);

	for (j = 0; j < c; j++) //genera la nueva fila al principio, una vez se ha eliminado la deseada
	{
		matriz[0][j] = (int)rand() % niveldificultad + 1;
	}

	imprimirMatriz(matriz, f, c);
}

void mover(int ** matriz, int f, int c, int niveldificultad)
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
					borrar(matriz,fc,cc,niveldificultad);
					borrar(matriz, fc-1, cc, niveldificultad);
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
					borrar(matriz, fc, cc, niveldificultad);
					borrar(matriz, fc+1, cc, niveldificultad);
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
					borrar(matriz, fc, cc, niveldificultad);
					borrar(matriz, fc, cc-1, niveldificultad);
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
					borrar(matriz, fc, cc, niveldificultad);
					borrar(matriz, fc, cc+1, niveldificultad);
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

void moverAut(int ** matriz, int f, int c, int fc, int cc, char direccion, int niveldificultad)
{

	int auxiliar = matriz[fc][cc];



	switch (direccion)
	{
	case 'U':
		if (fc - 1 >= 0 && fc - 1 < f)
		{
			if (cc >= 0 && cc < c)
			{
				//dentro del rango
				matriz[fc][cc] = matriz[fc - 1][cc];
				matriz[fc - 1][cc] = auxiliar;
				borrar(matriz, fc, cc, niveldificultad);
				borrar(matriz, fc - 1, cc, niveldificultad);
			}
		}
		break;
	case 'D':
		if (fc + 1 >= 0 && fc + 1 < f)
		{
			if (cc >= 0 && cc < c)
			{
				//dentro del rango
				matriz[fc][cc] = matriz[fc + 1][cc];
				matriz[fc + 1][cc] = auxiliar;
				borrar(matriz, fc, cc, niveldificultad);
				borrar(matriz, fc + 1, cc, niveldificultad);
			}
		}
		break;
	case 'L':
		if (fc >= 0 && fc < f)
		{
			if (cc - 1 >= 0 && cc - 1 < c)
			{
				//dentro del rango
				matriz[fc][cc] = matriz[fc][cc - 1];
				matriz[fc][cc - 1] = auxiliar;
				borrar(matriz, fc, cc, niveldificultad);
				borrar(matriz, fc, cc - 1, niveldificultad);
			}
		}
		break;
	case 'R':
		if (fc >= 0 && fc < f)
		{
			if (cc + 1 >= 0 && cc + 1 < c)
			{
				//dentro del rango
				matriz[fc][cc] = matriz[fc][cc + 1];
				matriz[fc][cc + 1] = auxiliar;
				borrar(matriz, fc, cc, niveldificultad);
				borrar(matriz, fc, cc + 1, niveldificultad);
			}
		}
		break;
	}

}

void automatico(int ** matriz, int f, int c, int niveldificultad)
{
	int fi, ci;
	int val;
	bool borrado;
	char salir = 'Q';
	printf("\nModo automático\n -Para salir introduzca 'Q'\n -Para continuar introduzca cualquier otra letra\n");
	scanf_s("%c", &salir);
	while (salir != 'Q'){
		fi = 0;
		ci = 0;
		borrado = false;
		//bucle iterador horizontal
		do
		{
			val = matriz[fi][ci];
			if (val == matriz[fi][ci + 1] && (ci + 1) < c && fi >= 0 && !borrado)
			{
				if (val == matriz[fi - 1][ci + 2] && (ci + 2) < c && (fi - 1) >= 0 && !borrado)
				{
					moverAut(matriz, f, c, (fi - 1), (ci + 2), 'D', niveldificultad);
					borrado = true;
				}
				if (val == matriz[fi][ci + 3] && (ci + 3) < c && !borrado)
				{
					moverAut(matriz, f, c, fi, (ci + 3), 'L', niveldificultad);
					borrado = true;
				}
				if (val == matriz[fi + 1][ci + 2] && (ci + 2) < c && (fi + 1) < f && !borrado)
				{
					moverAut(matriz, f, c, (fi + 1), (ci + 2), 'U', niveldificultad);
					borrado = true;
				}
			}
			ci++;
			if (ci == c) {
				ci = 0;
				fi++;
			}

		} while (fi < f && ci < c && !borrado);

		//bucle iterador vertical
		if (!borrado) {
			do
			{
				val = matriz[fi][ci];
				if (val == matriz[fi + 1][ci] && (fi + 1) < f && ci >= 0)
				{
					if (val == matriz[fi + 2][ci - 1] && (ci - 1) >= 0 && (fi + 2) < f && !borrado)
					{
						moverAut(matriz, f, c, (fi + 2), (ci - 1), 'R', niveldificultad);
						borrado = true;
					}
					if (val == matriz[fi + 3][ci] && (fi + 3) < f && !borrado)
					{
						moverAut(matriz, f, c, (fi + 3), ci, 'U', niveldificultad);
						borrado = true;
					}
					if (val == matriz[fi + 2][ci + 1] && (ci + 1) < c && (fi + 2) < f && !borrado)
					{
						moverAut(matriz, f, c, (fi + 2), (ci + 1), 'L', niveldificultad);
						borrado = true;
					}
				}
				fi++;
				if (fi == f) {
					fi = 0;
					ci++;
				}

			} while (fi < f && ci < c && !borrado);
		}

		printf("\n-Para salir introduzca 'Q'\n -Para continuar introduzca cualquier otra letra\n");
		scanf_s("%c", &salir);
	} 
	return;
}

int main()
{
	int arraySize;
	int niveldificultad = 0;
	int ayuda1 = 0, ayuda2 = 0;
	int nivelayuda = 0;
	int opcion = 0;
	char manualauto = 'z';
	int i, j, k;
	int **a, **b, **c;
	int f1, c1, f2, c2, f3, c3;
	int pruductoEscalar = 0;
	bool salir = false;

	printf("Bienvenido a Jewels no se cuantos.\n\n");	//primero se pregunta si se quiere el tablero estandar de 10 por 50 o uno personalizado
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
	else {		//en el caso de tablero personalizado, pedimos sus dimensiones
		printf("\nIntroduzca las filas del tablero: ");
		scanf_s("%d", &f1);
		printf("Introduzca las columnas del tablero: ");
		scanf_s("%d", &c1);
	}

	do
	{			// ahora preguntamos si quiere modo manual o modo automático
		printf("Modo manual o automatico? (introduzca m o a): ");
		scanf_s("%c", &manualauto);
	} while ((manualauto != 'm' && manualauto != 'M') && (manualauto != 'a' && manualauto != 'A'));

	//asignas la memoria al tablero
	a = (int **)malloc(f1 * sizeof(int*)); //asignas memoria a la matriz = tamaño de un puntero int X numero de filas

	for (i = 0; i<f1; i++)
	{
		a[i] = (int *)malloc(c1 * sizeof(int)); //en cada fila reservas memoria = tamaño de un int X numero de columnas
	}

	if (manualauto == 'm' || manualauto == 'M')	//ejecución manual
	{

	do
	{		//preguntamos sobre la dificultad
		printf("Modo facil, medio o dificil? (introduzca 1, 2 o 3): ");
		scanf_s("%d", &nivelayuda);
	} while (nivelayuda != 1 && nivelayuda != 2 && nivelayuda != 3);

	switch (nivelayuda)
	{
	case 1:
		niveldificultad = 4;
		break;
	case 2:
		niveldificultad = 6;
		break;
	case 3:
		niveldificultad = 8;
		break;
	}

	for (i = 0; i < f1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			do {
				a[i][j] = (int) rand() % niveldificultad + 1;

			} while (a[i][j] < 1 || a[i][j] > niveldificultad);
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
				mover(a,f1,c1,niveldificultad);
			}
			else {
				if (opcion == 2)
				{
				//pedir ayuda
					printf("Ayudas disponibles:\n\tNivel facil: bomba columna -> introduzca 9 1\n");
					printf("\tNivel medio: bomba columna -> introduzca 9 1\n\t\tbomba linea -> introduce 9 2\n");
					printf("\tNivel dificil: bomba columna -> introduzca 9 1\n\t\tbomba -> introduce 9 2\n\t\trotar -> introduce 9 3 (no disponible)");
					do
					{
						scanf_s("%d", &ayuda1);
						scanf_s("%d", &ayuda2);
					} while (ayuda1 != 9 || (ayuda2 != 1 && ayuda2 != 2 && ayuda2 != 3));

					if (nivelayuda == 1)// nivel dificultad 1, ayuda numero 1
					{
						if (ayuda2 == 1)
						{
							eliminarColumna(a, f1, c1, niveldificultad);
						}
						else {
							printf("\nAyuda no disponible.");
						}
					}
					else {
						if (nivelayuda == 2) // nivel de dificultad 2, disponibles ayudas 1 y 2
						{
							if (ayuda2 == 1)
							{
								eliminarColumna(a, f1, c1, niveldificultad);
							}
							else {
								if (ayuda2 == 2)
								{
									eliminarFila(a, f1, c1, niveldificultad);
								}
								else {
									printf("\nAyuda no disponible.");
								}
							}
						}
						else {// nivel de dificultad 3, las 3 ayudas (no implementamos la ayuda 3)
							if (ayuda2 == 1)
							{
								eliminarColumna(a, f1, c1, niveldificultad);
							}
							else {
								if (ayuda2 == 2)
								{
									eliminarFila(a, f1, c1, niveldificultad);
								}
								else {
									printf("\nAyuda no disponible.");
								}
							}
						}
					}
				}
			}
		}
	} while (!salir);
		
	}
	else
	{
		//ejecución automática
		printf("\nAutomatica no implementada.\n");
	}
	free(a);

	system("pause");


	return 0;
}