PACKAGE = libquantum
SUBPACKAGE = quob
VERSION = 1.1.1
INCLUDEDIR = -iquote../lib/include
BINDIR = ../../bin
CFLAGS = -g -O2 -Wall $(INCLUDEDIR)
LDFLAGS = -L$(BINDIR)

all: libquantum.quob

libquantum.quob: $(PACKAGE).$(SUBPACKAGE).$(VERSION)

$(PACKAGE).$(SUBPACKAGE).$(VERSION): $(PACKAGE).$(VERSION).so $(PACKAGE).$(SUBPACKAGE).$(VERSION).print $(PACKAGE).$(SUBPACKAGE).$(VERSION).dump

$(PACKAGE).$(SUBPACKAGE).$(VERSION).dump: quobdump.c

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $+ -lquantum -lm
	cp $@ $(BINDIR)/$@

$(PACKAGE).$(SUBPACKAGE).$(VERSION).print: quobprint.c $(INCLUDES)

	gcc $(CFLAGS) $(LDFLAGS) -o $@ $+ -lquantum -lm
	cp $@ $(BINDIR)/$@
	
$(PACKAGE).$(VERSION).so:

	$(MAKE) -C ../lib $@
	
clean:

	-rm $(PACKAGE).$(SUBPACKAGE).$(VERSION).print
	-rm $(PACKAGE).$(SUBPACKAGE).$(VERSION).dump
	-rm $(BINDIR)/$(PACKAGE).$(SUBPACKAGE).$(VERSION).print
	-rm $(BINDIR)/$(PACKAGE).$(SUBPACKAGE).$(VERSION).dump
	
.PHONY: all clean libquantum.quob $(PACKAGE).$(SUBPACKAGE).$(VERSION)