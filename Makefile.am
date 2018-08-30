ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libsafeqp
EXTRA_DIST = autogen.sh 
FINAL=$$(date +%Y\ %m\ %d | awk ' {a=$$1;b=$$2;c=$$3;if (b>10) a+=1;else if (b==10&&c>=13) a+=1;print 11"/"10"/"a}')
licence1:
	echo 'validas libsafeqp/.libs/libsafeqp.a `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
	echo 'validas libsafeqp/.libs/libsafeqp$(MY_DLL).0.0.0 `future -b 13101D54 \`date +%d/%m/%Y\` $(NOW)` 1023' | bash
licence:
	make licence1 NOW=$(FINAL)
