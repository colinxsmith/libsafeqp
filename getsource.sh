#!/bin/bash
for file in `(cd ../safeqp;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp ../safeqp/$file  libsafeqp
done
cp ../safeqp/validate.h libsafeqp
cd libsafeqp
rm constant.*
genconst -x > constant.cpp
genconst -h > constant.h
