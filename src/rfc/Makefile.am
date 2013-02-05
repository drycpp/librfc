AM_CFLAGS       = -Wall -Wextra -fPIC -DPIC -pipe
AM_CPPFLAGS     = -I$(top_srcdir)/src -iquote $(srcdir)
AM_LDFLAGS      = -rdynamic
LDADD           = librfc.la
lib_LTLIBRARIES = librfc.la

librfc_la_SOURCES =       \
  feature.c               \
  module.c                \
  version.c

base_pkgincludedir = $(includedir)/rfc

base_pkginclude_HEADERS = \
  feature.h               \
  module.h                \
  version.h
