#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "Input.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
	int retorno = 0;
	FILE * pFile;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "r");
		if(pFile != NULL){
			if(parser_EmployeeFromText(pFile, pArrayListEmployee)){
				if(controller_saveMaxIDWhileLoad("auxiliarData.txt", pArrayListEmployee)){
					retorno = 1;
				}
			}
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	int retorno = 0;
	FILE * pFile;

	if(path != NULL && pArrayListEmployee != NULL){

		pFile = fopen(path, "rb");

		if(pFile != NULL){
			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)){
				if(controller_saveMaxIDWhileLoad("auxiliarData.txt", pArrayListEmployee)){
					retorno = 1;
				}
			}
		}

		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
	Employee* empleado;

	int retorno = 0;
	int nuevoID = 0;

	char id[20];
	char nombre[128];
	char horasTrabajadas[20];
	char sueldo[20];

	if(pArrayListEmployee!=NULL && controller_readMaxID("auxiliarData.txt", &nuevoID)){
		nuevoID++;
		sprintf(id, "%d", nuevoID);

		if(GetNombreReintentos("\nIngrese el nombre del empleado: ","Error, el nombre ingresado no es correcto. Intente nuevamente.", 1, 128, 3, nombre) != -1){
			if(GetStringNumericoReintentos("\nIngrese las horas trabajadas: ", "Error, el numero ingresado no es correcto. Intente nuevamente.", 1, 20, 3, horasTrabajadas) != -1){
				if(GetStringNumericoReintentos("\nIngrese el salario del trabajador: ", "Error, el numero ingresado no es correcto. Intente nuevamente", 1, 20, 3, sueldo) != -1){
					empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

					if(!ll_add(pArrayListEmployee, empleado) && controller_saveMaxIDWhileAdding("auxiliarData.txt", empleado)){
							retorno = nuevoID;
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
	int retorno = 0;
	int index;
	int id;
	int opcion;
	int auxTam;

	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	Employee* empleado;

	if(pArrayListEmployee != NULL && controller_ListEmployee(pArrayListEmployee) && controller_readMaxID("auxiliarData.txt", &auxTam)){
		if(GetIntReintentos("\nIngrese el id del empleado a modificar: ","Error, el id ingresado no es correcto. Intente nuevamente.", 1, auxTam, 3, &id) != -1){
			printf("\nSe muestra el empleado seleccionado: \n");
			empleado = controller_searchByID(pArrayListEmployee, id);
			if(empleado != NULL && employee_mostrarUnEmpleado(empleado)){
				index = ll_indexOf(pArrayListEmployee, empleado);

				if(GetIntReintentos("\nIngrese la caracteristica a modificar.\nIngrese 1 si desea modificar el NOMBRE."
						"\nIngrese 2 si desea modificar las HORAS TRABAJADAS\nIngrese 3 si desea modificar el SALARIO."
						"\nLa opcion elegida es: ", "Error, la opcion elegida es incorrecta.", 1, 3, 3, &opcion) != -1){

					switch(opcion){
						case 1:
							if(GetNombreReintentos("\nIngrese el nuevo nombre para el empleado: ",
							"Error, el numero ingresado no es valido", 1, 128, 3, nombre) != -1){

								strcpy(empleado->nombre, nombre);
							}
							break;

						case 2:
							if(GetIntReintentos("\nIngrese el nuevo valor de las HORAS TRABAJADAS: ",
							"Error, el numero ingresado no es valido", 1, 99999999, 3, &horasTrabajadas) != -1){

								empleado->horasTrabajadas = horasTrabajadas;
							}
							break;

						case 3:
							if(GetIntReintentos("\nIngrese el nuevo valor del SALARIO: ",
							"Error, el numero ingresado no es valido", 1, 99999999, 3, &sueldo) != -1){

								empleado->sueldo = sueldo;
							}
							break;
					}
					if(!ll_set(pArrayListEmployee, index, empleado)){
						retorno = 1;
					}
				}
			}
		}
	} else {
		retorno = -1;
	}
	return retorno;
}

/** \brief Busca en una linkedList un empleado a traves de una id ingresada
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return Employee*
 *
 */
Employee* controller_searchByID(LinkedList* pArrayListEmployee, int id){
	Employee* empleado;
	int i;
	int auxId;
	int auxLen;

	if(pArrayListEmployee != NULL){
		auxLen = ll_len(pArrayListEmployee);

		for(i = 0; i < auxLen; i++){
			empleado = (Employee*)ll_get(pArrayListEmployee, i);
			if(employee_getId(empleado, &auxId)){
				if(auxId == id){
					break;
				} else {
					empleado = NULL;
				}
			}
		}
	}
	return empleado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
	Employee* empleado;
	int retorno = 0;
	int index;
	int id;
	int idMaximo;

	if(controller_readMaxID("auxiliarData.txt", &idMaximo)){
		if(controller_ListEmployee(pArrayListEmployee)){
			if(GetIntReintentos("\nIngrese el id del empleado a eliminar: ", "Error, el id ingresado no es correcto. Intente nuevamente.", 1, idMaximo, 3, &id) != -1){
				empleado = controller_searchByID(pArrayListEmployee, id);
				if(empleado != NULL){
					index = ll_indexOf(pArrayListEmployee, empleado);

					if(!ll_remove(pArrayListEmployee, index)){
						retorno = 1;
					}
				}
			}
		}
	} else {
		retorno = -1;
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
	int retorno = 0;
    int i;
    int auxLen = -1;
    Employee* empleado;

    if(pArrayListEmployee != NULL){
    auxLen = ll_len(pArrayListEmployee);
		if(auxLen > 0){
			printf("\n  ID                   NOMBRE     HORAS TRABAJADAS         SUELDO \n");

			for(i = 0; i < auxLen; i++){

				empleado = (Employee*)ll_get(pArrayListEmployee, i);

				if(employee_mostrarUnEmpleado(empleado)){
					retorno = 1;
				}
			}
		}
    }

	return retorno;

}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
	int retorno = 0;
	int orden;
	int seleccion;
	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0){
		if(GetIntReintentos("\nIngrese el modo de ORDENAMIENTO.\n 1 para ordenar por ID.\n "
					"2 para ordenar por NOMBRE.\n 3 para ordenar por HORAS TRABAJADAS.\n "
					"4 para ordenar por SALARIO.\nEl modo de ordenamiento es: ", "Error, el numero ingresado no es correcto.\n", 1, 4, 3, &seleccion) != -1){

			if(GetIntReintentos("\nIngrese el ORDEN.\n 1 para ASCENDENTE.\n 0 para DESCENDENTE.\nEl orden es: ", "Error, el numero ingresado no es correcto.\n", 0, 1, 3, &orden) != -1){
				printf("\nOrdenando, espere un momento...\n");
				switch(seleccion){
					case 1:
						if(!ll_sort(pArrayListEmployee, employee_compareByID, orden)){
							retorno = 1;
						}
						break;
					case 2:
						if(!ll_sort(pArrayListEmployee, employee_compareByName, orden)){
							retorno = 1;
						}
						break;
					case 3:
						if(!ll_sort(pArrayListEmployee, employee_compareByWorkedHours, orden)){
							retorno = 1;
						}
						break;
					case 4:
						if(!ll_sort(pArrayListEmployee, employee_compareBySalary, orden)){
							retorno = 1;
						}
						break;
				}
			}
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	int retorno = 0;
	int auxTam;
	int i;

	int id = 0;
	char nombre[128];
	int horasTrabajadas = 0;
	int sueldo = 0;

	FILE * pFile;
	Employee* empleado;

	pFile = fopen(path, "w");

	if(pFile !=NULL && pArrayListEmployee!=NULL){
		auxTam = ll_len(pArrayListEmployee);

		if(auxTam > 0){
			for(i = 0; i < auxTam; i++){
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				if(empleado != NULL){
					if(employee_getId(empleado, &id) && employee_getNombre(empleado, nombre) &&
					   employee_getHorasTrabajadas(empleado, &horasTrabajadas) && employee_getSueldo(empleado, &sueldo)){
							fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
					}
				}
			}

			fclose(pFile);

			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
	int retorno = 0;
	int auxTam;
	int i;

	FILE * pFile;
	Employee* empleado;

	pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListEmployee != NULL){
		auxTam = ll_len(pArrayListEmployee);

		if(auxTam > 0){
			for(i = 0; i < auxTam; i++){
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(empleado, sizeof(Employee), 1, pFile);
			}

			fclose(pFile);

			retorno = 1;
		}
	}
	return retorno;
}

int controller_saveMaxIDWhileLoad(char*path, LinkedList* pArrayListEmployee){
	int retorno = 0;
	int id = 0;
	int auxTam;

	FILE * pFile;
	LinkedList * pArrayAux;
	Employee * empleado;

	pFile = fopen(path, "w");

	if(pArrayListEmployee != NULL){
		pArrayAux = ll_clone(pArrayListEmployee);

		if(!ll_sort(pArrayAux, employee_compareByID, 1)){ // ordena un clon del auxiliar en caso de que el archivo no este ordenado
			auxTam = ll_len(pArrayAux);

			if(auxTam > 0){
				empleado = ll_get(pArrayAux, auxTam -1);
				employee_getId(empleado, &id);
			}
		}
	}

	if(id > 0){
		fprintf(pFile, "%d", id);
		retorno = 1;
	}

	fclose(pFile);

	return retorno;
}

int controller_saveMaxIDWhileAdding(char * path, Employee* empleado){
	int id;
	int retorno = 0;
	FILE * pFile;

	pFile = fopen(path, "w");

	if(empleado != NULL){
		if(employee_getId(empleado, &id)){
			if(id > 0){
				fprintf(pFile, "%d", id);
				retorno = 1;
			}
		}
	}

	fclose(pFile);

	return retorno;
}

int controller_readMaxID(char * path, int * id){
	int retorno = 0;
	FILE * pFile;
	char idAux[20];
	pFile = fopen(path, "r");

	if(id != NULL){
		fscanf(pFile, "%[^\n]", idAux);
		if(EsNumeroValido(idAux)){
			*id = atoi(idAux);
		}
		retorno = 1;
	}

	fclose(pFile);

	return retorno;
}
