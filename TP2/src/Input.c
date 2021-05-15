#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Input.h"

//Obtener Inputs
int GetString(char* mensaje, char* mensajeError, int min, int max, char* resultado){
    int retorno = -1;
    char bufferStr[max+10];

    if(mensaje != NULL && mensajeError != NULL && min <= max && resultado != NULL && bufferStr != NULL){
            setbuf(stdout, NULL);
            printf("%s", mensaje);
            setbuf(stdout, NULL);

            fgets(bufferStr, sizeof(bufferStr), stdin); //Lee la entrada
            setbuf(stdout, NULL);
            bufferStr[strlen(bufferStr) -1 ] = '\0'; // Anade el \0

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max){
                strncpy(resultado, bufferStr, max); //Se copia al resultado
                retorno = 0;
            } else {
                printf("\n%s \n", mensajeError);
                setbuf(stdout, NULL);
            }
    }
    return retorno;
}

int GetStringReintentos(char* mensaje, char* mensajeError, int min, int max, int* reintentos, char* resultado){
    int retorno= -1;
    char bufferStr[max+10];

    if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && resultado != NULL){
        do {
        	setbuf(stdout, NULL);
            printf("%s", mensaje);
            setbuf(stdout, NULL);

            fgets(bufferStr, sizeof(bufferStr), stdin); //Lee la entrada
            setbuf(stdout, NULL);

            bufferStr[strlen(bufferStr) -1 ] = '\0'; // Anade el \0

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max){
                strncpy(resultado, bufferStr, max); //Se copia al resultado
                retorno = 0;
                break;
            } else {
                printf("\n%s \n", mensajeError);
                setbuf(stdout, NULL);
                printf("\nQuedan %d reintentos\n", *(reintentos));
                setbuf(stdout, NULL);
            }

            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

//Transformar Inputs en Tipos sin limite de reintentos
int GetInt(char* mensaje, char* mensajeError, int min, int max, int *input){
	int retorno = -1;
    int maxSize = 15;
    int minSize = 1;
	char bufferStr[maxSize];

	if(mensaje != NULL && mensajeError != NULL && minSize <= maxSize && min <= max && input != NULL){
            if(!GetString(mensaje, mensajeError, minSize, maxSize, bufferStr)){
                if(EsNumeroValido(bufferStr) == 1 && strlen(bufferStr) < 21) {
                    *input = atoi(bufferStr);
                    	if(*input >= min && *input <= max){
							retorno = 0;
                    	} else {
                    		strcpy(bufferStr, "-x");
                    		printf("\n%s \n", mensajeError);
							setbuf(stdout, NULL);
                    	}
                } else {
                	strcpy(bufferStr, "-1");
                    printf("\n%s \n", mensajeError);
                    setbuf(stdout, NULL);
                }
            }
        }
    return retorno;
	}

int GetFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, float* input){
    int retorno =- 1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError!= NULL && minSize < maxSize && min <= max && input != NULL) {
	   if(!GetString(mensaje, mensajeError, minSize, maxSize, bufferStr)){
			if(EsFloatValido(bufferStr) == 1 && strlen(bufferStr) < 19){
				*input = atof(bufferStr);
				retorno = 0;
			} else {
				strcpy(bufferStr, "-1");
				printf("\n%s \n", mensajeError);
				setbuf(stdout, NULL);
			}
		}
    }
    return retorno;
}

int GetGenero(char* mensaje, char* mensajeError, int min, int max, char* resultado){
    int retorno = -1;
    char bufferChar[256];

    if(mensaje != NULL && mensajeError != NULL && min <= max && resultado != NULL){
		if(!GetString(mensaje, mensajeError, 1, 3, bufferChar)){
			if(EsCharValido(bufferChar[0]) == 1){
				*resultado=bufferChar[0];
				retorno = 0;
			}
			else {
				printf("\n%s \n", mensajeError);
			}
		}
    }
    return retorno;
}

