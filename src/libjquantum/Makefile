PACKAGE = libjquantum
VERSION = 1.0
BINDIR = ../../bin
INCLUDEDIR = -iquote./include -iquote../lib/include
SOURCES = jquantum.c
INCLUDES = ./include/jquantum.h 
CFLAGS = -g -O2 -Wall $(INCLUDEDIR)
LDFLAGS = -shared -fPIC -L$(BINDIR) -Wl,-soname,libjquantum.so,-rpath,/usr/local/lib

all: libjquantum

libjquantum: $(PACKAGE).$(VERSION).so

$(PACKAGE).$(VERSION).so: libquantum $(SOURCES) $(INCLUDES)

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES) -lm -lquantum
	cp $@ $(BINDIR)/$@
	cp $@ $(BINDIR)/$(PACKAGE).so

libquantum:
	
	make -C ../lib $@
	
clean:

	-rm $(PACKAGE).$(VERSION).so
	-rm $(BINDIR)/$(PACKAGE).$(VERSION).so
	-rm $(BINDIR)/$(PACKAGE).so
	
.PHONY: all clean libjquantum