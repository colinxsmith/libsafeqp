lib_LTLIBRARIES = libsafepl.la
INCLUDE=$$(find /usr/lib -name perl.h -print|sed "s|/perl.h||")
SWIG=~/SWIGcvs/SWIG/swig
libsafepl_la_SOURCES = safepl_wrap.cpp
libsafepl_la_CFLAGS = $(MY_DEF) -I../libsafeqp  -I$(INCLUDE)
libsafepl_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(INCLUDE)
libsafepl_la_LDFLAGS = -L$(TOPPER)/libsafqp/libsafeqp/.libs -lsafeqp -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
safepl_wrap.cpp:	Makefile.am
	cp ../../safeqp/safe.i safepl.i
	$(SWIG) -perl5 -c++ -module safepl -o $@ safepl.i 
	sed -i "s?\#undef ENTER?//\#undef ENTER?" $@
	sed -i "/== SWIG_NEWOBJ.*delete/d" $@
