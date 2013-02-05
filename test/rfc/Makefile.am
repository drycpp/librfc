AM_CFLAGS   = -Wall -Wextra -pipe
AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir)
LDADD       = $(top_srcdir)/src/rfc/librfc.la

check_PROGRAMS = \
  check_feature  \
  check_module   \
  check_version

TESTS = $(check_PROGRAMS)
