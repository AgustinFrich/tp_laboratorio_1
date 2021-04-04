#include "validaciones.h"
#include <stdio.h>

float AgregarNumero(){
	float numero;
	printf("\nIngrese el numero:");
	fflush(stdout);
	scanf("%f", &numero);
	return numero;
}

char ValidarOperandos(float primerNumero, float segundoNumero){
	char alertaNumerosEnCero = 's';
	if(primerNumero == 0 && segundoNumero == 0){
		do {
			printf("\nAlerta, el valor de ambos numeros es 0, ¿Desea continuar?"
			"(ingrese 's' para si y 'n' para no): ");
			fflush(stdin);
			scanf("%c", &alertaNumerosEnCero);
		} while(alertaNumerosEnCero != 's' && alertaNumerosEnCero != 'n');
	}
	return alertaNumerosEnCero;
}
