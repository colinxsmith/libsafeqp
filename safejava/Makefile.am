lib_LTLIBRARIES = libsafejava.la
JAVA=$(JAVA_HOME)/include
libdir=$(TOPPER)/libsafejava/lib
libsafejava_la_SOURCES = safejava_wrap.cpp
libsafejava_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_LIBADD = ../libsafeqp/libsafeqp.la
libsafejava_la_LDFLAGS =  -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
