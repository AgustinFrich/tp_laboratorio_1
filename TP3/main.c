#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main() {
    int option = 0;
    int aux;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	printf("Menu:\n"
    			" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
    			" 3. Alta de empleado.\n"
    			" 4. Modificar datos de empleado.\n"
    			" 5. Baja de empleado.\n"
    			" 6. Listar empleados.\n"
    			" 7. Ordenar empleados.\n"
    			" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    			"10. Salir\n");

		GetInt("\nIngrese una opcion: ", "La opcion seleccionada es incorrecta, intente nuevamente.", 1, 10, &option);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv", listaEmpleados)){
                	printf("\nSe cargaron los datos correctamente del archivo de texto.\n");
                } else {
                	printf("\nError, no se pudieron cargar los datos del archivo de texto.\n");
                }
                break;

            case 2:

                if(controller_loadFromBinary("data.bin", listaEmpleados)){
                	printf("\nSe cargaron los datos correctamente del archivo binario.\n");
				} else {
					printf("\nError, no se pudieron cargar los datos del archivo binario.\n");
				}

            	break;

            case 3:

            	aux = controller_addEmployee(listaEmpleados);
            	if(aux > 0){
            		printf("\nSe dio de alta correctamente en el ID nro: %d\n", aux);
            	} else {
            		printf("\nNo se pudo dar de alta.\n");
            	}
            	break;

            case 4:

            	aux = controller_editEmployee(listaEmpleados);
            	if(aux == 1){
            		printf("\nSe modifico el dato correctamente.\n");
            	} else {
            		if(aux == 0){
						printf("\nError, no se pudieron modificar los datos\n");
            		} else {
            			printf("\nError, no se puede modificar ningun dato ya que no se encuentran entradas.\n"
            					"\nIntente ingresando un empleado o cargando un archivo primero.\n");
            		}
            	}
            	break;

            case 5:

            	aux = controller_removeEmployee(listaEmpleados);
            	if(aux == 1){
            		printf("\nSe elimino el empleado correctamente\n");
            	} else {
            		if(aux == 0){
						printf("\nError, no se pudo eliminar\n");
            		} else {
            			printf("\nError, no se puede eliminar ya que no se encuentran entradas.\n"
            					"\nIntente ingresando un empleado o cargando un archivo primero.\n");
            		}
            	}
            	break;

            case 6:

            	if(!controller_ListEmployee(listaEmpleados)){
            		printf("\nError, no hay nada para mostrar. Pruebe con cargar un archivo o agregar un empleado.\n");
            	}
            	break;

            case 7:

            	if(controller_sortEmployee(listaEmpleados)){
            		printf("\nSe ordeno correctamente la lista.\n");
            	} else {
            		printf("\nError, no se pudo ordenar.\n");
            	}
            	break;

            case 8:

            	if(controller_saveAsText("data.csv", listaEmpleados)){
            		printf("\nSe guardo correctamente el archivo de texto.\n");
            	} else {
					printf("\nError, no se pudo guardar el archivo de texto.\n");
            	}
            	break;

            case 9:

            	if(controller_saveAsBinary("data.bin", listaEmpleados)){
            		printf("\nSe guardo correctamente el archivo binario.\n");
				} else {
					printf("\nError, no se pudo guardar el archivo binario.\n");
				}
            		break;

            case 10:
            	break;
        }

        printf("\n");

    }while(option != 10);

    printf("El programa finalizo correctamente\n");

    return 0;
}

