#!/bin/bash
BASE=../safeqp
for file in `(cd $BASE;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp $BASE/$file  libsafeqp
done
cp $BASE/validate.h libsafeqp
cp $BASE/dsmxainv.c libsafeqp
cd libsafeqp
rm constant.*
mkdir m4 config
genconst -x > constant.cpp
genconst -h > constant.h
