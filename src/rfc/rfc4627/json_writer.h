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
    write('{'); // TODO
    return *this;
  }

  json_writer& finish_object() {
    write('}'); // TODO
    return *this;
  }

  json_writer& write_null() {
    write("null");
    return *this;
  }

  json_writer& write_bool(const bool value) {
    write(value ? "true" : "false");
    return *this;
  }

  json_writer& flush();

protected:
  inline void write(const int c) {
    fputc(c, _stream);
  }

  inline void write(const char* const s) {
    fputs(s, _stream);
  }

  enum class state {
    none = 0,
  };

private:
  state _state  = state::none;
  FILE* _stream = nullptr;
};

#endif /* RFC_RFC4627_JSON_WRITER_H */
