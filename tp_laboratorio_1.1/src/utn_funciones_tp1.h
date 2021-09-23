/*
 * utn_funciones_tp1.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Leandro
 */

#ifndef UTN_FUNCIONES_TP1_H_
#define UTN_FUNCIONES_TP1_H_

char ImprimirMenu(int flagNumeroUno, int flagNumeroDos, float numUno, float numDos);
int getMyFloat(float* pNum,char *variableTexto, char *mensajeError);
float suma(float numUno,float numDos);
float resta(float numUno,float numDos);
float multiplicacion(float numUno,float numDos);
int division(float numUno,float numDos,float* pResultadoDivision);
int factorial(float num,float* pResultadoFactorial);


#endif /* UTN_FUNCIONES_TP1_H_ */