int GetNombre(char* mensaje, char* mensajeError, int min, int max, char* resultado)
{
    int retorno = -1;
    char bufferStr[max];

    if(mensaje != NULL && mensajeError != NULL && min <= max && resultado!= NULL){
		if(!GetString(mensaje, mensajeError, min, max, bufferStr)) {
			if(EsNombreValido(bufferStr) == 1) {
				strncpy(resultado, bufferStr, max);
				retorno = 0;
			} else {
				printf("\n%s \n", mensajeError);
				setbuf(stdout, NULL);
			}
		}
    }
    return retorno;
}

int GetAlfanumerico(char* mensaje, char* mensajeError, int minSize, int maxSize, char* input){
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError != NULL && minSize < maxSize  && input != NULL){
          if(!GetString(mensaje, mensajeError, minSize, maxSize, bufferStr)){
                if(EsAlfanumericoValido(bufferStr) == 1){
                    strncpy(input, bufferStr, maxSize);
                    retorno = 0;
                } else {
                    printf("\n%s \n", mensajeError);
                }
          }
    }
    return retorno;
}

int GetMail(char* mensaje, char* mensajeError, int minSize, int maxSize, char* input){
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError != NULL && minSize < maxSize  && input != NULL){
          if(!GetString(mensaje, mensajeError, minSize, maxSize, bufferStr)){
                if(EsMailValido(bufferStr) == 1){
                    strncpy(input, bufferStr, maxSize);
                    retorno = 0;
                } else {
                    printf("\n%s \n", mensajeError);
                }
          }
    }
    return retorno;
}

