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

nobase_pkginclude_HEADERS = \
  util/str.h

if !DISABLE_RFC1321
  librfc_la_SOURCES         += rfc1321/md5_digest.cc
  nobase_pkginclude_HEADERS += rfc1321.h                \
                               rfc1321/md5_digest.h     \
                               md5.h
endif

if !DISABLE_RFC2616
  librfc_la_SOURCES         += rfc2616/http_request.cc  \
                               rfc2616/http_response.cc
  nobase_pkginclude_HEADERS += rfc2616.h                \
                               rfc2616/http_request.h   \
                               rfc2616/http_response.h  \
                               http.h
endif

if !DISABLE_RFC3174
  librfc_la_SOURCES         += rfc3174/sha1_digest.cc
  nobase_pkginclude_HEADERS += rfc3174.h                \
                               rfc3174/sha1_digest.h    \
                               sha1.h
endif

if !DISABLE_RFC3629
  librfc_la_SOURCES         += rfc3629/utf8_decode.cc   \
                               rfc3629/utf8_encode.cc
  nobase_pkginclude_HEADERS += rfc3629.h                \
                               rfc3629/utf8_decode.h    \
                               rfc3629/utf8_encode.h    \
                               utf8.h
endif

if !DISABLE_RFC3986
  librfc_la_SOURCES         += rfc3986/uri.cc
  nobase_pkginclude_HEADERS += rfc3986.h                \
                               rfc3986/uri.h            \
                               uri.h
endif

if !DISABLE_RFC4122
  librfc_la_SOURCES         += rfc4122/uuid.cc
  nobase_pkginclude_HEADERS += rfc4122.h                \
                               rfc4122/uuid.h           \
                               uuid.h
endif

if !DISABLE_RFC4627
  librfc_la_SOURCES         += rfc4627/json_array.cc    \
                               rfc4627/json_boolean.cc  \
                               rfc4627/json_number.cc   \
                               rfc4627/json_object.cc   \
                               rfc4627/json_reader.cc   \
                               rfc4627/json_string.cc   \
                               rfc4627/json_value.cc    \
                               rfc4627/json_writer.cc
  nobase_pkginclude_HEADERS += rfc4627.h                \
                               rfc4627/json_array.h     \
                               rfc4627/json_boolean.h   \
                               rfc4627/json_number.h    \
                               rfc4627/json_object.h    \
                               rfc4627/json_reader.h    \
                               rfc4627/json_string.h    \
                               rfc4627/json_value.h     \
                               rfc4627/json_writer.h    \
                               json.h
endif
