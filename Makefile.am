ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libsafeqp testsafeqp safeqp testU conic
EXTRA_DIST = autogen.sh 
FINAL=$$(date +%Y\ %m\ %d | awk ' {a=$$1;b=$$2;c=$$3;if (b>10) a+=1;else if (b==10&&c>=13) a+=1;print 11"/"10"/"a}')
licence1:
	echo 'validas libsafeqp/.libs/libsafeqp.a `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
	if test x'$(MY_DLL)' = x'.so'; then \
	for file in libsafeqp/.libs/*safeqp*$(MY_DLL)*; do \
	if ! test -h $$file; then \
	echo $$file;lic=$$(future -b 13101D54 $$(date +%d/%m/%Y) $$NOW); echo $$lic; echo $(NOW); validas $$file $$lic 1023; \
	fi; \
	done \
	else \
	for file in libsafeqp/.libs/*safeqp*$(MY_DLL); do \
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
	rm -rf libsafeqp-d usr
	make install prefix=$$(pwd)/usr/local/lib/libsafeqp
	make testlibD
	(cd usr/local/lib/libsafeqp/lib;tar cf - *) | (cd usr/local/lib/libsafeqp;tar xf -)#put libs in correct directory
	rm -rf usr/local/lib/libsafeqp/lib
	rm -rf usr/local/lib/libsafeqp/bin
	tar cf - DEBIAN/ usr/ | (mkdir libsafeqp-d;cd libsafeqp-d;tar xf -)
	dpkg-deb --build libsafeqp-d
rpm:
	make install prefix=$$(pwd)/usr/local
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
