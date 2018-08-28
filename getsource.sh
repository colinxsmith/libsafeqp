#!/bin/bash
for file in `(cd ../safeqp;make -f makelinux listsrc) | sed "/^for/d"`
do
    cp ../safeqp/$file  .
done