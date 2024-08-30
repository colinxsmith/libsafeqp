lib_LTLIBRARIES = libBITAOPT.la
VER=$$(ls /usr/include/ | sed -n "s/python//p" | sed "/d/d")
SWIG=~/SWIGcvs/SWIG/swig
libBITAOPT_la_SOURCES = BITAOPT_wrap.cpp
libBITAOPT_la_CFLAGS = $(MY_DEF) -I../libsafeqp  -I/usr/include/python$(VER) -I/usr/include/python$(VER)/config
libBITAOPT_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp  -I/usr/include/python$(VER) -I/usr/include/python$(VER)/config
libBITAOPT_la_LDFLAGS = -L/usr/lib/python$(VER) ../libsafeqp/libsafeqp.la -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
BITAOPT_wrap.cpp:	Makefile.am
	cp ../../safeqp/BITAOPT.i BITAOPT.i
	$(SWIG) -python -c++ -module BITAOPT -o BITAOPT_wrap.cpp BITAOPT.i 
