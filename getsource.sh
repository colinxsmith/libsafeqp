#!/bin/bash
for file in `(cd ../safeqp;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp ../safeqp/$file  libsafeqp
done
cp ../safeqp/validate.h libsafeqp
cp ../dsmxainv.c libsafeqp
cd libsafeqp
rm constant.*
mkdir m4 config
genconst -x > constant.cpp
genconst -h > constant.h
