/*
 * Menu.c
 *
 *  Created on: 2 may. 2021
 *      Author: Agus
 */

#include <stdio.h>

#include "Menu.h"
#include "Input.h"

void SwitchMenuPrincipal(Employee* list, int len){
	int opcion = -1;
    int aux;
	do {
		printf("MENU PRINCIPAL. \n");
		printf("1. Ir dar ALTA.\n");
		printf("2. Ir a dar BAJA.\n");
		printf("3. Ir a MODIFICACION.\n");
		printf("4. Ir a Menu LISTADOS.\n");
		printf("5. SALIR.\n");

		GetInt("\nIngrese una opcion: ", "Error, ingrese una opcion correcta.", 1, 6, &opcion);

		switch(opcion){
		case 1:
            printf("\nSe esta dando de alta.\n");

            aux = InputNewEmployee(list, len);

            switch(aux){
                case 0:
                    printf("\nSe ha dado de alta correctamente.\n");
                break;
                case -1:
                    printf("\nNo hay espacio disponible para ingresar un empleado. Regresando al menu.\n");
                break;
                default:
                    printf("\nError, no se ha podido ingresar un trabajador correctamente.\n");
                break;
            }
			break;

		case 2:
            printf("\nSe esta dando de baja.\n");

            aux = RemoveEmployee(list, len);

             switch(aux){
                case 0:
                    printf("\nSe ha eliminado el empleado con exito.\n");
                break;
                case -1:
                    printf("\nNo se ha podido eliminar.\n");
                break;
                case -2:
                	printf("\nError, se debe dar de alta primero. No hay entradas para eliminar.\n");
                	break;
                default:
                    printf("\nError, alguno de los datos del sistema es incorrecto.\n");
                break;
            }
			break;

		case 3:
            printf("\nSe esta modificando un producto.\n\n");
            aux = ModifyEmployee(list, len);

            switch(aux){
                case 0:
                    printf("\nSe ha modificado correctamente el empleado.\n");
                break;
                case -1:
                	printf("\nSe ha cancelado el ingreso de datos. Regresando al menu.\n");

                break;
                case -2:
                	printf("\nError, no se pudo encontrar el ID seleccionado. No se ha podido modificar.\n");

                break;
                case -3:
                	printf("\nError, no hay empleados disponibles para modificar. Ingrese alguno primero.\n");
                break;
                default:
                    printf("\nError, alguno de los datos del sistema es incorrecto.\n");
            }
			break;

		case 4:
			printf("\nSe muestra el menu de listados\n");

			SwitchMenuListados(list, len);
			break;
		case 5:
			break;
		}
		printf("\n");
	}
	while(opcion != 5);
}

void SwitchMenuListados(Employee* list, int len){
	int opcion;
	int aux;

	do {
		printf("\nMENU LISTADOS. \n");
		printf("1. Mostrar listado de EMPLEADOS ordenados alfabeticamente por sector.\n");
		printf("2. Mostrar TOTAL y promedio de los SALARIOS, y cuantos empleados SUPERAN el SALARIO PROMEDIO.\n");
		printf("3. REGRESAR.\n");

		GetInt("\nIngrese una opcion: ", "Error, ingrese una opcion correcta.", 1, 6, &opcion);

		switch(opcion){
		case 1:
			printf("\nSe muestra el listado de empleados.\n\n");
			SwitchSortEmployees(list, len);

			break;
		case 2:
			printf("\nSe muestran el TOTAL, el PROMEDIO de los SALARIOS y cuantos empleados SUPERAN el SALARIO PRIMEDIO.\n");

			aux = ShowTotalAndAverage(list, len);

			if(aux == 0){
				printf("\nError, no hay empleados disponibles para mostrar los datos. Ingrese alguno primero.\n");
			} else {
				if(aux == -1){
					printf("\nError, alguno de los datos ingresados es incorrecto.\n");
				}
			}

			break;
		case 3:
			printf("\nRegresando al menu principal...\n");
		}
	} while(opcion != 3);
}

void SwitchSortEmployees(Employee* list, int len){
	int opcion;

	GetInt("\nIngrese 1 para ordenar de forma ascendente,"
			"\nO 0 para ordenar de forma descendente: ", "Error, ingrese una opcion correcta.", 0, 1, &opcion);

	SortEmployees(list, len, opcion);
	if(!PrintEmployees(list, len)){
		printf("\nError, no hay empleados para mostrar. Ingrese alguno primero.\n");
	}
	SortByID(list, len);
}
