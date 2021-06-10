#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;

	Employee * empleado;

	char id[10];
	char nombre[128];
	char horasTrabajadas[20];
	char sueldo[15];

	//fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

	if(pArrayListEmployee != NULL && pFile != NULL){
		ll_clear(pArrayListEmployee);
	        while(!feof(pFile)){
	            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4){

					empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

					if(empleado != NULL){
						if(!ll_add(pArrayListEmployee, empleado)){
							retorno = 1;
						}
					}
	            }
	        }
	    }
	    return retorno;

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int cant;
	Employee * empleado = NULL;

	ll_clear(pArrayListEmployee);

	while(!feof(pFile)){
		empleado = employee_new();
		cant = fread(empleado, sizeof(Employee), 1, pFile);
		if(cant == 1){
			if(empleado != NULL){
				if(!ll_add(pArrayListEmployee, empleado)){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}


