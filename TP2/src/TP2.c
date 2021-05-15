/*
 ============================================================================
 Name        : TP2.c
 Author      : Friadenrich Agustin
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "Menu.h"

#define len 10

int main(void) {

	Employee list[len];

	InitEmployees(list, len);


	AddEmployee(list, len, 1, "Agus", "Friadenrich", 2100, 41, 0);
	AddEmployee(list, len, 2, "Fernando", "Bernandez", 5000, 41, 1);
	AddEmployee(list, len, 3, "Bernardo", "Jimenes", 5300, 42, 2);
	AddEmployee(list, len, 4, "German", "Alvarez", 6000, 42, 3);
	AddEmployee(list, len, 5, "Ramiro", "Fernandez", 6200, 41, 4);

	SwitchMenuPrincipal(list, len);

	return EXIT_SUCCESS;
}