//Transformar Inputs en Tipos con limite de reintentos
int GetIntReintentos(char* mensaje, char* mensajeError, int min, int max, int reintentos, int* input){
    int retorno = -1;
    int maxSize = 15;
    int minSize = 1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError!= NULL && minSize <= maxSize && min <= max && reintentos >= 0 && input != NULL){
        do {
            if(!GetStringReintentos(mensaje, mensajeError, minSize, maxSize, &reintentos, bufferStr)){
                if(EsNumeroValido(bufferStr) == 1) {
                    *input = atoi(bufferStr);
                    if(*input >= min && *input <= max){
						retorno = 0;
						break;
                    } else {
                    	printf("\n%s \n", mensajeError);
						setbuf(stdout, NULL);
						printf("\nQuedan %d reintentos\n", reintentos);
						setbuf(stdout, NULL);
						reintentos--;
                    }
                } else {
                    printf("\n%s \n", mensajeError);
                    setbuf(stdout, NULL);
                    printf("\nQuedan %d reintentos\n", reintentos);
                    setbuf(stdout, NULL);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }

    if(reintentos <= 0){
    	retorno = 0;
    }
    return retorno;
}

int GetFloatReintentos(char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos, float* input){
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError!= NULL && minSize < maxSize && min <= max && reintentos >= 0 && input != NULL) {
        do {
            if(!GetStringReintentos(mensaje, mensajeError, minSize, maxSize, &reintentos, bufferStr)){
                if(EsFloatValido(bufferStr) == 1){
                    *input = atof(bufferStr);
                    retorno = 0;
                    break;
                } else {
                    printf("\n%s \n", mensajeError);
                    printf("\nQuedan %d reintentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    if(reintentos == 0){
        retorno = 0;
    }

    return retorno;
}

int GetCharReintentos(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado){
    int retorno = -1;
    char bufferChar[256];

    if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >=0 && resultado != NULL){
        do {
            if(!GetStringReintentos(mensaje, mensajeError, 1, 3, &reintentos, bufferChar)){
                if(EsCharValido(bufferChar[0]) == 1){
                    printf("\nCaracter ingresado correctamente\n");
                    *resultado=bufferChar[0];
                    retorno = 0;
                    break;
                }
                else {
                    printf("\n%s \n", mensajeError);
                    printf("\nQuedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }

    if(reintentos == 0){
        retorno = 0;
    }
    return retorno;
}

int GetNombreReintentos(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[max];

    if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && resultado!= NULL){
        do {
            if(!GetStringReintentos(mensaje, mensajeError, min, max, &reintentos, bufferStr)) {
                if(EsNombreValido(bufferStr) ==1 ) {
                    strncpy(resultado, bufferStr, max);
                    retorno = 0;
                    break;
                } else {
                    printf("\n%s \n", mensajeError);
                    printf("\nQuedan %d reintentos restantes.\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }
    if(reintentos == 0){
        retorno = 0;
    }
    return retorno;
}

int GetAlfanumericoReintentos(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input){
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL){
    	do {
            if(!GetStringReintentos(mensaje, mensajeError, minSize, maxSize, &reintentos, bufferStr)){
                if(EsAlfanumericoValido(bufferStr) == 1){
                    strncpy(input, bufferStr, maxSize);
                    retorno = 0;
                    break;
                } else {
                    printf("\n%s \n", mensajeError);
                    printf("Quedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }
    if(reintentos <= 0){
        retorno = 0;
    }
    return retorno;
}

int GetMailReintentos(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, char* input){
    int retorno = -1;
    char bufferStr[maxSize];

    if(mensaje != NULL && mensajeError != NULL && minSize < maxSize && reintentos >= 0 && input != NULL){
    	do {
            if(!GetStringReintentos(mensaje, mensajeError, minSize, maxSize, &reintentos, bufferStr)){
                if(EsMailValido(bufferStr) == 1){
                    strncpy(input, bufferStr, maxSize);
                    retorno = 0;
                    break;
                } else {
                    printf("\n%s \n", mensajeError);
                    printf("Quedan %d intentos\n", reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos >= 0);
    }
    if(reintentos <= 0){
        retorno = 0;
    }
    return retorno;
}

//Validaciones
int EsNumeroValido(char* stringRecibido){
    int retorno = 1;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++){
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && stringRecibido[0] != '-'){
            retorno = 0;
            break;
        }
    }

    if(strlen(stringRecibido) > 20){
    	retorno = 0;
    }

    return retorno;
}

int EsFloatValido(char* stringRecibido)
{
    int retorno = 1;
    int i;

    for(i = 0; stringRecibido[i] != '\0'; i++){
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') && stringRecibido[i] != '.'){
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int EsGeneroValido(char charRecibido){
    int retorno = 1;

    if(charRecibido != 'f' && charRecibido !='m' && charRecibido != 'f' && charRecibido != 'm' && charRecibido != '0'){
        retorno = 0;
    }

    return retorno;
}

int EsCharValido(char charRecibido){
    int retorno = 1;

    if((charRecibido < 'A' || charRecibido>'Z') && (charRecibido < 'a' || charRecibido > 'z')){
        retorno = 0;
    }

    return retorno;
}

int EsNombreValido(char* stringRecibido)
{
    int retorno = 1;
    int i;
    for(i = 0; stringRecibido[i] != '\0'; i++)
    {
        if((stringRecibido[i] < 'A' || stringRecibido[i] > 'Z' ) && (stringRecibido[i] < 'a' || stringRecibido[i] > 'z'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int EsAlfanumericoValido(char* stringRecibido){
    int retorno = 1;
    int i;

    for(i = 0; stringRecibido[i] != '\0'; i++){
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') &&
           (stringRecibido[i] < 'A' || stringRecibido[i]>'Z') &&
		   (stringRecibido[i]<'a' || stringRecibido[i]>'z' )){
            retorno = 0;
            break;
        }
    }
    return retorno;
}


int EsMailValido(char* stringRecibido){
    int retorno = 1;
    int i;

    for(i = 0; stringRecibido[i] != '\0'; i++){
        if((stringRecibido[i] < '0' || stringRecibido[i] > '9') &&
           (stringRecibido[i] < 'A' || stringRecibido[i]>'Z') &&
           (stringRecibido[i]<'a' || stringRecibido[i]>'z' ) &&
            stringRecibido[i] != '@' && stringRecibido[i] != '.' &&
            stringRecibido[i] != '-' && stringRecibido[i] != '_'){
            retorno = 0;
            break;
        }
    }
    return retorno;
}
