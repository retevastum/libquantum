PACKAGE = libquantum
VERSION = 1.1.1
BINDIR = ../../bin
INCLUDEDIR = -iquote./include
SOURCES = objcode.c classic.c complex.c decoherence.c density.c energy.c error.c expn.c gates.c lapack.c matrix.c measure.c oaddn.c omuln.c qec.c qft.c \
qtime.c qureg.c version.c 
INCLUDES = ./include/classic.h ./include/complex.h ./include/config.h ./include/decoherence.h ./include/defs.h ./include/density.h \
./include/energy.h ./include/error.h ./include/expn.h ./include/gates.h ./include/lapack.h ./include/matrix.h ./include/measure.h ./include/oaddn.h \
./include/objcode.h ./include/omuln.h ./include/qec.h ./include/qft.h ./include/qtime.h ./include/quantum.h ./include/qureg.h ./include/types.h ./include/version.h
CFLAGS = -g -O2 -Wall $(INCLUDEDIR)
LDFLAGS = -shared -fPIC -fopenmp -Wl,-soname,libquantum.so,-rpath,/usr/local/lib

all: libquantum

libquantum: $(PACKAGE).$(VERSION).so

$(PACKAGE).$(VERSION).so: $(SOURCES) $(INCLUDES)

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES) -lm
	cp $@ $(BINDIR)/$@
	
clean:

	rm $(PACKAGE).$(VERSION).so
	rm $(BINDIR)/$(PACKAGE).$(VERSION).so
	
.PHONY: all clean libquantum