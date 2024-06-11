ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libsafeqp testsafeqp safeqp testU conic safejava controller
EXTRA_DIST = autogen.sh 
HERE=$$(pwd)
FINAL=$$(date +%Y\ %m\ %d | awk ' {a=$$1;b=$$2;c=$$3;if (b>10) a+=1;else if (b==10&&c>=13) a+=1;print 11"/"10"/"a}')
licence1:
	echo 'validas libsafeqp/.libs/libsafeqp.a `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
	if test x'$(MY_DLL)' = x'.so'; then \
		for file in libsafeqp/.libs/*safeqp*$(MY_DLL)*; do \
		if ! test -h $$file; then \
		echo $$file;lic=$$(future -b 13101D54 $$(date +%d/%m/%Y) $$NOW); echo $$lic; echo $(NOW); validas $$file $$lic 1023; \
		fi; \
		done; \
		for file in lib/*safeqp*$(MY_DLL)*; do \
		if ! test -h $$file; then \
		echo $$file;lic=$$(future -b 13101D54 $$(date +%d/%m/%Y) $$NOW); echo $$lic; echo $(NOW); validas $$file $$lic 1023; \
		fi; \
		done \
	else \
		for file in libsafeqp/.libs/*safeqp*$(MY_DLL); do \
		if ! test -h $$file; then \
		echo $$file;lic=$$(future -b 13101D54 $$(date +%d/%m/%Y) $$NOW); echo $$lic; echo $$NOW; validas $$file $$lic 1023; \
		fi; \
		done; \
		for file in lib/*safeqp*$(MY_DLL); do \
		if ! test -h $$file; then \
		echo $$file;lic=$$(future -b 13101D54 $$(date +%d/%m/%Y) $$NOW); echo $$lic; echo $$NOW; validas $$file $$lic 1023; \
		fi; \
		done \
	fi
licence:
	make licence1 NOW=$(FINAL)
testlib:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd testsafeqp/.libs;ldd pversion;./pversion) \
	else \
		(PATH=$$(pwd)/inst/bin:$$PATH;cd testsafeqp/.libs;ldd pversion;./pversion) \
	fi
testlibg:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/libsafeqp/.libs;cd testsafeqp/.libs;ldd pversion;./pversion) \
	else \
		(PATH=$$(pwd)/libsafeqp/.libs:$$PATH;cd testsafeqp/.libs;ldd pversion;./pversion) \
	fi
testlibr:
	(export LD_LIBRARY_PATH=$$(pwd)/RPM/SOURCES/libsafeqp-1;cd testsafeqp/.libs;ldd pversion;./pversion)
testlibD:
	(find . -type f ! -regex '.*?bin.*' ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum | sed -n "/ usr/p" > DEBIAN/md5sums)
	(export LD_LIBRARY_PATH=$$(pwd)/usr/local/lib/libsafeqp;cd testsafeqp/.libs;ldd pversion;./pversion)
dotdeb:
	rm -rf usr
	rm -rf ~/libsafeqp-d usr
	make install DESTDIR=$$(pwd)/usr/local 
	make testlibD
	ls usr/local/$(HERE)
	cp -rp usr/local/$(HERE)/lib usr/local/lib
	cp -rp usr/local/$(HERE)/bin usr/local/bin
#tar cf - usr/ | pax -r -s "|$(HERE)||"
	rm -rf usr/local/$(HERE)
	tree usr
	tar cf - DEBIAN/ usr/ | (mkdir ~/libsafeqp-d;chmod 755 ~/libsafeqp-d;cd ~/libsafeqp-d;tar xf -)
	sed -i "s|\$(HERE)||" ~/libsafeqp-d/DEBIAN/md5sums
	dpkg-deb --build ~/libsafeqp-d
rpm:
	rm -rf usr
	make install DESTDIR=$$(pwd)/usr/local
	ls usr/local/$(HERE)
	cp -rp usr/local/$(HERE)/lib usr/local/lib
	cp -rp usr/local/$(HERE)/bin usr/local/bin
#tar cf - usr/ | pax -r -s "|$(HERE)||"
	rm -rf usr/local/$(HERE)
	tree usr
	(cd usr/local/lib;tar cf - *) | (cd RPM/SOURCES/libsafeqp-1;tar xf -;cd ..;tar czf libsafeqp.tgz libsafeqp-1/*)
	make testlibr
	(cp -pr RPM/SOURCES ~/rpmbuild;rpmbuild -ba RPM/SPECS/libsafeqp.spec)
installrpm:
	make rpm
	sudo rpm -ivh ~/rpmbuild/RPMS/x86_64/libsafeqp-1-0.x86_64.rpm 
	(export LD_LIBRARY_PATH=/usr/local/lib/libsafeqp-1;cd testsafeqp/.libs;ldd pversion;./pversion)
	(export LD_LIBRARY_PATH=;cd testsafeqp/.libs;ldd pversion;./pversion)
testsafe:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd safeqp/.libs; ./safeqp $$(pwd)/../../data/costlog.log) \
	else \
		(PATH=$$(pwd)/inst/bin:$$PATH;cd safeqp/.libs; ./safeqp $$(pwd)/../../data/costlog.log) \
	fi
testlog:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd safeqp/.libs; ./logopt $$(pwd)/../../data/logopt.log) \
	else \
		(PATH=$$(pwd)/inst/bin:$$PATH;cd safeqp/.libs; ./logopt $$(pwd)/../../data/logopt.log) \
	fi
testETL:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd safeqp/.libs; ./ETL $$(pwd)/../../data/E1.log; ./ETL $$(pwd)/../../data/E2.log) \
	else \
		(PATH=$$(pwd)/inst/bin:$$PATH;cd safeqp/.libs; ./ETL $$(pwd)/../../data/E1.log; ./ETL $$(pwd)/../../data/E2.log) \
	fi
testUBS:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd testU/.libs; paskey colincolin1;./safeqpU $$(pwd)/../../data/PAS1.log) \
	else \
		(PATH=$$(pwd)/inst/bin:$$PATH;cd testU/.libs; paskey colincolin1;./safeqpU $$(pwd)/../../data/PAS1.log) \
	fi
testconic:
	if test x'$(MY_DLL)' = x'.so'; then \
		(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd conic/.libs; ./safeconic $$(pwd)/../../data/conic.log) \
	else \
		           (PATH=$$(pwd)/inst/bin:$$PATH;cd conic/.libs; ./safeconic $$(pwd)/../../data/conic.log) \
	fi
testsafejava:
	if test x'$(MY_DLL)' = x'.so'; then \
	  (export LD_LIBRARY_PATH=$$(pwd)/../libsafeqp/lib;cd safejava;cp $$(pwd)/../../safeqp/compat1.java .;javac *.java;java compat1) \
	else \
	  	            (PATH=$$(pwd)/../libsafeqp/lib;cd safejava;cp $$(pwd)/../../safeqp/compat1.java .;javac *.java;java compat1) \
	fi
testcontroller:
	if test x'$(MY_DLL)' = x'.so'; then \
	  (export LD_LIBRARY_PATH=$$(pwd)/../libsafeqp/lib;cd controller;javac logopt.java;java logopt $$(pwd)/../data/logopt.log) \
	else \
	                    (PATH=$$(pwd)/../libsafeqp/lib;cd controller;javac logopt.java;java logopt $$(pwd)/../data/logopt.log) \
	fi
