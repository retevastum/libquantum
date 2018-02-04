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
#include <quantum.h>

/*
 * 
 */
int main(int argc, char** argv) {

    quantum_reg reg;
    reg = quantum_new_qureg(0,1);
    quantum_print_qureg(reg);
    return (EXIT_SUCCESS);
}

