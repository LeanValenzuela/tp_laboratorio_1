/*
 * OPERACIONES_TP1.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Leandro Valenzuela
 */

#ifndef OPERACIONES_TP1_H_
#define OPERACIONES_TP1_H_

void ImprimirMenu(int flagNumeroUno, int flagNumeroDos, float numUno, float numDos);
int getMyFloat(float* pNum,char *variableTexto, char *mensajeError);
int imprimirSubMenu(int flagNumeroUno,int flagNumeroDos);
float suma(float numUno,float numDos);
float resta(float numUno,float numDos);
float multiplicacion(float numUno,float numDos);
int division(float numUno,float numDos,float* pResultadoDivision);
int factorial(float num,float* pResultadoFactorial);


#endif /* OPERACIONES_TP1_H_ */
