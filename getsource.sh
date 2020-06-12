#!/bin/bash
BASE=${1-"../safeqp"}
for file in `(cd $BASE;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp -p $BASE/$file  libsafeqp
done
cp -p $BASE/validate.h libsafeqp
cp -p $BASE/dsmxainv.c libsafeqp
mkdir m4 config
mkdir RPM/SOURCES
mkdir RPM/SOURCES/libsafeqp-1
cd libsafeqp
rm constant.* dlldatax.c
genconst -x > constant.cpp
genconst -h > constant.h
#Investigate this
#find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum > DEBIAN/md5sums
