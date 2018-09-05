ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libsafeqp testsafeqp
EXTRA_DIST = autogen.sh 
FINAL=$$(date +%Y\ %m\ %d | awk ' {a=$$1;b=$$2;c=$$3;if (b>10) a+=1;else if (b==10&&c>=13) a+=1;print 11"/"10"/"a}')
licence1:
	echo 'validas libsafeqp/.libs/libsafeqp.a `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
	echo 'validas libsafeqp/.libs/*safeqp*$(MY_DLL) `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
licence:
	make licence1 NOW=$(FINAL)
testlib:
	(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd testsafeqp/.libs;ldd pversion;./pversion)
testlibg:
	(export LD_LIBRARY_PATH=$$(pwd)/libsafeqp/.libs;cd testsafeqp/.libs;ldd pversion;./pversion)
testlibr:
	(export LD_LIBRARY_PATH=$$(pwd)/RPM/SOURCES/libsafeqp-1;cd testsafeqp/.libs;ldd pversion;./pversion)
testlibD:
	(find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum | sed -n "/ usr/p" > DEBIAN/md5sums)
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
