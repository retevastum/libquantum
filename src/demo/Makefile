PACKAGE = libquantum
SUBPACKAGE = demo
VERSION = 1.1.1
INCLUDEDIR = -I../lib/include
BINDIR = ../../bin
CFLAGS = -g -O2 -Wall $(INCLUDEDIR)
LDFLAGS = -L$(BINDIR)

all: libquantum.demo

libquantum.demo: $(PACKAGE).$(SUBPACKAGE).$(VERSION)

$(PACKAGE).$(SUBPACKAGE).$(VERSION): $(PACKAGE).$(VERSION).so $(PACKAGE).$(SUBPACKAGE).$(VERSION).shor $(PACKAGE).$(SUBPACKAGE).$(VERSION).grover $(PACKAGE).$(SUBPACKAGE).$(VERSION).ising

$(PACKAGE).$(SUBPACKAGE).$(VERSION).shor: shor.c 

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $+ -lquantum -lm
	cp $@ $(BINDIR)/$@

$(PACKAGE).$(SUBPACKAGE).$(VERSION).grover: grover.c

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $+ -lquantum -lm
	cp $@ $(BINDIR)/$@

$(PACKAGE).$(SUBPACKAGE).$(VERSION).ising: ising.c

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $+ -lquantum -lm
	cp $@ $(BINDIR)/$@	
	
$(PACKAGE).$(VERSION).so:

	$(MAKE) -C ../lib $@
	
clean:

	-rm $(PACKAGE).$(SUBPACKAGE).$(VERSION).shor
	-rm $(PACKAGE).$(SUBPACKAGE).$(VERSION).grover
	-rm $(PACKAGE).$(SUBPACKAGE).$(VERSION).ising
	-rm $(BINDIR)/$(PACKAGE).$(SUBPACKAGE).$(VERSION).shor
	-rm $(BINDIR)/$(PACKAGE).$(SUBPACKAGE).$(VERSION).grover
	-rm $(BINDIR)/$(PACKAGE).$(SUBPACKAGE).$(VERSION).ising
	
.PHONY: all clean libquantum.quob $(PACKAGE).$(SUBPACKAGE).$(VERSION)