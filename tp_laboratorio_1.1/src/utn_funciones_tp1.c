/*
 * utn_funciones_tp1.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn_funciones_tp1.h"

/**
 *\brief Mostrara el menu según los datos ingresados de numero 1 y 2
 *\param flagNumeroUno permitira saber si el usuario ha ingresado el valor del primer número para poder mostrarlo en el menú
 *\param flagNumeroDos permite saber si el usuario ha ingresado el valor del segundo número para poder mostrarlo en el menú.
 *\param numUno es el valor ingresado por el usuario en la opcion 1.
 *\param numDos es el valor ingresado por el usuario en la opcion 2.
 *\return Retornara el printf que segun los datos que haya o no ingresado el usuario hasta el momento para las opciones 1. y 2.
 */
char ImprimirMenu(int flagNumeroUno, int flagNumeroDos, float numUno, float numDos)
{
	char mensaje;
	if(flagNumeroUno!=0&&flagNumeroDos!=0)
	{
		mensaje=printf("Menu:\n\t 1.Para Ingresar el primer número \n\t 2.Para Ingresar el segundo número \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t"); /* prints menu */
	}
	else
	{
		if(flagNumeroUno==0&&flagNumeroDos!=0)
		{
			mensaje=printf("Menu:\n\t 1.Primer número: %.2f \n\t 2.Para Ingresar el segundo número \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numUno); /* prints menu */
		}
		else
		{
			if(flagNumeroUno!=0&&flagNumeroDos==0)
			{
				mensaje=printf("Menu:\n\t 1.Para Ingresar el primer número \n\t 2.Segundo número: %.2f \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numDos); /* prints menu */
			}
			else
			{
				mensaje=printf("Menu:\n\t 1.Primer número: %.2f \n\t 2.Segundo Numero: %.2f \n\t 3.Comenzar las operaciones \n\t 4.Mostrar resultados: \n\t 5.Salir del Programa.\n\t",numUno,numDos); /* prints menu */
			}
		}
	}
	return mensaje;
}

int getMyFloat(float* pNum,char *variableTexto, char *mensajeError)
{
	int salidaScanf=0;
	int estado=-1;

	if (pNum != NULL) //NULL(solo funciona con punteros para saber si estamos trayendo algo bien de la memoria)
	{
		printf("\n%s\n", variableTexto/*"Ingrese un numero: \n"*/);
		salidaScanf = scanf("%f", pNum); //(si scanf devuelve 1 es un texto por lo que sera invalido en caso de querer solo numeros)

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

float suma(float numUno,float numDos)
{
	int resultado;
	resultado=numUno+numDos;

	return resultado;
}
float resta(float numUno,float numDos)
{
	int resultado;
	resultado=numUno-numDos;

	return resultado;
}
float multiplicacion(float numUno,float numDos)
{
	int resultado;
	resultado=numUno*numDos;

	return resultado;
}
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
