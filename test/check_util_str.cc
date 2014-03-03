/* This is free and unencumbered software released into the public domain. */

#include "catch.hpp"

#include <rfc/util/str.h>

#include <limits> /* for std::numeric_limits */

static const char* const hello = "Hello, world!\n";
static const std::size_t hello_size = 14;

using namespace rfc;

TEST_CASE("test_npos") {
  //REQUIRE(str::npos == std::numeric_limits<std::size_t>::max()); // FIXME
}

TEST_CASE("test_ctor") {
  REQUIRE_NOTHROW(str());
  REQUIRE_NOTHROW(str(""));
  REQUIRE_NOTHROW(str(hello));
}

TEST_CASE("test_cbegin") {
  REQUIRE(str(hello).cbegin() == hello);
}

TEST_CASE("test_cend") {
  REQUIRE(str(hello).cend() == &hello[hello_size]);
}

TEST_CASE("test_begin") {
  REQUIRE(str(hello).begin() == hello);
}

TEST_CASE("test_end") {
  REQUIRE(str(hello).end() == &hello[hello_size]);
}

TEST_CASE("test_empty") {
  REQUIRE(str().empty());
  REQUIRE(str("").empty());
  REQUIRE(!str("\n").empty());
  REQUIRE(!str(hello).empty());
}

TEST_CASE("test_clear") {
  str s("");
  REQUIRE(s.data() == "");
  s.clear();
  REQUIRE(s.data() == nullptr);
}

TEST_CASE("test_length") {
  REQUIRE(str().length() == 0);
  REQUIRE(str("").length() == 0);
  REQUIRE(str(hello).length() == hello_size);
}

TEST_CASE("test_size") {
  REQUIRE(str().size() == 0);
  REQUIRE(str("").size() == 0);
  REQUIRE(str(hello).size() == hello_size);
}

TEST_CASE("test_c_str") {
  REQUIRE(str().c_str() == nullptr);
  REQUIRE(str(hello).c_str() == hello);
}

TEST_CASE("test_data") {
  REQUIRE(str().data() == nullptr);
  REQUIRE(str(hello).data() == hello);
}

TEST_CASE("test_operator_brackets") {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    REQUIRE(str(hello)[i] == hello[i]);
  }
  REQUIRE(str(hello)[hello_size] == '\0');
}

TEST_CASE("test_at") {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    REQUIRE(str(hello).at(i) == hello[i]);
  }
  REQUIRE_THROWS_AS(str(hello).at(hello_size), std::out_of_range);
}

TEST_CASE("test_back") {
  REQUIRE(str(hello).back() == '\n');
}

TEST_CASE("test_front") {
  REQUIRE(str(hello).front() == 'H');
}

TEST_CASE("test_pop_back") {
  char buffer[16] {"foobar"};
  REQUIRE(buffer[5] == 'r');
  str(buffer).pop_back();
  REQUIRE(buffer[5] == '\0');
  REQUIRE(std::strcmp(buffer, "fooba") == 0);
}

TEST_CASE("test_compare") {
  REQUIRE(str(hello).compare(str(hello)) == 0);
}

TEST_CASE("test_copy") {
  char buffer[16];
  str(hello).copy(buffer, hello_size);
  REQUIRE(std::strcmp(buffer, hello) == 0);
}

TEST_CASE("test_find") {
  REQUIRE(str(hello).find('H') == 0);
  REQUIRE(str(hello).find('l') == 2);
  //REQUIRE(str(hello).find('?') == str::npos); // FIXME
}

TEST_CASE("test_find_with_pos") {
  //REQUIRE(str(hello).find('H', 1) == str::npos); // FIXME
  REQUIRE(str(hello).find('l', 3) == 3);
  REQUIRE(str(hello).find('l', 4) == 10);
}

TEST_CASE("test_rfind") {
  REQUIRE(str(hello).rfind('H') == 0);
  REQUIRE(str(hello).rfind('l') == 10);
  //REQUIRE(str(hello).rfind('?') == str::npos); // FIXME
}

TEST_CASE("test_rfind_with_pos") {
  //REQUIRE(str(hello).rfind('l', 11) == str::npos); // FIXME
}

TEST_CASE("test_substr") {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    REQUIRE(str(hello).substr(i).data() == hello + i);
  }
}

TEST_CASE("test_substr_from") {
  REQUIRE(str("foo/bar").substr_from('/').data() == "foo/bar" + 3);
}

TEST_CASE("test_substr_after") {
  REQUIRE(str("foo/bar").substr_after('/').data() == "foo/bar" + 4);
}
