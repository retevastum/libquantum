# libquantum 1.1.1

Unofficial fork from the original libquantum from http://libquantum.de.

All credits to them.

This one has autotools removed, restructured directories; otherwise nothing changed as of yet.

See original stuff in _orig directory, including license, readme and stuff.

No install make target, just check out top level Makefile to see what's available and take the built
stuff from bin directory.

Replaced autoconf-templates with once configured results (for x86_64 on Ubuntu 16.04 LTS), so types.h, config.h and quantum.h are bound to the platform.