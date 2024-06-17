INTERFACE=safecsharp
lib_LTLIBRARIES = libsafecsharp.la
SWIG=~/SWIGcvs/SWIG/swig
libsafecsharp_la_SOURCES = safecsharp_wrap.cpp
libsafecsharp_la_CFLAGS = $(MY_DEF) -I../libsafeqp
libsafecsharp_la_CXXFLAGS = $(MY_DEF) -I../libsafeqp -std=gnu++11
libsafecsharp_la_LDFLAGS = ../libsafeqp/libsafeqp.la -lgomp -version-info 1:0:0 $(MY_no_undefined) $(MY_netapi32) $(MY_LDEF)
safecsharp_wrap.cpp:	Makefile.am
	cp ../../safeqp/safe.i safecsharp.i
	cp ../../safeqp/compat.cs .
	sed -i "s?//%?%?" safecsharp.i
	sed -i "s?//\#?\#?" safecsharp.i
	$(SWIG) -csharp -c++ -module safecsharp -o $@ safecsharp.i
	sed -i "1iusing System;\nusing System.Runtime.InteropServices;" $(INTERFACE)PINVOKE.cs
	sed -i "1iusing System;\nusing System.Runtime.InteropServices;" $(INTERFACE).cs
	mcs -out:compat.exe compat.cs $(INTERFACE).cs $(INTERFACE)PINVOKE.cs
	mcs -out:OptDotNet.dll -t:library $(INTERFACE).cs $(INTERFACE)PINVOKE.cs
