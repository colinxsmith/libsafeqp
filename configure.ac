dnl Process this file with autoconf to produce a configure script.
AC_INIT(libsafeqp, 1.0)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(libsafeqp)
AC_CONFIG_SRCDIR(testsafeqp)
AC_CONFIG_SRCDIR(safeqp)
AC_CONFIG_SRCDIR(testU)
AC_CONFIG_SRCDIR(conic)
AC_CONFIG_SRCDIR(safejava)
AC_CONFIG_SRCDIR(safepython)
AC_CONFIG_SRCDIR(safeperl)
AC_CONFIG_SRCDIR(safecsharp)
AC_CONFIG_SRCDIR(controller)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_SED
LT_INIT
echo Host os is $host_os
if test $shrext_cmds = ".dll" ; then
    _LT_SET_OPTION([LT_INIT],[win32-dll])
    AC_SUBST([MY_DLL],[.dll])
    AC_SUBST([MY_no_undefined],[-no-undefined])
    AC_SUBST([MY_netapi32],[-lnetapi32])
    MY_DEF="-DALLWAYS"
else
    AC_SUBST([MY_DLL],[.so])
    AC_SUBST([MY_DEF],[-Dsomethinghereforlinux])
fi
echo shared lib endings $shrext_cmds
case $host_os in
  cygwin* | pw32* | cegcc*)
    MY_DEF+=" -DMSDOSS"
    ;;
esac
case $host_os in
  mingw*)
    MY_DEF+=" -DMINGW32 -D__SYSNT__ -D__SYSNT64__ -DMYNOVIRT -DBITADIRECT"
    MY_LDEF="-lwsock32 "
    AC_SUBST([MY_LDEF])
    ;;
esac
echo "#include <sys/types.h>  
ushort a=0; "> gnut.cpp
${CC-"gcc"} -c gnut.cpp
res=$?
rm -f gnut.*
if test "${res}" = 1 ; then
    echo No ushort
fi
echo "#include <sys/types.h>  
ulong a=0; " > gnut.cpp
${CC-"gcc"} -c gnut.cpp
res=$?
rm -f gnut.*
if test "${res}" = 1 ; then
    echo No ulong
fi
echo "auto foo=17;" > gnut.cpp
${CXX-"g++"} -c gnut.cpp
res=$?
rm -f gnut.*
if test "${res}" = 1 ; then
    echo My result for z
    echo "auto foo=17;" > gnut.cpp
    ${CXX-"g++"} -std=gnu++1z -c gnut.cpp
    res=$?
    rm -f gnut.*
    if test "${res}" = 0 ; then
        AC_SUBST([MY_STD],[-std=gnu++1z])
    fi
fi
if test "${res}" != 0 ; then
    echo My result for y
    echo "auto foo=17;" > gnut.cpp
    ${CXX-"g++"} -std=gnu++1y -c gnut.cpp
    res=$?
    rm -f gnut.*
    if test "${res}" = 0 ; then
        AC_SUBST([MY_STD],[-std=gnu++1y])
    else
        echo My result for x
        echo "auto foo=17;" > gnut.cpp
        ${CXX-"g++"} -std=c++0x -c gnut.cpp
        res=$?
        rm -f gnut.*
        if test "${res}" = 0 ; then
            AC_SUBST([MY_STD],[-std=c++0x])
        else
            AC_SUBST([MY_STD],[-DNOGPP])
            echo Cannot handle auto
        fi
    fi
fi
echo $MY_STD
echo $MY_DEF
AC_CONFIG_FILES(Makefile safejava/Makefile testsafeqp/Makefile safecsharp/Makefile safepython/Makefile safeperl/Makefile libsafeqp/Makefile controller/Makefile safeqp/Makefile testU/Makefile conic/Makefile)
AC_OUTPUT
