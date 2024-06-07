lib_LTLIBRARIES = libsafejava.la libOptimiserController.la
JAVA=$(JAVA_HOME)/include
SWIG=~/SWIGcvs/SWIG/swig
libsafejava_la_SOURCES = safejava_wrap.cpp
libsafejava_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libsafejava_la_LDFLAGS = -L$(TOPPER)/libsafeqp/libsafeqp/.libs -lsafeqp -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
libOptimiserController_la_SOURCES = OptimiserController_wrap.cpp
libOptimiserController_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libOptimiserController_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libOptimiserController_la_LDFLAGS = -L$(TOPPER)/libsafeqp/libsafeqp/.libs -lsafeqp -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
safejava_wrap.cpp:
	sed "s/libraryname/safejava/" ../../safeqp/safe.i > safejava.i
	$(SWIG) -java -c++ -module safejava -o safejava_wrap.cpp safejava.i 
OptimiserController_wrap.cpp:
	sed "s/libraryname/OptimiserController/" ../../safeqp/safe.i > OptimiserController.i
	$(SWIG) -java -c++ -package com.bitaplus.BitaModel.Optimisation -module OptimiserController -o OptimiserController_wrap.cpp OptimiserController.i 
