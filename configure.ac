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
# --enable-rfc1321/--disable-rfc1321
AC_ARG_ENABLE([rfc1321],
  [AS_HELP_STRING([--disable-rfc1321], [do not include the RFC 1321 (MD5) module])])
AS_IF([test "x$enable_rfc1321" == "xno"], [
  AC_DEFINE([DISABLE_RFC1321], 1, [Define to omit the <rfc/rfc1321.h> module.])])
AM_CONDITIONAL([DISABLE_RFC1321], [test "x$enable_rfc1321" == "xno"])
# --enable-rfc2616/--disable-rfc2616
AC_ARG_ENABLE([rfc2616],
  [AS_HELP_STRING([--disable-rfc2616], [do not include the RFC 2616 (HTTP/1.1) module])])
AS_IF([test "x$enable_rfc2616" == "xno"], [
  AC_DEFINE([DISABLE_RFC2616], 1, [Define to omit the <rfc/rfc2616.h> module.])])
AM_CONDITIONAL([DISABLE_RFC2616], [test "x$enable_rfc2616" == "xno"])
# --enable-rfc3174/--disable-rfc3174
AC_ARG_ENABLE([rfc3174],
  [AS_HELP_STRING([--disable-rfc3174], [do not include the RFC 3174 (SHA-1) module])])
AS_IF([test "x$enable_rfc3174" == "xno"], [
  AC_DEFINE([DISABLE_RFC3174], 1, [Define to omit the <rfc/rfc3174.h> module.])])
AM_CONDITIONAL([DISABLE_RFC3174], [test "x$enable_rfc3174" == "xno"])
# --enable-rfc3629/--disable-rfc3629
AC_ARG_ENABLE([rfc3629],
  [AS_HELP_STRING([--disable-rfc3629], [do not include the RFC 3629 (UTF-8) module])])
AS_IF([test "x$enable_rfc3629" == "xno"], [
  AC_DEFINE([DISABLE_RFC3629], 1, [Define to omit the <rfc/rfc3629.h> module.])])
AM_CONDITIONAL([DISABLE_RFC3629], [test "x$enable_rfc3629" == "xno"])
# --enable-rfc3986/--disable-rfc3986
AC_ARG_ENABLE([rfc3986],
  [AS_HELP_STRING([--disable-rfc3986], [do not include the RFC 3986 (URI) module])])
AS_IF([test "x$enable_rfc3986" == "xno"], [
  AC_DEFINE([DISABLE_RFC3986], 1, [Define to omit the <rfc/rfc3986.h> module.])])
AM_CONDITIONAL([DISABLE_RFC3986], [test "x$enable_rfc3986" == "xno"])
# --enable-rfc4122/--disable-rfc4122
AC_ARG_ENABLE([rfc4122],
  [AS_HELP_STRING([--disable-rfc4122], [do not include the RFC 4122 (UUID) module])])
AS_IF([test "x$enable_rfc4122" == "xno"], [
  AC_DEFINE([DISABLE_RFC4122], 1, [Define to omit the <rfc/rfc4122.h> module.])])
AM_CONDITIONAL([DISABLE_RFC4122], [test "x$enable_rfc4122" == "xno"])
# --enable-rfc4627/--disable-rfc4627
AC_ARG_ENABLE([rfc4627],
  [AS_HELP_STRING([--disable-rfc4627], [do not include the RFC 4627 (JSON) module])])
AS_IF([test "x$enable_rfc4627" == "xno"], [
  AC_DEFINE([DISABLE_RFC4627], 1, [Define to omit the <rfc/rfc4627.h> module.])])
AM_CONDITIONAL([DISABLE_RFC4627], [test "x$enable_rfc4627" == "xno"])

dnl Check for libraries:

dnl Check for header files:
AC_LANG_PUSH([C])
AC_HEADER_ASSERT
AC_HEADER_STDBOOL
AC_LANG_POP([C])

dnl Check for types:

dnl Check for structures:

dnl Check for compiler characteristics:
AC_CANONICAL_HOST
AC_C_BIGENDIAN
AC_C_INLINE
AC_C_RESTRICT

dnl Check for library functions:
AC_FUNC_ALLOCA

dnl Check for system services:

dnl Generate output:
AC_CONFIG_FILES([Makefile src/Makefile src/rfc/Makefile test/Makefile test/rfc/Makefile])
AC_SUBST([PACKAGE_VERSION_MAJOR], ["VERSION_MAJOR"])
AC_SUBST([PACKAGE_VERSION_MINOR], ["VERSION_MINOR"])
AC_SUBST([PACKAGE_VERSION_PATCH], ["VERSION_PATCH"])
AC_CONFIG_FILES([src/rfc/version.h])
#AH_BOTTOM([#include "rfc/prelude.h"])
AC_OUTPUT
