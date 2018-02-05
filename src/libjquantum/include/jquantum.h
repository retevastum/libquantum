/* quantum.h: Header file for libjquantum

   Copyright 2003-2013 Bjoern Butscher, Hendrik Weimer
   Copyright 2018 Jörg Jung

   This file is part of libjquantum, based on orig. header file for libquantum.

   libjquantum is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3 of the License,
   or (at your option) any later version.

   libjquantum is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with libquantum; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA

*/

#ifndef __JQUANTUM_H

#define __JQUANTUM_H

typedef struct {
    
    float real;
    float imag;
} komplex;

typedef struct {
    
    int rows;
    int cols;
    komplex *t;
} jquantum_matrix;

typedef long maxint;

typedef struct {
  
    int width;    /* number of qubits in the qureg */
    int size;     /* number of non-zero vectors */
    int hashw;    /* width of the hash array */
    komplex *amplitude;
    maxint *state;
    int *hash;
} jquantum_reg;

typedef struct {
  
    int num;          /* total number of state vectors */
    float *prob;      /* probabilities of the state vectors */
    jquantum_reg *reg; /* state vectors */
} quantum_density_op;

enum {
  QUANTUM_SOLVER_LANCZOS,
  QUANTUM_SOLVER_LANCZOS_MODIFIED,
  QUANTUM_SOLVER_IMAGINARY_TIME
};

extern void jquantum_new_qureg(jquantum_reg *jreg, maxint initval, int width);
extern void jquantum_print_qureg(jquantum_reg *jreg);

#endif
