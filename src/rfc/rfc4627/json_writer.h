/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_RFC4627_JSON_WRITER_H
#define RFC_RFC4627_JSON_WRITER_H

/**
 * @file
 */

#include <cstdio> /* for FILE */

namespace rfc4627 {
  class json_writer;
}

/**
 * A simple JSON serializer.
 */
class rfc4627::json_writer {
public:
  json_writer(FILE* stream) : _stream(stream) {}

  json_writer& begin_object() {
    set_state(state::object_begin);
    write('{'); // TODO
    return *this;
  }

  json_writer& finish_object() {
    write('}'); // TODO
    return *this;
  }

  json_writer& begin_array() {
    set_state(state::array_begin);
    write('['); // TODO
    return *this;
  }

  json_writer& finish_array() {
    write(']'); // TODO
    return *this;
  }

  json_writer& write_null() {
    write("null");
    return *this;
  }

  json_writer& write_boolean(const bool value) {
    write(value ? "true" : "false");
    return *this;
  }

  json_writer& write_number(long long value);

  json_writer& write_number(unsigned long long value);

  json_writer& write_number(double value);

  json_writer& flush();

protected:
  enum class state {
    none = 0,
    object_begin,
    object_key,
    object_value,
    array_begin,
    array_element,
  };

  inline void set_state(const state s) {
    _state = s;
  }

  inline void write(const int c) {
    fputc(c, _stream);
  }

  inline void write(const char* const s) {
    fputs(s, _stream);
  }

private:
  state _state  = state::none;
  FILE* _stream = nullptr;
};

#endif /* RFC_RFC4627_JSON_WRITER_H */
