/*
 ============================================================================
 Name        : TP1.c
 Author      : Friadenrich Agustin
 Description : Calculadora con menu de opciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "aritmetica.h"
#include "validaciones.h"

int main(void) {

	int opcion = 0;
	float primerNumero = 0;
	float segundoNumero = 0;
	float respuestaA = 0;
	float respuestaB = 0;
	float respuestaC = 0;
	float respuestaD = 0;
	float respuestaE = 0;
	float respuestaESegunda = 0;
	char alertaNumerosEnCero;

	do {
		printf("1. Ingresar 1er operando (A = %.2f)\n", primerNumero);

		printf("2. Ingresar 2do operando (B = %.2f)\n", segundoNumero);

		printf("3. Calcular todas las operaciones:\n");
		printf("	a) Calcular la suma (A + B)\n");
		printf("	b) Calcular la resta (A - B)\n");
		printf("	c) Calcular la division (A / B)\n");
		printf("	d) Calcular la multiplicacion (A * B)\n");
		printf("	e) Calcular el factorial (A!)\n");

		printf("4. Informar resultados\n");

		printf("5. Salir\n");

		do {
			printf("\nIngrese una opcion: ");
			setbuf(stdout, NULL);
			scanf("%d", &opcion);

			switch(opcion){
			case 1:
				primerNumero = AgregarNumero();
				break;
			case 2:
				segundoNumero = AgregarNumero();
				break;
			case 3:
				alertaNumerosEnCero = ValidarOperandos(primerNumero, segundoNumero);

				if(alertaNumerosEnCero == 'n'){
					printf("\nEl calculo de operaciones se ha cancelado.\n\n");
					break;
				} else {
					respuestaA = Suma(primerNumero, segundoNumero);
					respuestaB = Resta(primerNumero, segundoNumero);
					respuestaC = Division(primerNumero, segundoNumero);
					respuestaD = Multiplicacion(primerNumero, segundoNumero);
					respuestaE = Factorial(primerNumero);
					respuestaESegunda = Factorial(segundoNumero);
					printf("\nSe han realizado todos los calculos correspondientes.\n\n");
					break;
				}

			case 4:
				alertaNumerosEnCero = ValidarOperandos(respuestaA, respuestaB);

				if(alertaNumerosEnCero == 'n'){
					printf("\nEl informe de resultados se ha cancelado.\n\n");
					break;
				} else {
					printf("\na) El resultado de A + B es: %.2f\n", respuestaA);
					printf("b) El resultado de A - B es: %.2f\n", respuestaB);
						if(segundoNumero == 0){
							printf("c) No es posible dividir por cero.\n");
						} else {
							printf("c) El resultado de A / B es: %.2f\n" , respuestaC);
						}
					printf("d) El resultado de A * B es: %.3f\n", respuestaD);
					printf("e) El factorial de A es: %.2f y El factorial de B es: %.2f\n\n", respuestaE, respuestaESegunda);
				}

					break;
			case 5:
				break;
			default:
				printf("Error, no se ha ingresado una opcion valida");
			}

		} while(opcion < 1 || opcion > 5);

	} while(opcion != 5);

	printf("\nEl programa ha finalizado.");
	return EXIT_SUCCESS;
}
