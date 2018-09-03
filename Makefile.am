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
	(export LD_LIBRARY_PATH=~/libsafeqp/inst/lib:~/safeqp;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibg:
	(export LD_LIBRARY_PATH=~/libsafeqp/libsafeqp/.libs:~/safeqp;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibr:
	(export LD_LIBRARY_PATH=~/libsafeqp/RPM/SOURCES/libsafeqp-1:~/safeqp;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
testlibD:
	(find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum | sed -n "/ usr/p" > DEBIAN/md5sums)
	(export LD_LIBRARY_PATH=~/libsafeqp/usr/local/lib:~/safeqp;cd ~/safeqp;ldd _safe.so;python -c "from safe import *; print version()")
dotdeb:
	rm -rf safeqp
	make install prefix=$$(pwd)/usr/local
	tar cvf - DEBIAN/ usr/ | (mkdir safeqp;cd safeqp;tar xvf -)
	make testlibD
	dpkg-deb --build safeqp
rpm:
	make install prefix=$$(pwd)/usr/local
	(cd usr/local/lib;tar cvf - *) | (cd RPM/SOURCES/libsafeqp-1;tar xvf -;cd ..;tar cvzf libsafeqp.tgz libsafeqp-1/*;cp -p libsafeqp.tgz ~/rpmbuild/SOURCES)
	make testlibr
	(cd RPM;rpmbuild -ba SPECS/libsafeqp.spec)
#	rpm -ivh libsafeqp-1-0.noarch.rpm # install step