/*
--------------------------------------------------
Project: cp264 assignment 2
Author:  ismail elhadi
Version: 24/01/2025
--------------------------------------------------
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
float horner(float *p, int n, float x);

void derivative(float *p, float *d, int n);

float newton(float *p, int n, float x0);

#endif