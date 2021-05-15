/*
 * utn.h
 *
 *  Created on: 26 abr. 2021
 *      Author: Agus
 */

#ifndef INPUT_H_
#define INPUT_H_

//Obtener Inputs

/** \brief lee un string ingresado por consola y lo asigna a un puntero para su uso
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* resultado
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetString(char*, char*, int, int, char*); //sin limite de reintentos

/** \brief lee un string ingresado por consola y lo asigna a un puntero para su uso en un numero ingresado de reintentos
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int* reintentos
 * \param char* resultado
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetStringReintentos(char*, char*, int, int, int*, char*); //con limite de reintentos

//Transformar Inputs en Tipos sin limite de reintentos

/** \brief permite el ingreso de un entero por consola y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetInt(char*, char*, int, int, int*);

/** \brief permite el ingreso de un flotante por consola y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int minSize
 * \param int maxSize
 * \param int min
 * \param int max
 * \param float* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetFloat(char*, char*, int, int, int, int, float*);

/** \brief permite el ingreso de un caracter 'f' o 'm' por consola y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetGenero(char*, char*, int, int, char*);

/** \brief permite el ingreso de un caracter cualquiera por consola y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetChar(char*, char*, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que solo contenga letras y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetNombre(char*, char*, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que puede contener letras y numeros y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetAlfanumerico(char*, char*, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que puede contener los caracteres necesarios
 * para una direccion de email y guardarlo en un puntero.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/no esta en el rango de los valores minimo y maximo.
 *
 */
int GetMail(char*, char*, int, int, char*);





//Transformar Inputs en Tipos con limite de reintentos

/** \brief permite el ingreso de un entero por consola
 * y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int reintentos
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetIntReintentos(char*, char*, int, int, int, int*);

/** \brief permite el ingreso de un flotante por consola
 * y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int minSize;
 * \param int maxSize;
 * \param int min
 * \param int max
 * \param int reintentos
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetFloatReintentos(char*, char*, int, int, int, int, int, float*);

/** \brief permite el ingreso de un caracter cualquiera
 * y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int reintentos
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetCharReintentos(char*, char*, int, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que puede contener letras
 * y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int reintentos
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetNombreReintentos(char*, char*, int, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que puede contener letras y numeros
 * y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param int reintentos
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetAlfanumericoReintentos(char*, char*, int, int, int, char*);

/** \brief permite el ingreso de una cadena por consola que puede contener los caracteres necesarios
 * para una direccion de email y guardarlo en un puntero en un numero ingresado de reintentos.
 *
 * \param char* mensaje
 * \param char* mensajeError
 * \param int min
 * \param int max
 * \param char* input
 *
 * \return int retorna 0 si se asigna correctamente o -1 si algun valor de entrada es erroneo/
 * no esta en el rango de los valores minimo y maximo/el numero de reintentos se agota.
 *
 */
int GetMailReintentos(char*, char*, int, int, int, char*);




//Validaciones

/** \brief comprueba si la cadena recibida es un entero
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsNumeroValido(char*);

/** \brief comprueba si la cadena recibida es un flotante
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsFloatValido(char*);

/** \brief comprueba si la cadena recibida es un genero valido ('f' o 'm')
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsGeneroValido(char);

/** \brief comprueba si la cadena recibida es un caracter cualquiera
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsCharValido(char);

/** \brief comprueba si la cadena recibida es un string de letras
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsNombreValido(char*);

/** \brief comprueba si la cadena recibida es un string alfanumerico
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsAlfanumericoValido(char*);

/** \brief comprueba si la cadena recibida es un mail alfanumerico valido
 *
 * param char* charRecibido
 *
 * return int 1 si la comprobacioon es correcta y 0 si es erronea.
 *
 */
int EsMailValido(char*);
#endif /* INPUT_H_ */
