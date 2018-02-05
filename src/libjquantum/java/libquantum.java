/*
 *
 *  *
 *  *
 *  *   * Copyright (c) 2018. Jörg Jung. Deutschland, Germany.
 *  *   * Alle Rechte vorbehalten.
 *  *
 *  * /
 *
 */

package de.datengraphie.data.quant;

import com.sun.jna.*;

import java.util.Arrays;
import java.util.List;

public class libquantum {

    private interface _libquantum extends Library {

        _libquantum i = Native.loadLibrary("quantum", _libquantum.class);
        _libquantum INSTANCE = (_libquantum) Native.loadLibrary("jquantum", _libquantum.class);

        public static class komplex extends Structure {

            public float real;
            public float imag;

            protected List getFieldOrder() {

                return Arrays.asList(new String[] {"real", "imag"});
            }
        }

        public static class jquantum_matrix extends Structure {

            public int rows;
            public int cols;
            public komplex[] t = new komplex[1];

            protected List getFieldOrder() {

                return Arrays.asList(new String[] {"rows", "cols", "t"});
            }
        }

        public static class jquantum_reg extends Structure {

            public int width;
            public int size;
            public int hashw;
            public komplex[] amplitude = new komplex[1];
            public NativeLong[] state = new NativeLong[1];
            public int[] hash = new int[1];

            protected List getFieldOrder() {

                return Arrays.asList(new String[] {"width", "size", "hashw", "amplitude", "state", "hash"});
            }
        }

        public static class quantum_density_op extends Structure {

            public int num;
            public float[] prob = new float[1];
            public jquantum_reg[] jreg = new jquantum_reg[1];

            protected List getFieldOrder() {

                return Arrays.asList(new String[] {"num", "prob", "reg"});
            }
        }

        public void jquantum_new_qureg(jquantum_reg jreg, long initval, int width);
        public void jquantum_print_qureg(jquantum_reg jreg);
    }

    public static void main(String[] args) {

        _libquantum libq = _libquantum.INSTANCE;
        _libquantum.jquantum_reg jreg = new _libquantum.jquantum_reg();
        _libquantum.jquantum_reg jreg2 = new _libquantum.jquantum_reg();
        libq.jquantum_new_qureg(jreg , 0, 1);
        libq.jquantum_new_qureg(jreg2 , 12, 8);
        libq.jquantum_print_qureg(jreg);
        libq.jquantum_print_qureg(jreg2);
        //libq.quantum_print_qureg(reg);

    }
}

