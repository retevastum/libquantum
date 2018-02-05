all: libquantum libjquantum libquantum.demo libquantum.quob

libquantum:

	$(MAKE) -C lib $@

libjquantum:

	$(MAKE) -C libjquantum $@

libquantum.demo:

	$(MAKE) -C demo $@
	
libquantum.quob:

	$(MAKE) -C quob $@

clean:

	$(MAKE) -C lib $@
	$(MAKE) -C libjquantum $@
	$(MAKE) -C demo $@
	$(MAKE) -C quob $@