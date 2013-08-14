/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "json_writer.h"

#include <cassert>   /* for assert() */
#include <cstdio>    /* for fflush(), fprintf() */
#include <stdexcept> /* for std::invalid_argument */

using namespace rfc4627;

json_writer&
json_writer::write_null() {
  write("null");
  return *this;
}

json_writer&
json_writer::write_boolean(const bool value) {
  write(value ? "true" : "false");
  return *this;
}

json_writer&
json_writer::write_number(const long long value) {
  fprintf(_stream, "%lld", value);
  return *this;
}

json_writer&
json_writer::write_number(const unsigned long long value) {
  fprintf(_stream, "%llu", value);
  return *this;
}

json_writer&
json_writer::write_number(const double value) {
  fprintf(_stream, "%.20g", value);
  return *this;
}

json_writer&
json_writer::write_string(const char* const value) {
  if (value == nullptr) {
    return write_null();
  }
  write('"');
  const char* s = value;
  while (*s != '\0') {
    write_char(*s++);
  }
  write('"');
  return *this;
}

void
json_writer::write_char(const std::uint8_t value) noexcept {
  switch (value) {
    case '"':  /* U+0022 quotation mark */
      write("\\\"");
      break;
    case '\\': /* U+005C reverse solidus */
      write("\\\\");
      break;
    case '/':  /* U+002F solidus */
      write("\\/");
      break;
    case '\b': /* U+0008 backspace */
      write("\\b");
      break;
    case '\f': /* U+000C form feed */
      write("\\f");
      break;
    case '\n': /* U+000A line feed */
      write("\\n");
      break;
    case '\r': /* U+000D carriage return */
      write("\\r");
      break;
    case '\t': /* U+0009 tab */
      write("\\t");
      break;
    default:
      if (value <= 0x1F) { /* ASCII control character */
        write("\\u");
        fprintf(_stream, "%04X", value);
      }
      else { /* UTF-8 character */
        write(value);
      }
  }
}

json_writer&
json_writer::flush() {
  if (fflush(_stream) != 0) {
    // TODO: error handling
  }
  return *this;
}
