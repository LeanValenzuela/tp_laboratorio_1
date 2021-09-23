/*
 ============================================================================
 Name        : 1.c
 Author      : Leandro Valenzuela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir */

#include <stdio.h>
#include <stdlib.h>

#include "utn_funciones_tp1.h"


int main(void)
{
	setbuf(stdout,NULL);

	char menu;
	int opcion=0;
	int subOpcion=0;
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
			menu=ImprimirMenu(flagNumeroUno,flagNumeroDos, numeroUno, numeroDos);
			scanf("%d",&opcion);
			while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5)
			{
				fflush(stdin);
				menu=ImprimirMenu(flagNumeroUno, flagNumeroDos, menu, numeroDos);
				scanf("%d", &opcion);
			}

		switch(opcion)
		{
			case 1:
				flagNumeroUno=getMyFloat(&numeroUno, "Ingrese el primer numero", "no es un valor válido");
				if(flagNumeroUno==0&&flagNumeroDos==-1)
				{
					printf("\nDesea ingresar el segundo numero?\n 1-Si\n 2-No\n");
					scanf("%d",&subOpcion);
					while(subOpcion!=1&&subOpcion!=2)
					{
						fflush(stdin);
						printf("\nComando Inválido.\nDesea ingresar el segundo numero?\n 1-Si\n 2-No\n");
						scanf("%d",&subOpcion);
					}
					if(subOpcion==1)
					{
						flagNumeroDos=getMyFloat(&numeroDos, "Ingrese el segundo numero", "no es un valor válido");
					}
				}
				break;
			case 2:
				flagNumeroDos=getMyFloat(&numeroDos, "Ingrese el segundo numero", "no es un valor válido");
				if(flagNumeroDos==0&&flagNumeroUno==-1)
				{
					printf("\nDesea ingresar el segundo numero?\n 1-Si\n 2-No\n");
					scanf("%d",&subOpcion);
					while(subOpcion!=1&&subOpcion!=2)
					{
						fflush(stdin);
						printf("\nComando Inválido.\nDesea ingresar el primer numero?\n 1-Si\n 2-No \n");
						scanf("%d",&subOpcion);
					}
					if(subOpcion==1)
					{
						flagNumeroUno=getMyFloat(&numeroDos, "Ingrese el primer numero", "no es un valor válido");
					}
				}
				break;
			case 3:
				if(flagNumeroUno==0 && flagNumeroDos==0)
				{
					resultadoSuma=suma(numeroUno,numeroDos);
					resultadoResta=resta(numeroUno,numeroDos);
					resultadoMultiplicacion=multiplicacion(numeroUno,numeroDos);
					flagDivision=division(numeroUno,numeroDos,&resultadoDivision);
					flagFactorialUno=factorial(numeroUno,&resultadoFactorialUno);
					flagFactorialDos=factorial(numeroDos,&resultadoFactorialDos);

					flagResultados=0;
					printf("\n Se realizaron las operaciones\n");
				}
				else
				{
					printf("\nFaltan ingresar datos\n");
				}
				break;
			case 4:
				if(flagResultados==0)
				{
					printf("\nEl resultado de %.2f + %.2f es: %.2f\n",numeroUno,numeroDos,resultadoSuma);
					printf("\nEl resultado de %.2f - %.2f es: %.2f\n",numeroUno,numeroDos,resultadoResta);
					printf("\nEl resultado de %.2f * %.2f es: %.2f\n",numeroUno,numeroDos,resultadoMultiplicacion);
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
					printf("\nFaltan ingresar datos\n");
				}
				break;
			default:
				printf("\nTerminando programa\n");
				break;
		}

	}while(opcion!=5);


	return EXIT_SUCCESS;
}

