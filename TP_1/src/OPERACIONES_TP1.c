/*
 * OPERACIONES_TP1.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Leandro Valenzuela
 */

#include <stdio.h>
#include <stdlib.h>
#include "OPERACIONES_TP1.h"

/**
 *\brief Retornar� el men� seg�n los datos que haya o no ingresado el usuario hasta el momento para las opciones 1. y 2.
 *\param flagNumeroUno permitira saber si el usuario ha ingresado el valor del primer n�mero para poder mostrarlo en el men�
 *\param flagNumeroDos permite saber si el usuario ha ingresado el valor del segundo n�mero para poder mostrarlo en el men�.
 *\param numUno es el valor ingresado por el usuario en la opcion 1.
 *\param numDos es el valor ingresado por el usuario en la opcion 2.
 */
void ImprimirMenu(int flagNumeroUno, int flagNumeroDos, float numUno, float numDos)
{
	if(flagNumeroUno!=0&&flagNumeroDos!=0)
	{
		printf("Menu:\n\t 1.Para Ingresar el primer n�mero \n\t 2.Para Ingresar el segundo n�mero \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t"); /* prints menu */
	}
	else
	{
		if(flagNumeroUno==0&&flagNumeroDos!=0)
		{
			printf("Menu:\n\t 1.Primer n�mero: %.2f \n\t 2.Para Ingresar el segundo n�mero \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numUno); /* prints menu */
		}
		else
		{
			if(flagNumeroUno!=0&&flagNumeroDos==0)
			{
				printf("Menu:\n\t 1.Para Ingresar el primer n�mero \n\t 2.Segundo n�mero: %.2f \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numDos); /* prints menu */
			}
			else
			{
				printf("Menu:\n\t 1.Primer n�mero: %.2f \n\t 2.Segundo Numero: %.2f \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numUno,numDos); /* prints menu */
			}
		}
	}
}

/*/*
 * brief Pedir� que ingrese un n�mero y validar� el n�mero ingresado
 * param *pNum es un puntero en el cual se guardar� el valor del n�mero pedido
 * param variableTexto traer� el texto insertado en la variable del main
 * param mensajeError traer� el texto de error insertado en la variable de la function main
 * return retornar� el estado, que sea v�lido el valor ingresado
 */
int getMyFloat(float* pNum,char *variableTexto, char *mensajeError)
{
	int salidaScanf=0;
	int estado=-1;

	if (pNum != NULL) //NULL(solo funciona con punteros para saber si estamos trayendo algo bien de la memoria)
	{
		printf("\n%s\n", variableTexto);
		salidaScanf = scanf("%f", pNum);

		while (salidaScanf != 1)
		{
			printf("\n%s\n", mensajeError);
			fflush(stdin);
			salidaScanf = scanf("%f", pNum);
		}
		estado=0;
	 }
	return estado;
}

/*/*brief me imprimir� un submen� en caso de que haya ingresado el primer valor pero no el segundo
 * param flagNumeroUno controla que se haya ingresado bien el primer valor cambiando de estado la bandera
 * param flagNumeroDos controlar� si ingres� el segundo valor, en caso negativo lo invitara a ingresarlo
 */
int imprimirSubMenu(int flagNumeroUno,int flagNumeroDos)
{
	int subOption=-1;
	if(flagNumeroUno==0&&flagNumeroDos==-1)
	{
		printf("\nDesea ingresar el segundo numero?\n 1-Si\n 2-No\n");
		scanf("%d",&subOption);
		while(subOption!=1&&subOption!=2)
		{
			fflush(stdin);
			printf("\nComando Inv�lido.\nDesea ingresar el segundo numero?\n 1-Si\n 2-No\n");
			scanf("%d",&subOption);
		}
	}
	return subOption;
}

/*/*
 * brief realiza y retornar� el resultado de la operaci�n de sumar
 * param numUno toma el valor del primer n�mero ingresado
 * param numDos toma el valor del segundo n�mero ingresado
 * param resultado guarda el resultado de la operaci�n
 */
float suma(float numUno,float numDos)
{
	int resultado;
	resultado=numUno+numDos;

	return resultado;
}

/*/*
 * brief realiza y retornar� el resultado de la operaci�n de restar
 * param numUno toma el valor del primer n�mero ingresado
 * param numDos toma el valor del segundo n�mero ingresado
 * param resultado guarda el resultado de la operaci�n
 */
float resta(float numUno,float numDos)
{
	int resultado;
	resultado=numUno-numDos;

	return resultado;
}

/*/*
 * brief realizar� la operaci�n de multiplicar y devuleve su resultado
 * param numUno toma el valor del primer n�mero ingresado
 * param numDos toma el valor del segundo n�mero ingresado
 * param resultado guarda el resultado de la operaci�n
 * return retornar� el resultado de la operaci�n
 */
float multiplicacion(float numUno,float numDos)
{
	int resultado;
	resultado=numUno*numDos;

	return resultado;
}

/*/*
 * brief Se analiza si es posible o no realizar la operaci�n de dividir y en caso positivo se guarda el resultado
 * param numUno toma el valor del primer n�mero ingresado
 * param numDos toma el valor del segundo n�mero ingresado
 * param *pResultadoDivision guarda el resultado de la operaci�n
 * param estado guardar� el valor si es posible la operaci�n
 * return devolver� 0 si es posible la operaci�n o un -1 si no lo es
 */
int division(float numUno,float numDos,float* pResultadoDivision)
{
	int estado;

	if(numDos!=0)
	{
		*pResultadoDivision = numUno/numDos;
		estado=0;
	}
	else
	{
		estado=-1;
	}
	return estado;
}

/*/*
 * brief Se analiza si es posible o no realizar la operaci�n de factorial y en caso positivo se guarda el resultado
 * param numUno toma el valor del primer n�mero ingresado
 * param numDos toma el valor del segundo n�mero ingresado
 * param *pResultadoFactorail guarda el resultado de la operaci�n
 * param estado guardar� el valor si es posible la operaci�n
 * return devolver� 0 si es posible la operaci�n o un -1 si no lo es
 */
int factorial(float num,float* pResultadoFactorial)
{
	int estado;
	float auxiliar=1;

	if(num>0)
	{
		for(float i=num;i>1;i--)
		{
			auxiliar=auxiliar*i;
		}
			*pResultadoFactorial=auxiliar;
			estado=0;
	}
	else
	{
		if(num==0)
		{
			*pResultadoFactorial=1;
			estado=0;
		}
		else
		{
			estado=-1;
		}
	}
	return estado;
}
