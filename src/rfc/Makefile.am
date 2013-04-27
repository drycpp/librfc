AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CXXFLAGS = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/rfc/librfc.la

lib_LTLIBRARIES = librfc.la

librfc_la_SOURCES =       \
  feature.cc              \
  module.cc               \
  version.cc

base_pkgincludedir = $(includedir)/rfc

base_pkginclude_HEADERS = \
  feature.h               \
  module.h                \
  version.h
