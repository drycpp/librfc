AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
AM_CXXFLAGS = -Wall -Wextra -pipe
LDADD       = $(top_srcdir)/src/rfc/librfc.la

check_PROGRAMS = \
  check_feature  \
  check_module   \
  check_version

TESTS = $(check_PROGRAMS)

AM_DEFAULT_SOURCE_EXT = .cc
