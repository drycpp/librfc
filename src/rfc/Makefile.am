AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CXXFLAGS = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/rfc/librfc.la

lib_LTLIBRARIES = librfc.la

librfc_la_SOURCES =       \
  feature.cc              \
  module.cc               \
  version.cc

pkgincludedir = $(includedir)/rfc
base_pkgincludedir = $(pkgincludedir)

base_pkginclude_HEADERS = \
  feature.h               \
  module.h                \
  version.h

nobase_pkginclude_HEADERS =

if !DISABLE_RFC1321
  librfc_la_SOURCES       += rfc1321/md5.cc
  nobase_pkginclude_HEADERS += rfc1321.h rfc1321/md5.h
endif

if !DISABLE_RFC3174
  librfc_la_SOURCES       += rfc3174/sha1.cc
  nobase_pkginclude_HEADERS += rfc3174.h rfc3174/sha1.h
endif
