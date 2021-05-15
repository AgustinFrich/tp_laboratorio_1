/*
 * Employees.c
 *
 *  Created on: 2 may. 2021
 *      Author: Agus
 *
 *  int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
 */

#include <stdio.h>
#include <string.h>

#include "ArrayEmployees.h"

#include "Input.h"
#define VACIO -1
#define OCUPADO 0

int InitEmployees(Employee* list, int len){
	int retorno = -1;
    int i;

    	if(list != NULL && len > 0){
    		retorno = 0;

			for(i = 0; i < len; i++){
				(list + i)->id = -1;
				strcpy((list + i)->name, "-1");
				strcpy((list + i)->lastName, "-1");
				(list + i)->salary = 0;
				(list + i)->sector = -1;
				(list + i)->isEmpty = VACIO;
			}
    	}
	return retorno;
}

int FindFreeSpace(Employee* list, int len){
	int i;
	int indice = -1;

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if((list + i)->isEmpty == VACIO){
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int FindEmployeeById(Employee* list, int len, int id){
    int i;
    int indice = -1;

    for(i = 0; i < len; i++){
        if((list + i)->id == id && (list + i)->isEmpty == OCUPADO){
            indice = i;
            break;
        }
    }

    return indice;
}

int CountEmployees(Employee* list, int len){
	int retorno = 0;
	int i;

	if(list != NULL && len > 0){
		for(i = 0; i < len; i++){
			if((list + i)->isEmpty == OCUPADO){
				retorno++;
			}
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int InputNewEmployee(Employee* list, int len){
	int retorno = -1;
	int indice;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	if(list != NULL && len > 0){
		indice = FindFreeSpace(list, len);
		if(indice != -1){

			id = indice + 1;

			if(id > 0){

				while(GetNombre("\nIngrese el nombre (hasta 50 caracteres): ",
						"Error, el nombre es demasiado largo o contiene caracteres que no son validos.", 1, 50, name) != 0);

				while(GetNombre("\nIngrese el apellido (hasta 50 caracteres): ",
						"Error, el nombre es demasiado largo o contiene caracteres que no son validos.", 1, 50, lastName) != 0);

				while(GetFloat("\nIngrese el salario (hasta $1.000.000): $",
						"Error, el salario esta fuera de rango o el numero es demasiado largo.", 1, 12, 1, 1000000, &salary) != 0);

				while(GetInt("\nIngrese el sector (El rango es de 1 a 100): ",
						"Error, el sector esta fuera de rango o el numero es demasiado largo.", 1, 100, &sector) != 0);
			}

			if(AddEmployee(list, len, id, name, lastName, salary, sector, indice) != -1){
				retorno = 0;
			}
		}
	} else {
		retorno = -2;
	}

	return retorno;
}

int AddEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector, int indice){
	int retorno = -1;

	if(indice != -1 && id != -1){
		(list + indice)->id = id;
		strcpy((list + indice)->name, name);
		strcpy((list + indice)->lastName, lastName);
		(list + indice)->salary = salary;
		(list + indice)->sector = sector;
		(list + indice)->isEmpty = OCUPADO;
		retorno = 0;
	}
	return retorno;
}

int RemoveEmployee(Employee* list, int len){
int id = -1;
int aux;
int retorno = -1;
	if(list != NULL && len > 0){
		do {
			if(PrintEmployees(list, len) > 0){
				aux = GetInt("\nIngrese el ID del empleado a eliminar. \nEl rango es 1 a 1000, o ingrese 0 para cancelar: ", "Error, el ID esta fuera de rango.", 0, 1000, &id);
				if(id == 0){
					id--;
					break;
				}
				if(FindEmployeeById(list, len, id) == -1){
					printf("\nError, el ID no se encuentra.\n");
					aux = -1;
				}
			} else {
				retorno = -2;
				break;
			}
		} while (aux != 0);

		if(RemoveEmployeeByID(list, len, id) != -1 && id > 0){
			retorno = 0;
		}
	} else {
		retorno = -3;
	}
	return retorno;
}

int RemoveEmployeeByID(Employee* list, int len, int id){
	int indice;

	indice = FindEmployeeById(list, len, id);

	if(indice != -1){
		(list + indice)->isEmpty = VACIO;
	}

	return indice;
}

int ModifyEmployee(Employee* list, int len){
    int retorno = -1;
    int i;
    int id;
    int opcion;
    char auxiliarChar[51];
    float salary;
    int sector;

    if(list != NULL && len > 0){
        if(PrintEmployees(list, len) > 0){
            GetIntReintentos("\nIngrese el ID del empleado a modificar: ", "Error, Ingrese un ID correcto para modificar: ", 1, 10000, 3, &id);

            i = FindEmployeeById(list, len, id);

            if(i != -1 && (list + i)->isEmpty == OCUPADO){
            PrintOneEmployee(list + i);

            GetIntReintentos("\n\nIngrese 0 para CANCELAR."
            		"\nIngrese 1 para modificar el NOMBRE del empleado."
            		"\nIngrese 2 para modificar el APELLIDO del empleado."
            		"\nIngrese 3 para modificar el SALARIO del empleado"
            		"\nIngrese 4 para modificar el SECTOR"
            		"\n\nIngrese el dato a modificar: ",
					"\nError, la opcion seleccionada no se ha encontrado. Intente nuevamente.\n", 0, 4, 3, &opcion);

                switch(opcion){
                    case 0:
                        break;
                    case 1:
            			while(GetNombre("\nIngrese el nombre (hasta 50 caracteres): ",
            				"Error, el nombre es demasiado largo o contiene caracteres que no son validos.", 1, 50, auxiliarChar) != 0);

            			strcpy((list + i)->name, auxiliarChar);
                    	break;
                    case 2:
            			while(GetNombre("\nIngrese el apellido (hasta 50 caracteres): ",
            				"Error, el nombre es demasiado largo o contiene caracteres que no son validos.", 1, 50, auxiliarChar) != 0);

            			strcpy((list + i)->lastName, auxiliarChar);
                        break;
                    case 3:
            			while(GetFloat("\nIngrese el salario (hasta $1.000.000): $",
            				"Error, el salario esta fuera de rango o el numero es demasiado largo.", 1, 12, 1, 1000000, &salary) != 0);

            			(list + i)->salary = salary;
                    	break;
                    case 4:
            			while(GetInt("\nIngrese el sector (El rango es de 1 a 100): ",
            				"Error, el sector esta fuera de rango o el numero es demasiado largo.", 1, 100, &sector) != 0);

            			(list + i)->sector = sector;
                    	break;
                    default:
                        printf("\nError, la opcion seleccionada no se ha encontrado.");
                }
				if(opcion != 0) {
					retorno = 0;
				}
    		} else {
    			retorno = -2;
    		}
        } else {
            retorno = -3;
        }
    } else {
        retorno = -4;
    }
    return retorno;
}

int PrintEmployees(Employee* list, int length){
	int retorno = 0;
	int i;

	if(list != NULL && length > 0){
		for(i = 0; i < length; i++){
			if((list + i)->isEmpty == OCUPADO){
				retorno++;
				PrintOneEmployee(list + i);
			}
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int PrintOneEmployee(Employee* employee){
	int retorno = -1;
if(employee->isEmpty == OCUPADO){
retorno = 0;
	printf("%2d. %20s %20s - salario: %10.2f - sector: %5d\n",
			employee->id, employee->name, employee->lastName, employee->salary, employee->sector);
}

	return retorno;
}

int SortEmployees(Employee* list, int len, int order){
	int retorno = -1;
		if(list != NULL && len > 0 && (order == 1 || order == 0)){
			retorno = 0;

			SortByLastName(list, len, order);

			SortBySector(list, len, order);
		}

	return retorno;
}

void SortBySector(Employee* list, int len, int order){
	Employee aux;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if((list + i)->sector > (list + j)->sector && order == 1){
				aux = *(list + i);
				*(list + i) = *(list + j);
				*(list + j) = aux;
			} else {
				if((list + i)->sector < (list + j)->sector && order == 0){
					aux = *(list + i);
					*(list + i) = *(list + j);
					*(list + j) = aux;
				}
			}
		}
	}
}


void SortByLastName(Employee* list, int len, int order){
	Employee aux;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp((list + i)->lastName, (list + j)->lastName) > 0 && order == 1){
				aux = *(list + i);
				*(list + i) = *(list + j);
				*(list + j) = aux;
			} else {
				if(stricmp((list + i)->lastName, (list + j)->lastName) < 0 && order == 0){
					aux = *(list + i);
					*(list + i) = *(list + j);
					*(list + j) = aux;
				}
			}
		}
	}
}

void SortByID(Employee* list, int len){
	Employee aux;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if((list + i)->id > (list + j)->id){
				aux = *(list + i);
				*(list + i) = *(list + j);
				*(list + j) = aux;
			}
		}
	}
}

