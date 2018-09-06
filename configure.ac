dnl Process this file with autoconf to produce a configure script.
AC_INIT(libsafeqp, 1.0)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(libsafeqp)
AC_CONFIG_SRCDIR(testsafeqp)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_SED
LT_INIT
echo Host os is $host_os
if test $shrext_cmds = ".dll" ; then
    AC_LIBTOOL_WIN32_DLL
    AC_SUBST(MY_DLL,.dll)
    AC_SUBST(MY_no_undefined,-no-undefined)
    AC_SUBST(MY_netapi32,-lnetapi32)
else
    AC_SUBST(MY_DLL,.so)
fi
echo shared lib endings $shrext_cmds
case $host_os in
  cygwin* | mingw* | pw32* | cegcc*)
    AC_SUBST(MY_DEF,-DMSDOSS)
    ;;
esac
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
        AC_SUBST(MY_STD,-std=gnu++1z)
    fi
fi
if test "${res}" != 0 ; then
    echo My result for y
    echo "auto foo=17;" > gnut.cpp
    ${CXX-"g++"} -std=gnu++1y -c gnut.cpp
    res=$?
    rm -f gnut.*
    if test "${res}" = 0 ; then
        AC_SUBST(MY_STD,-std=gnu++1y)
    else
        echo My result for x
        echo "auto foo=17;" > gnut.cpp
        ${CXX-"g++"} -std=c++0x -c gnut.cpp
        res=$?
        rm -f gnut.*
        if test "${res}" = 0 ; then
            AC_SUBST(MY_STD,-std=c++0x)
        else
            AC_SUBST(MY_STD,-DNOGPP)
            echo Cannot handle auto
        fi
    fi
fi
echo $MY_STD
AC_CONFIG_FILES(Makefile testsafeqp/Makefile libsafeqp/Makefile)
AC_OUTPUT
