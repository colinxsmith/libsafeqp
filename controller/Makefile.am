lib_LTLIBRARIES = libOptimiserController.la
JAVA=$(JAVA_HOME)/include
SWIG=~/SWIGcvs/SWIG/swig
libOptimiserController_la_SOURCES = OptimiserController_wrap.cpp
libOptimiserController_la_CFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libOptimiserController_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -I$(JAVA) -I$(JAVA)/linux
libOptimiserController_la_LDFLAGS = -L$(TOPPER)/libsafeqp/libsafeqp/.libs -lsafeqp -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
OptimiserController_wrap.cpp:
	sed "s/libraryname/OptimiserController/" ../../safeqp/safe.i > OptimiserController.i
	$(SWIG) -java -c++ -package com.bitaplus.BitaModel.Optimisation -module OptimiserController -o $@ OptimiserController.i 
	mkdir com && mkdir com/bitaplus && mkdir com/bitaplus/BitaModel && mkdir com/bitaplus/BitaModel/Optimisation
	mv Base_Optimise.java FOptimise.java Optimise.java OptimiserController.java OptimiserControllerJNI.java com/bitaplus/BitaModel/Optimisation