int CalculateTotalAndAverage(Employee* list, int len, float* total, float* average){
	int retorno = 0;
	int contador = 0;
	int i;

	if(total != NULL && average != NULL){
		for(i = 0; i < len; i++){
			if((list + i)->isEmpty == OCUPADO){
				*total += (list + i)->salary;
				contador++;
			}
		}

		*average = *total / (float)contador;
		retorno = 1;
	}
	return retorno;
}

int ShowTotalAndAverage(Employee* list, int len){
	int retorno = 0;
	float total = 0;
	float average;
	int contadorMayorPromedio = 0;
	int i;

	if(list != NULL && len > 0){
		if(CountEmployees(list, len) > 0){
			if(CalculateTotalAndAverage(list, len, &total, &average)){
				printf("\nEl TOTAL de los salarios es de: $%.2f\n", total);

				printf("\nEl PROMEDIO de los salarios es de: $%.2f\n", average);

				printf("\nSe muestran los empleados que superan al PROMEDIO de SALARIOS: \n");

				for(i = 0; i < len; i++){
					if((list + i)->salary > average && (list + i)->isEmpty == OCUPADO){
						contadorMayorPromedio++;
						PrintOneEmployee(list + i);
					}
				}

				printf("\nEl total de empleados que superan el salario promedio es de %d empleados.\n", contadorMayorPromedio);
				retorno = 1;
			}
		}
	} else {
		retorno = -1;
	}
	return retorno;
}


