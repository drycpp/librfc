/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_RFC4627_JSON_WRITER_H
#define RFC_RFC4627_JSON_WRITER_H

/**
 * @file
 */

#include <cstdio>  /* for FILE, std::fput*() */
#include <cstddef> /* for std::size_t */
#include <cstdint> /* for std::uint*_t */
#include <string>  /* for std::string */

namespace rfc4627 {
  class json_writer;
}

/**
 * A simple JSON serializer.
 */
class rfc4627::json_writer {
public:
  static constexpr std::size_t max_depth = 40;

  json_writer(FILE* stream) : _stream(stream) {}

  json_writer& begin_object();

  json_writer& finish_object();

  json_writer& begin_array();

  json_writer& finish_array();

  json_writer& write_null();

  json_writer& write_boolean(bool value);

  json_writer& write_integer(long long value);

  json_writer& write_number(double value);

  json_writer& write_string(const char* string);

  template <typename T>
  json_writer& write_strings(T string) {
    return write_string(string);
  }

  template <typename T, typename... Args>
  json_writer& write_strings(T string, Args... args) {
    write_string(string);
    return write_strings(args...);
  }

  inline json_writer& write_string(const std::string& string) {
    write(string.c_str());
    return *this;
  }

#ifdef RFC_RFC4627_JSON_VALUE_H
  inline json_writer& write(const json_object& value) {
    return (void)value, *this; // TODO
  }

  inline json_writer& write(const json_array& value) {
    return (void)value, *this; // TODO
  }

  inline json_writer& write(const std::nullptr_t value) {
    return (void)value, write_null();
  }

  inline json_writer& write(const json_boolean& value) {
    return (void)value, *this; // TODO
  }

  inline json_writer& write(const json_number& value) {
    return (void)value, *this; // TODO
  }

  inline json_writer& write(const json_string& value) {
    return (void)value, *this; // TODO
  }
#endif /* RFC_RFC4627_JSON_VALUE_H */

  json_writer& flush();

protected:
  struct flags {
    bool pretty : 1;
  };

  enum class state : std::uint8_t {
    begin = 0,
    object_begin,
    object_key,
    object_value,
    array_begin,
    array_element,
    finish,
    error,
  };

  void write_char(std::uint8_t value) noexcept;

  inline void write(const std::uint8_t c) {
    std::fputc(c, _stream);
  }

  inline void write(const char* const s) {
    std::fputs(s, _stream);
  }

  inline void increment_depth();

  inline void decrement_depth();

  inline void ensure_valid_state();

  inline void reject_object_key();

  inline void transition_state();

  inline void insert_separator();

  inline void insert_whitespace();

private:
  flags _flags = {true};
  unsigned int _depth = 0;
  FILE* _stream = nullptr;
  const char* _indent = "  ";
  state _state[max_depth] = {state::begin};
};

#endif /* RFC_RFC4627_JSON_WRITER_H */
