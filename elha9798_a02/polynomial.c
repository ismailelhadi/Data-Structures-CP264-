/*
--------------------------------------------------
Project: cp264 assignment 2
Author:  ismail elhadi
Version: 24/01/2025
--------------------------------------------------
*/

#include <stdio.h>
#include <math.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

#define EPSILON 1e-6

float horner(float *p, int n, float x) {
	float result = p[0];
	for (int i = 1; i < n; i++) {
		result = result * x + p[i];
	}
	return result;

}

void derivative(float *p, float *d, int n)
{
	for (int i = 0; i < n-1; i++) {
		d[i] = (n-i-1) * p[i];
	}
}

// add auxilliary function float myfabs(floatx) to return the absolute value x
float myfabs(float x){
	if (x < 0){
		return -x;
	}
	return x;
}
float newton(float *p, int n, float x0)
{
	float d[n - 1];
	float x = x0;
	float sol, derSol;

	derivative(p, d, n);

	for (int i = 0; i < MAXCOUNT; i++) {
		x0 = x;

		sol = horner(p, n, x);
		derSol = horner(d, n - 1, x);

		if (myfabs(derSol) < EPSILON) {
			return x;
		}

		x = x0 - (sol / derSol);

		if (myfabs(x - x0) < EPSILON) {
			return x;
		}
	}

	return x;
}