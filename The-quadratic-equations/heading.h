#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include "functions.c"
#define There_are_no_roots 0
#define One_root 1
#define Two_roots 2
#define The_coefficients_are_zero 3

int cmp_with_zero(double val);
void Unit_Test_Square_equation();
double Discriminant_(double a, double b, double c);
void Print_function(double a, double b, double c);
double Square_equation( double a, double b, double c, double* x1, double* x2);
