lib_LTLIBRARIES = libsafejava.la
JAVA=$$(find /usr -name jni.h -print | sed "s|/include.*||")/include
SWIG=~/SWIGcvs/SWIG/swig
libsafejava_la_SOURCES = safejava_wrap.cpp
libsafejava_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_LDFLAGS = ../libsafeqp/libsafeqp.la  -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
safejava_wrap.cpp:	Makefile.am
	sed "s/libraryname/safejava/" ../../safeqp/safe.i > safejava.i
	$(SWIG) -java -c++ -module safejava -o safejava_wrap.cpp safejava.i 
