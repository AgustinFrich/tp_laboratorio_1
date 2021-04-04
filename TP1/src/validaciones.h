/*
 * aritmetica.h
 *
 *  Created on: 25 mar. 2021
 *      Author: Friadenrich Agustín
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/** \brief funcion que permite ingresar un numero flotante por consola
 *
 * \return float el numero ingresado
 *
 */
float AgregarNumero();

/** \brief funcion que valida que los numeros ingresados no sean 0
 * y consulta si se desa continuar en el caso de que lo sean
 *
 * \param float primerNumero
 * \param float segundoNumero
 * \return char 's' si se puede continuar y 'n' si se desea cancelar
 *
 */
char ValidarOperandos(float, float);

#endif /* VALIDACIONES_H_ */
