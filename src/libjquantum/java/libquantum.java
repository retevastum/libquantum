/*
 *
 *  *
 *  *
 *  *   * Copyright (c) 2018. Jörg Jung. Deutschland, Germany.
 *  *   * FREI.
 *  *
 *  * /
 *
 */

package de.datengraphie.data.quant;

import com.sun.jna.*;

import java.util.Arrays;
import java.util.List;

public class libquantum {

    private static _libquantum _i = Native.loadLibrary("quantum", _libquantum.class);
    private static _libquantum INSTANCE = (_libquantum) Native.loadLibrary("jquantum", _libquantum.class);
    private static _libquantum SYNC_INSTANCE = (_libquantum) Native.synchronizedLibrary(INSTANCE);

    public static class qReg extends _libquantum.jquantum_reg {

        public qReg() {

            super();
        }
    }

    private interface _libquantum extends Library {

        public static class unsignedLongLong extends NativeLong {

            public unsignedLongLong() {

                super(0, true);
            }

            public unsignedLongLong(long v) {

                super(v, true);
            }
        }

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
            public unsignedLongLong[] state = new unsignedLongLong[1];
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

        public void jquantum_new_qureg(jquantum_reg jreg, unsignedLongLong initval, int width);
        public void jquantum_print_qureg(jquantum_reg jreg);
    }

    public static void main(String[] args) {

        druckeQReg(neuesQReg(128, 8));
    }

    public static qReg neuesQReg(long v, int w) {

        qReg ret = new qReg();
        SYNC_INSTANCE.jquantum_new_qureg(ret, new _libquantum.unsignedLongLong(v), w);

        return ret;
    }

    public static void druckeQReg(qReg reg) {

        SYNC_INSTANCE.jquantum_print_qureg(reg);
    }
}

