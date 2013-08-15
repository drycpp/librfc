/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "json_writer.h"

#include <cassert>   /* for assert() */
#include <cmath>     /* for std::isinf(), std::isnan() */
#include <cstdio>    /* for std::fflush(), std::fprintf() */
#include <stdexcept> /* for std::invalid_argument, std::*_error */

using namespace rfc4627;

json_writer&
json_writer::begin_object() {
  ensure_valid_state();
  reject_object_key();

  insert_separator();
  insert_whitespace();

  increment_depth();
  _state[_depth] = state::object_begin;

  write('{');
  if (_flags.pretty) {
    write('\n');
  }

  return *this;
}

json_writer&
json_writer::finish_object() {
  ensure_valid_state();
  decrement_depth();

  if (_flags.pretty) {
    write('\n');
  }

  transition_state();

  insert_whitespace();

  write('}');

  return *this;
}

json_writer&
json_writer::begin_array() {
  ensure_valid_state();
  reject_object_key();

  insert_separator();
  insert_whitespace();

  increment_depth();
  _state[_depth] = state::array_begin;

  write('[');
  if (_flags.pretty) {
    write('\n');
  }

  return *this;
}

json_writer&
json_writer::finish_array() {
  ensure_valid_state();
  decrement_depth();

  if (_flags.pretty) {
    write('\n');
  }

  transition_state();

  insert_whitespace();

  write(']');

  return *this;
}

json_writer&
json_writer::write_null() {
  ensure_valid_state();
  reject_object_key();

  insert_separator();
  insert_whitespace();

  write("null");

  transition_state();

  return *this;
}

json_writer&
json_writer::write_boolean(const bool value) {
  ensure_valid_state();
  reject_object_key();

  insert_separator();
  insert_whitespace();

  write(value ? "true" : "false");

  transition_state();

  return *this;
}

json_writer&
json_writer::write_integer(const long long value) {
  ensure_valid_state();
  reject_object_key();

  insert_separator();
  insert_whitespace();

  std::fprintf(_stream, "%lld", value);

  transition_state();

  return *this;
}

json_writer&
json_writer::write_number(const double value) {
  ensure_valid_state();
  reject_object_key();

  /* Numeric values that cannot be represented as sequences of digits
   * (such as Infinity and NaN) are not permitted. */
  if (std::isinf(value)) {
    throw std::invalid_argument("Infinity cannot be represented in JSON serialization");
  }
  if (std::isnan(value)) {
    throw std::invalid_argument("NaN cannot be represented in JSON serialization");
  }

  insert_separator();
  insert_whitespace();

  std::fprintf(_stream, "%.20g", value);

  transition_state();

  return *this;
}

json_writer&
json_writer::write_string(const char* const value) {
  ensure_valid_state();
  insert_separator();
  insert_whitespace();

  if (value == nullptr) {
    return write_null();
  }

  write('"');
  const char* s = value;
  while (*s != '\0') {
    write_char(*s++);
  }
  write('"');

  transition_state();

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
        std::fprintf(_stream, "%04X", value);
      }
      else { /* UTF-8 character */
        write(value);
      }
  }
}

json_writer&
json_writer::flush() {
  if (std::fflush(_stream) != 0) {
    // TODO: error handling
  }

  return *this;
}

void
json_writer::increment_depth() {
  if (++_depth >= max_depth) {
    throw std::overflow_error("maximum nesting depth exceeded in JSON serialization");
  }
}

void
json_writer::decrement_depth() {
  assert(_depth >= 1);
  if (--_depth >= max_depth) { /* wraps around */
    throw std::logic_error("mismatched begin/finish nesting in JSON serialization");
  }
}

void
json_writer::ensure_valid_state() {
  switch (_state[_depth]) {
    case state::error:
      throw std::logic_error("error state encountered in JSON serialization");
    case state::finish:
      throw std::logic_error("output already finished in JSON serialization");
    default:
      break;
  }
}

void
json_writer::transition_state() {
  switch (_state[_depth]) {
    case state::begin:
      _state[_depth] = state::finish;
      break;
    case state::object_begin:
    case state::object_key:
      _state[_depth] = state::object_value;
      break;
    case state::object_value:
      _state[_depth] = state::object_key;
      break;
    case state::array_begin:
      _state[_depth] = state::array_element;
      break;
    default:
      break;
  }
}

void
json_writer::reject_object_key() {
  switch (_state[_depth]) {
    case state::object_begin:
    case state::object_key:
      throw std::logic_error("object keys must be strings in JSON serialization");
    default:
      break;
  }
}

void
json_writer::insert_separator() {
  switch (_state[_depth]) {
    case state::object_key:
    case state::array_element:
      write(',');
      if (_flags.pretty) {
        write('\n');
      }
      break;
    case state::object_value:
      write(':');
      if (_flags.pretty) {
        write(' ');
      }
      break;
    default:
      break;
  }
}

void
json_writer::insert_whitespace() {
  if (_flags.pretty) {
    if (_state[_depth] != state::object_value) {
      for (auto i = 0U; i < _depth; i++) {
        write(_indent);
      }
    }
  }
}
