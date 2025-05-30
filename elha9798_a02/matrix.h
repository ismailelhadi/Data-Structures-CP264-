/*
--------------------------------------------------
Project: cp264 assignment 2
Author:  ismail elhadi
Version: 24/01/2025
--------------------------------------------------
*/
#ifndef MATRIX_H
#define MATRIX_H
 
float norm(float *v, int n);

float dot_product(float *v1, float *v2, int n);

void matrix_multiply_vector(float *m, float *v, float *vout, int n);

void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif