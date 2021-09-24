/*
 ============================================================================
 Name        : TP_1.c
 Author      : Leandro Valenzuela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* Enunciado
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "OPERACIONES_TP1.h"


int main(void)
{
	setbuf(stdout,NULL);

	int option=0;
	int subOption=0;
	float numeroUno;
	int flagNumeroUno=-1;
	float numeroDos;
	int flagNumeroDos=-1;

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int flagDivision=-1;
	float resultadoFactorialUno;
	float resultadoFactorialDos;
	int flagFactorialUno=-1;
	int flagFactorialDos=-1;
	int flagResultados=-1;


	do{
			//se imprime el menu
			ImprimirMenu(flagNumeroUno,flagNumeroDos, numeroUno, numeroDos);
			scanf("%d",&option);
			//evito que se ingrese una opci�n no v�lida
			while(option!=1&&option!=2&&option!=3&&option!=4&&option!=5)
			{
				fflush(stdin);
				ImprimirMenu(flagNumeroUno, flagNumeroDos, numeroUno, numeroDos);
				scanf("%d", &option);
			}
		//ingrese la opcion indicada
		switch(option)
		{
			case 1:
				//obtendre el valor de numero 1
				flagNumeroUno=getMyFloat(&numeroUno, "Ingrese el primer numero", "no es un valor v�lido");//Adquiero mi primer valor
				//doy la opcion de que se despliegue un submenu para ingresar el valor de numero 2 si no fue ingresado
				subOption=imprimirSubMenu(flagNumeroUno,flagNumeroDos);
				//en el caso de que elija la opcion 1 del submenu tomare el valor del segundo numero
				if(subOption==1)
				{
					flagNumeroDos=getMyFloat(&numeroDos, "Ingrese el segundo numero", "no es un valor v�lido");
				}
				break;
			case 2:
				//obtendre el valor de numero 2
				flagNumeroDos=getMyFloat(&numeroDos, "Ingrese el segundo numero", "no es un valor v�lido");
				//doy la opcion de que se despliegue un submenu para ingresar el valor de numero 1 si no fue ingresado
				subOption=imprimirSubMenu(flagNumeroDos, flagNumeroUno);
				//en el caso de que elija la opcion 1 del submenu tomare el valor del segundo numero
				if(subOption==1)
				{
					flagNumeroUno=getMyFloat(&numeroDos, "Ingrese el primer numero", "no es un valor v�lido");
				}
				break;
			case 3:
				//se realizan las operaciones solo si ingresaron los datos
				if(flagNumeroUno==0 && flagNumeroDos==0)
				{
					resultadoSuma=suma(numeroUno,numeroDos);
					resultadoResta=resta(numeroUno,numeroDos);
					resultadoMultiplicacion=multiplicacion(numeroUno,numeroDos);
					//devuelve si fue posible hacer la operaci�n
					flagDivision=division(numeroUno,numeroDos,&resultadoDivision);
					flagFactorialUno=factorial(numeroUno,&resultadoFactorialUno);
					flagFactorialDos=factorial(numeroDos,&resultadoFactorialDos);

					//marca que se realizaron todas las operaciones
					flagResultados=0;
					printf("\n Se realizaron las operaciones\n");
				}
				else
				{
					printf("\nFaltan ingresar datos\n");
				}
				break;
			case 4:
				//mostrara los resultados
				if(flagResultados==0)
				{
					printf("\nEl resultado de %.2f + %.2f es: %.2f\n",numeroUno,numeroDos,resultadoSuma);
					printf("\nEl resultado de %.2f - %.2f es: %.2f\n",numeroUno,numeroDos,resultadoResta);
					printf("\nEl resultado de %.2f * %.2f es: %.2f\n",numeroUno,numeroDos,resultadoMultiplicacion);

					//mensaje mostrado si es posible la operaci�n
					if(flagDivision==0)
					{
						printf("\nEl resultado de %.2f / %.2f es: %.2f\n",numeroUno,numeroDos,resultadoDivision);
					}
					else
					{
						printf("\nNo puede dividirse por 0\n");
					}
					if(flagFactorialUno==0)
					{
						printf("\nEl factorial de %.2f es: %.2f\n",numeroUno,resultadoFactorialUno);
					}
					else
					{
						printf("\nNo podemos calcular un negativo\n");
					}
					if(flagFactorialDos==0)
					{
						printf("\nEl factorial de %.2f es: %.2f\n",numeroDos,resultadoFactorialDos);
					}
					else
					{
						printf("\nNo podemos calcular un negativo\n");
					}
				}
				else
				{
					printf("\nFaltan ingresar datos o ingresar la opci�n 3.\n");
				}
				break;
			default:
				//termina el programa
				printf("\nTerminando programa\n");
				break;
		}

	}while(option!=5);


	return EXIT_SUCCESS;
}
