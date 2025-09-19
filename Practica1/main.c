/****************************************************
 * File: main
 * Author: Joshua Osorio
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Sep/17/2025
 * Comments:
    Métodos de ordenamiento y búsqueda
    - Ordenamiento Lineal
    - Ordenamiento por Selección
    - Ordenamiento Burbuja
    - Búsqueda Lineal
    - Búsqueda Binaria
 * Compilación:  gcc main.c -o main.exe -fdiagnostics-color=always -g -std=c99 -Wall -Wextra -Werror -Wpedantic
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
/* Prototipos de funciones */

/* Métodos de Busqueda */
int busquedaLineal(int arr[], int n, int bus);
int busquedaBinaria(int arreglo[], int n, int llave);

/* Métosdes de ordenamiento */
void ordLineal(int arr[], int n);
void ordInsercion(int arr[], int n);
void ordBurbuja(int arr[], int n);

/* funciones de arreglos */
void imprimirArrInt(int *arr, int n);
void llenarArrInt(int *arr, int n);
void liberarArrInt(int **arr);
void CrearArrInt(int **arr, int n);

int main(void)
{
    int opcion, *arr = NULL, n, bus, pos;
    printf("Practica 1: Métodos de ordenamiento y búsqueda\n");
    do
    {
        printf("\n   1. Búsqueda Lineal");
        printf("\n   2. Búsqueda Binaria");
        printf("\n   3. Ordenamiento por Selección");
        printf("\n   4. Ordenamiento Lineal");
        printf("\n   5. Ordenamiento inserción");
        printf("\n   6. Salir.");

        /* Filtramos la opción elegida por el usuario */
        do
        {
            printf("\n   Introduzca opci%cn (1-6): ", 162);
            scanf("%d", &opcion);

        } while (opcion < 1 || opcion > 7);
        /* La opción sólo puede ser 1 al 6 */

        switch (opcion)
        {
        case 1: /* Busqueda Lineal */
            printf("\n  Búsqueda Lineal");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            imprimirArrInt(arr, n);
            printf("\n   Introduzca un n%cmero entero a buscar: ", 163);
            scanf("%d", &bus);
            pos = busquedaLineal(arr, n, bus);
            if (pos != -1)
                printf("\n   El numero %d se encuentra en la posicion %d del arreglo\n\n", bus, pos);
            else
                printf("\n   El numero %d no se encuentra en el arreglo\n\n", bus);
            break;
        case 2:
            printf("\n  Búsqueda Binaria");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            pos = busquedaBinaria(arr, n, 3);
            if (pos != -1)
                printf("\n   El numero %d se encuentra en la posicion %d del arreglo\n\n", 3, pos);
            else
                printf("\n   El numero %d no se encuentra en el arreglo\n\n", 3);
            break;

        case 3:
            printf("\n  Ordenamiento por Selección");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            ordInsercion(arr, n);
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 4:
            printf("\n  Ordenamiento Lineal");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            ordLineal(arr, n);
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 5:
            printf("\n  Ordenamiento por Inserción");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            ordBurbuja(arr, n);
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 6:
            printf("\n  Saliendo...\n");
            break;
        }

    } while (opcion != 4);

    return 0;
}
/*
int main(void)
{

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);
    CrearArrInt(&arr, n);
    llenarArrInt(arr, n);
    imprimirArrInt(arr, n);
    ordInsercion(arr, n); */
/* ordLineal(arr, n); */
/* ordBurbuja(arr, n); */
/* busquedaLineal(arr, n); */
/* printf("pos: %d\n", busquedaBinaria(arr, n, 3)); */
/* printf("\nArreglo ordenado: \n"); */
/* imprimirArrInt(arr, n); */
/* return 0; } */

/* Métodos de Busqueda */
int busquedaLineal(int arr[], int n, int bus)
{
    int i;
    /* printf("Ingrese el numero a buscar: ");
    scanf("%d", &bus); */
    for (i = 0; i < n; i++)
    {
        if (arr[i] == bus)
        {
            /* printf("El numero %d se encuentra en la posicion %d del arreglo\n", bus, i); */
            return i;
            /* flag = 1; */
            break;
        }
    }
    /* if (flag == 0)
    { */
    return -1;
    /* printf("El numero %d no se encuentra en el arreglo\n", bus); */
    /* } */
}

int busquedaBinaria(int arreglo[], int n, int llave)
{
    int izq = 0, der = n - 1, centro;

    while (izq <= der)
    {
        centro = (izq + der) / 2;

        if (arreglo[centro] == llave)
        {
            return centro;
        }
        else if (llave > arreglo[centro])
        {
            izq = centro + 1;
        }
        else
        {
            der = centro - 1;
        }
    }
    return -1;
}
/* metodos de ordenamiento */

void ordLineal(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ordInsercion(int arr[], int n)
{
    int i, j, menor, temp, pos;
    for (i = 0; i < n; i++)
    {
        menor = arr[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < menor)
            {
                menor = arr[j];
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = menor;
        arr[pos] = temp;
    }
}

void ordBurbuja(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/* funciones de arreglos */

void CrearArrInt(int **arr, int n)
{
    *arr = (int *)malloc(n * sizeof(int));
}

void liberarArrInt(int **arr)
{
    free(*arr);
    *arr = NULL;
}
void llenarArrInt(int *arr, int n)
{
    int i, m;
    printf("Ingrese los %d numeros enteros del arreglo\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &m);
        arr[i] = m;
    }
}

void imprimirArrInt(int *arr, int n)
{
    int i;
    printf("\nArreglo de numeros enteros: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
