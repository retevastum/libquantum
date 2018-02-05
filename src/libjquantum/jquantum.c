/* jquantum.c: Wrapper so JNA works

   Copyright 2018 Jörg Jung

   This file is part of libjquantum

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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "jquantum.h"
#include "qureg.h"

void jquantum_convertqjq(jquantum_reg *jreg, quantum_reg *reg);
void jquantum_convertjqq(jquantum_reg *jreg, quantum_reg *reg);

void jquantum_new_qureg(jquantum_reg *jreg, maxint initval, int width) {
    
    quantum_reg reg = quantum_new_qureg(initval, width);
    
    jquantum_convertqjq(jreg, &reg);
}

void jquantum_print_qureg(jquantum_reg *jreg) {
    
    quantum_reg reg = quantum_new_qureg(0, 1);
    
    jquantum_convertjqq(jreg, &reg);
    quantum_print_qureg(reg);
}

void jquantum_convertqjq(jquantum_reg *jreg, quantum_reg *reg) {
    
    jreg->width = reg->width;
    jreg->size = reg->size;
    jreg->hashw = reg->hashw;
    
    //free(jreg->hash);
    jreg->hash = calloc(jreg->size, sizeof(int));
    
    //free(jreg->state);
    jreg->state = calloc(jreg->size, sizeof(maxint));
    for (int i = 0; i < jreg->size; i++) {
        
        jreg->state[i] = reg->state[i];
    }
    
    //free(jreg->amplitude);
    jreg->amplitude = calloc(jreg->size, sizeof(komplex));
    for (int i = 0; i < jreg->size; i++) {
        
        jreg->amplitude[i].real = creal(reg->amplitude[i]);
        jreg->amplitude[i].imag = cimag(reg->amplitude[i]);
    }
}

void jquantum_convertjqq(jquantum_reg *jreg, quantum_reg *reg) {
  
    reg->width = jreg->width;
    reg->size = jreg->size;
    reg->hashw = jreg->hashw;
    
    //free(reg->hash);
    reg->hash = calloc(reg->size, sizeof(int));
    
    //free(reg->state);
    reg->state = calloc(reg->size, sizeof(maxint));
    for (int i = 0; i < reg->size; i++) {
        
        reg->state[i] = jreg->state[i];
    }
    
    //free(reg->amplitude);
    reg->amplitude = calloc(reg->size, sizeof(komplex));
    for (int i = 0; i < reg->size; i++) {
        
        reg->amplitude[i] = CMPLX(jreg->amplitude[i].real, jreg->amplitude[i].imag);
    }
}


