lib_LTLIBRARIES = libsafejava.la
JAVA=$(JAVA_HOME)/include
libsafejava_la_SOURCES = safejava_wrap.cpp
libsafejava_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_LIBADD = ../libsafeqp/libsafeqp.la
