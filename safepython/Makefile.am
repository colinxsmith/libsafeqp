lib_LTLIBRARIES = libsafe.la
VER=$$(ls /usr/include/ | grep py | sed "s/.*thon//")
SWIG=~/SWIGcvs/SWIG/swig
libsafe_la_SOURCES = safe_wrap.cpp
libsafe_la_CFLAGS = $(MY_DEF) -I../libsafeqp  -I/usr/include/python$(VER) -I/usr/include/python$(VER)/config
libsafe_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp  -I/usr/include/python$(VER) -I/usr/include/python$(VER)/config
libsafe_la_LDFLAGS = -L/usr/lib/python$(VER) ../libsafeqp/libsafeqp.la -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
safe_wrap.cpp:	Makefile.am
	cp ../../safeqp/safe.i safe.i
	$(SWIG) -python -c++ -module safe -o safe_wrap.cpp safe.i 
