AM_CPPFLAGS = -I$(top_srcdir)/src -iquote $(srcdir) $(BOOST_CPPFLAGS) -DBOOST_TEST_DYN_LINK
AM_CXXFLAGS = -Wall -Wextra -pipe
AM_LDFLAGS  = $(BOOST_LDFLAGS) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)

LDADD = $(top_srcdir)/src/rfc/librfc.la

check_PROGRAMS = \
  check_feature  \
  check_module   \
  check_version

if !DISABLE_RFC1321
  check_PROGRAMS += check_md5
endif

if !DISABLE_RFC2616
  check_PROGRAMS += check_http
endif

if !DISABLE_RFC3174
  check_PROGRAMS += check_sha1
endif

if !DISABLE_RFC3629
  check_PROGRAMS += check_utf8
endif

if !DISABLE_RFC3986
  check_PROGRAMS += check_uri
endif

if !DISABLE_RFC4122
  check_PROGRAMS += check_uuid
endif

if !DISABLE_RFC4627
  check_PROGRAMS += check_json
endif

TESTS = $(check_PROGRAMS)

AM_DEFAULT_SOURCE_EXT = .cc
