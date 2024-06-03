lib_LTLIBRARIES = libsafejava.la
JAVA=/usr/lib/jvm/java-21-openjdk/include
libsafejava_la_SOURCES = safejava_wrap.cpp
libsafejava_la_CFLAGS = $(MY_DEF) -I/topper/safeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_CXXFLAGS = $(MY_DEF) -I/topper/safeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_LIBADD = ../libsafeqp/libsafeqp.la
