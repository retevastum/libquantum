/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jj
 *
 * Created on 4. Februar 2018, 15:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quantum.h"
#include "jquantum.h"


void f (jquantum_reg *jreg)
{
  int constant = 1;
  if(!constant)
    jquantum_cnot(0, 2, jreg);
}

int main ()
{
  jquantum_reg jreg;
  jreg.amplitude = 0;
  jreg.hash = 0;
  jreg.state = 0;
  srand(time(0));
  jquantum_new_qureg(&jreg, 5, 3);
  jquantum_hadamard(0, &jreg);
  jquantum_hadamard(1, &jreg);
  jquantum_hadamard(2, &jreg);
  f(&jreg);
  jquantum_hadamard(0, &jreg);
  jquantum_hadamard(1, &jreg);
  jquantum_print_qureg(&jreg);
  printf("Ergebnis: %i\n", jquantum_bmeasure(0, &jreg));
  jquantum_print_qureg(&jreg);
  return 0;
}

