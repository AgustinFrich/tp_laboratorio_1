#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Employee.h"


Employee* employee_new(){
	Employee * empleado;

	empleado = (Employee*) malloc(sizeof(Employee));

	return empleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){
	int flag = 0;
	Employee * empleado;

	empleado = employee_new();

	if(employee_setId(empleado, atoi(idStr)) && EsNumeroValido(idStr)){
		if(employee_setNombre(empleado, nombreStr)){
			if(employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr)) && EsNumeroValido(horasTrabajadasStr)){
				if(employee_setSueldo(empleado, atoi(sueldoStr)) && EsNumeroValido(sueldoStr)){
					flag = 1;
				}
			}
		}
	}

	if(!flag){
		employee_delete(empleado);
		empleado = NULL;
	}

	return empleado;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

int employee_mostrarUnEmpleado(Employee * empleado){
	int retorno = 0;
	int id = 0;
	char nombre[128];
	int horasTrabajadas = 0;
	int sueldo = 0;

	if(empleado != NULL){
		if(employee_getId(empleado, &id) && employee_getNombre(empleado, nombre) &&
		   employee_getHorasTrabajadas(empleado, &horasTrabajadas) && employee_getSueldo(empleado, &sueldo)){
				printf("%4d  -  %20s  -  %16d  -  %10d\n", id, nombre, horasTrabajadas, sueldo);
				retorno = 1;
		}
	}
	return retorno;
}



int employee_setId(Employee* this, int id){
	int retorno = 0;

	if(this != NULL && id >= 1){
			this->id = id;
			retorno = 1;
	}

	return retorno;
}
int employee_getId(Employee* this, int* id){
	int retorno = 0;

	if(this != NULL && id != NULL){
			*id = this->id;
			retorno = 1;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre){
	int retorno = 0;

	if(this != NULL && nombre != NULL){
		if(EsNombreYApellidoValido(nombre)){
			strcpy(this->nombre, nombre);
			retorno = 1;
		}

	}

	return retorno;
}
int employee_getNombre(Employee* this, char* nombre){
	int retorno = 0;

	if(this != NULL && nombre != NULL){
			strcpy(nombre, this->nombre);
			retorno = 1;

	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int retorno = 0;

	if(this != NULL && horasTrabajadas > 0){
			this->horasTrabajadas = horasTrabajadas;
			retorno = 1;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int retorno = 0;

	if(this != NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo){
	int retorno = 0;

	if(this != NULL && sueldo > 0){
			this->sueldo = sueldo;
			retorno = 1;
	}

	return retorno;
}
int employee_getSueldo(Employee* this, int* sueldo){
	int retorno = 0;

	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

int employee_compareByName(Employee* empleado1, Employee* empleado2){
	int retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL){
		retorno = strcmp(empleado1->nombre, empleado2->nombre);
	}

	return retorno;
}

int employee_compareByID(Employee* empleado1, Employee* empleado2){
	int retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL){
		if(empleado1->id > empleado2->id){
			retorno = 1;
		} else {
			if(empleado1->id < empleado2->id){
			retorno = -1;
			}
		}
	}

	return retorno;

}

int employee_compareByWorkedHours(Employee* empleado1, Employee* empleado2){
	int retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL){
		if(empleado1->horasTrabajadas > empleado2->horasTrabajadas){
			retorno = 1;
		} else {
			if(empleado1->horasTrabajadas < empleado2->horasTrabajadas){
				retorno = -1;
			}
		}
	}

	return retorno;

}

int employee_compareBySalary(Employee* empleado1, Employee* empleado2){
	int retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL){
		if(empleado1->sueldo > empleado2->sueldo){
			retorno = 1;
		} else {
			if(empleado1->sueldo < empleado2->sueldo){
				retorno = -1;
			}
		}
	}

	return retorno;

}

