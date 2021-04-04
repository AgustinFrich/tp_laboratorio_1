/*
 * aritmetica.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Agus
 */

#include "aritmetica.h"

float Suma(float primerNumero, float segundoNumero){
	float respuesta;
	respuesta = primerNumero + segundoNumero;

	return respuesta;
}

float Resta(float primerNumero, float segundoNumero){
	float respuesta;
	respuesta = primerNumero - segundoNumero;

	return respuesta;
}

float Division(float primerNumero, float segundoNumero){
	float respuesta = 0;
	if(segundoNumero != 0){
		respuesta = primerNumero / segundoNumero;
	}

	return respuesta;
}

float Multiplicacion(float primerNumero, float segundoNumero){
	float respuesta;
	respuesta = primerNumero * segundoNumero;

	return respuesta;
}

float Factorial(float numero){
	float respuesta = 1;
	if(numero == 0){
		respuesta = 0;
	} else {
		for(int i = numero; i > 0; i--){
			respuesta *= i;
		}
	}
	return respuesta;
}
