dnl Process this file with autoconf to produce a configure script.
AC_INIT(libsafeqp, 1.0)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(libsafeqp)
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_OUTPUT(Makefile libsafeqp/Makefile)
echo "int foo;" > gnut.cpp
${CXX-g++} -std=gnu++1z -c gnut.cpp
res=$?
rm -f gnut.*
echo My result $res
if test "${res}" = 0 ; then
echo My result for z
#AC_SUBST([CXXFLAGS],[$(-std=gnu++1z)])
libsafeqp_la_CXXFLAGS += -std=gnu++1z
else
echo My result for y
#AC_SUBST([AM_CXXFLAGS],[-std=gnu++1y])
#libsafeqp_la_CXXFLAGS += -std=gnu++1y
AM_CXXFLAGS += -std=gnu++1y
fi
exit 0
