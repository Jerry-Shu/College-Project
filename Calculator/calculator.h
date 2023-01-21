#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "../std_lib_facilities.h"
#include "Token_stream.h"

///This file does not need to be changed at all
///note the function headers below

double expression(); // deal with + and -
double primary();	// deal with numbers and parentheses
double term();	// deal with * and /
void calculate();

///Functions to implement

///returns n!
unsigned long long factorial(int n);

///Helper function to generate terms for sin
///returns (x^n) / (n!).  Use a for loop to avoid overflowing.
///ie return (x / 1) * (x / 2) * .... * (x / n)
double factExp(double x, int n);

///returns sin(x), using nTerms terms for the Taylor Series
///sin(x) = x - (x^3)/(3!) + (x^5)/(5!) - (x^7)/(7!) + ...
double sin(double x, int nTerms);

///returns sqrt(n), using nTerms terms for Newton's Method
double sqrt(double x, int nTerms);

///extern keyword means the variable will be declared / intialized in a different file
///will be covered in chapter 8
extern Token_stream ts;

#endif // CALCULATOR_H_INCLUDED
