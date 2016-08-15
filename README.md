CIRC
====

This IRC C library depends on the cutil library (https://github.com/dhuseby/cutil) and optionally it depends on the CUnit library if you wish to run the unit tests.

The Makefile is sensitive to the PREFIX environment variable.  If you set it and then run "make install" it will build the static library and copy it to $(PREFIX)/lib.  If you do not specify a value for PREFIX, then it defaults to /usr/local.

The Makefile is also sensitive to CUTIL_ROOT which should be the path to where  the cunit library is installed (e.g. /usr/local).
