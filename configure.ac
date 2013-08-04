dnl configure.ac                                        -*- Autoconf -*-
dnl
dnl Process this file with `autoconf` to produce a configure script.
dnl
dnl This is free and unencumbered software released into the public domain.
AC_PREREQ([2.68])

dnl Define version information:
m4_define([VERSION_MAJOR],
  m4_esyscmd([cut -d'.' -f1 VERSION | tr -d '\n']))
m4_define([VERSION_MINOR],
  m4_esyscmd([cut -d'.' -f2 VERSION | tr -d '\n']))
m4_define([VERSION_PATCH],
  m4_esyscmd([cut -d'.' -f3 VERSION | tr -d '\n']))
m4_define([VERSION_STRING],
  m4_esyscmd([git describe --dirty --always | tr -d '\n']))

dnl Define package information:
AC_INIT([librfc], [VERSION_STRING],
  [arto@bendiken.net], [librfc],
  [http://librfc.org/])

dnl Configure Autoconf:
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_SRCDIR([src/rfc.h])
AC_CONFIG_AUX_DIR([etc/aclocal])
AC_CONFIG_MACRO_DIR([etc/aclocal])

dnl Configure Automake:
AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2 subdir-objects nostdinc])
AM_SILENT_RULES([yes])

dnl Check for programs:
AC_PROG_CC(clang gcc cc)
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_CXX(clang++ g++ c++)
AC_PROG_CXXCPP
AC_USE_SYSTEM_EXTENSIONS
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11([noext])

dnl Check for configuration options:
# --with-stdlib=libstdc++|libc++
AC_ARG_WITH([stdlib],
  [AS_HELP_STRING([--with-stdlib=LIB], [specify the C++ standard library to use [default=system]])],
  [], [with_stdlib=system])
AS_IF([test "x$with_stdlib" != "xsystem"],
  [CXXFLAGS="$CXXFLAGS -stdlib=$with_stdlib"
   LDFLAGS="$LDFLAGS -stdlib=$with_stdlib"])
# --enable-debug/--disable-debug
AC_ARG_ENABLE([debug],
  [AS_HELP_STRING([--enable-debug], [build with debugging support [default=no]])],
  [], [enable_debug=no])
AS_IF([test "x$enable_debug" != "xno"],
  [AC_DEFINE([DEBUG], [1], [Enable debugging support.])],
  [AC_DEFINE([NDEBUG], [1], [Disable assertions.])])
AM_CONDITIONAL([ENABLE_DEBUG], [test "x$enable_debug" != "xno"])
# --enable-unicode/--disable-unicode
AC_ARG_ENABLE([unicode],
  [AS_HELP_STRING([--disable-unicode], [omit support for Unicode strings])])
AS_IF([test "x$enable_unicode" == "xno"],
  [AC_DEFINE([DISABLE_UNICODE], 1, [Define to disable Unicode string support.])])
# --enable-rfc*/--disable-rfc*
AC_DEFUN([AX_ARG_ENABLE_RFC], [dnl
  AC_ARG_ENABLE([rfc$1],
    [AS_HELP_STRING([--disable-rfc$1], [do not include the RFC $1 ($2) module])])
  AS_IF([test "x$enable_rfc$1" == "xno"], [
    AC_DEFINE([DISABLE_RFC$1], 1, [Define to omit the <rfc/rfc$1.h> module.])])
  AM_CONDITIONAL([DISABLE_RFC$1], [test "x$enable_rfc$1" == "xno"])
])
AX_ARG_ENABLE_RFC([1321], [MD5])      # --enable-rfc1321/--disable-rfc1321
AX_ARG_ENABLE_RFC([2616], [HTTP/1.1]) # --enable-rfc2616/--disable-rfc2616
AX_ARG_ENABLE_RFC([3174], [SHA-1])    # --enable-rfc3174/--disable-rfc3174
AX_ARG_ENABLE_RFC([3629], [UTF-8])    # --enable-rfc3629/--disable-rfc3629
AX_ARG_ENABLE_RFC([3986], [URI])      # --enable-rfc3986/--disable-rfc3986
AX_ARG_ENABLE_RFC([4122], [UUID])     # --enable-rfc4122/--disable-rfc4122
AX_ARG_ENABLE_RFC([4627], [JSON])     # --enable-rfc4627/--disable-rfc4627

dnl Check for libraries:
AX_BOOST_BASE([1.48], [AX_BOOST_UNIT_TEST_FRAMEWORK])

dnl Check for header files:
AC_LANG_PUSH([C])
AC_HEADER_ASSERT
AC_HEADER_STDBOOL
AC_LANG_POP([C])

dnl Check for types:

dnl Check for structures:

dnl Check for compiler characteristics:
AC_CANONICAL_HOST
AM_CPPFLAGS="$AM_CPPFLAGS -I\$(top_srcdir)/src -iquote \$(srcdir)"
AM_CXXFLAGS="$AM_CXXFLAGS -Wall -Wextra -pipe"
AM_LDFLAGS="$AM_LDFLAGS"
TEST_CPPFLAGS="$AM_CPPFLAGS \$(BOOST_CPPFLAGS) -DBOOST_TEST_DYN_LINK"
TEST_CXXFLAGS="$AM_CXXFLAGS"
TEST_LDFLAGS="$AM_LDFLAGS \$(BOOST_LDFLAGS) \$(BOOST_UNIT_TEST_FRAMEWORK_LIB)"
AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([TEST_CPPFLAGS])
AC_SUBST([TEST_CXXFLAGS])
AC_SUBST([TEST_LDFLAGS])

dnl Check for library functions:
AC_FUNC_ALLOCA

dnl Check for system services:

dnl Generate output:
AC_CONFIG_FILES([Makefile src/Makefile src/rfc/Makefile test/Makefile test/rfc/Makefile])
AC_SUBST([PACKAGE_VERSION_MAJOR], ["VERSION_MAJOR"])
AC_SUBST([PACKAGE_VERSION_MINOR], ["VERSION_MINOR"])
AC_SUBST([PACKAGE_VERSION_PATCH], ["VERSION_PATCH"])
AC_CONFIG_FILES([src/rfc/version.h])
dnl AH_BOTTOM([#include "rfc/prelude.h"])
AC_OUTPUT
