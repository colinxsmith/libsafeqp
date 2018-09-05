ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libsafeqp
EXTRA_DIST = autogen.sh 
FINAL=$$(date +%Y\ %m\ %d | awk ' {a=$$1;b=$$2;c=$$3;if (b>10) a+=1;else if (b==10&&c>=13) a+=1;print 11"/"10"/"a}')
licence1:
	echo 'validas libsafeqp/.libs/libsafeqp.a `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
	echo 'validas libsafeqp/.libs/*safeqp*$(MY_DLL) `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
licence:
	make licence1 NOW=$(FINAL)
testlib:
	(export LD_LIBRARY_PATH=$$(pwd)/inst/lib;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibg:
	(export LD_LIBRARY_PATH=$$(pwd)/libsafeqp/.libs;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibr:
	(export LD_LIBRARY_PATH=$$(pwd)/RPM/SOURCES/libsafeqp-1;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibD:
	(find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum | sed -n "/ usr/p" > DEBIAN/md5sums)
	(export LD_LIBRARY_PATH=$$(pwd)/usr/local/lib/libsafeqp;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
dotdeb:
	rm -rf safeqp
	make install prefix=$$(pwd)/usr/local/lib/libsafeqp
	(cd usr/local/lib/libsafeqp/lib;tar cvf - *) | (cd usr/local/lib/libsafeqp;tar xvf -)#put libs in correct directory
	rm -rf usr/local/lib/libsafeqp/lib
	tar cvf - DEBIAN/ usr/ | (mkdir safeqp;cd safeqp;tar xvf -)
	make testlibD
	dpkg-deb --build safeqp
rpm:
	make install prefix=$$(pwd)/usr/local
	(cd usr/local/lib;tar cvf - *) | (cd RPM/SOURCES/libsafeqp-1;tar xvf -;cd ..;tar cvzf libsafeqp.tgz libsafeqp-1/*)
	make testlibr
	(cp -pr RPM/SOURCES $$(pwd)/rpmbuild;rpmbuild -ba RPM/SPECS/libsafeqp.spec)
installrpm:
	make rpm
	sudo rpm -ivh ~/rpmbuild/RPMS/x86_64/libsafeqp-1-0.x86_64.rpm 
	(export LD_LIBRARY_PATH=/usr/local/lib/libsafeqp-1;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
	(export LD_LIBRARY_PATH=;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
