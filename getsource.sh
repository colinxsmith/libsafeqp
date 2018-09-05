#!/bin/bash
BASE=${1-"../safeqp"}
for file in `(cd $BASE;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp $BASE/$file  libsafeqp
done
cp $BASE/validate.h libsafeqp
cp $BASE/dsmxainv.c libsafeqp
mkdir m4 config
cd libsafeqp
rm constant.*
genconst -x > constant.cpp
genconst -h > constant.h
mkdir RPM/SOURCES
mkdir RPM/SOURCES/libsafeqp-1
#Investigate this
#find . -type f ! -regex '.*.hg.*' ! -regex '.*?debian-binary.*' ! -regex '.*?DEBIAN.*' -printf '%P ' | xargs md5sum > DEBIAN/md5sums