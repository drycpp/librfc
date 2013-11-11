/* This is free and unencumbered software released into the public domain. */

#define BOOST_TEST_MODULE util_str
#include <boost/test/unit_test.hpp>

#include <rfc/util/str.h>

#include <limits> /* for std::numeric_limits */

static const char* const hello = "Hello, world!\n";
static const std::size_t hello_size = 14;

using namespace rfc;

BOOST_AUTO_TEST_CASE(test_npos) {
  BOOST_CHECK(str::npos == std::numeric_limits<std::size_t>::max());
}

BOOST_AUTO_TEST_CASE(test_ctor) {
  BOOST_CHECK_NO_THROW(str());
  BOOST_CHECK_NO_THROW(str(""));
  BOOST_CHECK_NO_THROW(str(hello));
}

BOOST_AUTO_TEST_CASE(test_cbegin) {
  BOOST_CHECK_EQUAL(str(hello).cbegin(), hello);
}

BOOST_AUTO_TEST_CASE(test_cend) {
  BOOST_CHECK_EQUAL(str(hello).cend(), &hello[hello_size]);
}

BOOST_AUTO_TEST_CASE(test_begin) {
  BOOST_CHECK_EQUAL(str(hello).begin(), hello);
}

BOOST_AUTO_TEST_CASE(test_end) {
  BOOST_CHECK_EQUAL(str(hello).end(), &hello[hello_size]);
}

BOOST_AUTO_TEST_CASE(test_empty) {
  BOOST_CHECK(str().empty());
  BOOST_CHECK(str("").empty());
  BOOST_CHECK(!str("\n").empty());
  BOOST_CHECK(!str(hello).empty());
}

BOOST_AUTO_TEST_CASE(test_clear) {
  str s("");
  BOOST_CHECK_EQUAL(s.data(), "");
  s.clear();
  BOOST_CHECK(s.data() == nullptr);
}

BOOST_AUTO_TEST_CASE(test_length) {
  BOOST_CHECK_EQUAL(str().length(), 0);
  BOOST_CHECK_EQUAL(str("").length(), 0);
  BOOST_CHECK_EQUAL(str(hello).length(), hello_size);
}

BOOST_AUTO_TEST_CASE(test_size) {
  BOOST_CHECK_EQUAL(str().size(), 0);
  BOOST_CHECK_EQUAL(str("").size(), 0);
  BOOST_CHECK_EQUAL(str(hello).size(), hello_size);
}

BOOST_AUTO_TEST_CASE(test_c_str) {
  BOOST_CHECK(str().c_str() == nullptr);
  BOOST_CHECK_EQUAL(str(hello).c_str(), hello);
}

BOOST_AUTO_TEST_CASE(test_data) {
  BOOST_CHECK(str().data() == nullptr);
  BOOST_CHECK_EQUAL(str(hello).data(), hello);
}

BOOST_AUTO_TEST_CASE(test_operator_brackets) {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    BOOST_CHECK_EQUAL(str(hello)[i], hello[i]);
  }
  BOOST_CHECK_EQUAL(str(hello)[hello_size], '\0');
}

BOOST_AUTO_TEST_CASE(test_at) {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    BOOST_CHECK_EQUAL(str(hello).at(i), hello[i]);
  }
  BOOST_CHECK_THROW(str(hello).at(hello_size), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(test_back) {
  BOOST_CHECK_EQUAL(str(hello).back(), '\n');
}

BOOST_AUTO_TEST_CASE(test_front) {
  BOOST_CHECK_EQUAL(str(hello).front(), 'H');
}

BOOST_AUTO_TEST_CASE(test_pop_back) {
  char buffer[16] {"foobar"};
  BOOST_CHECK_EQUAL(buffer[5], 'r');
  str(buffer).pop_back();
  BOOST_CHECK_EQUAL(buffer[5], '\0');
  BOOST_CHECK_EQUAL(std::strcmp(buffer, "fooba"), 0);
}

BOOST_AUTO_TEST_CASE(test_compare) {
  BOOST_CHECK_EQUAL(str(hello).compare(str(hello)), 0);
}

BOOST_AUTO_TEST_CASE(test_copy) {
  char buffer[16];
  str(hello).copy(buffer, hello_size);
  BOOST_CHECK_EQUAL(std::strcmp(buffer, hello), 0);
}

BOOST_AUTO_TEST_CASE(test_find) {
  BOOST_CHECK_EQUAL(str(hello).find('H'), 0);
  BOOST_CHECK_EQUAL(str(hello).find('l'), 2);
  BOOST_CHECK(str(hello).find('?') == str::npos);
}

BOOST_AUTO_TEST_CASE(test_rfind) {
  BOOST_CHECK_EQUAL(str(hello).rfind('H'), 0);
  BOOST_CHECK_EQUAL(str(hello).rfind('l'), 10);
  BOOST_CHECK(str(hello).rfind('?') == str::npos);
}

BOOST_AUTO_TEST_CASE(test_substr) {
  for (auto i = 0U; i < std::strlen(hello); i++) {
    BOOST_CHECK_EQUAL(str(hello).substr(i).data(), hello + i);
  }
}

BOOST_AUTO_TEST_CASE(test_substr_from) {
  BOOST_CHECK_EQUAL(str("foo/bar").substr_from('/').data(), "foo/bar" + 3);
}

BOOST_AUTO_TEST_CASE(test_substr_after) {
  BOOST_CHECK_EQUAL(str("foo/bar").substr_after('/').data(), "foo/bar" + 4);
}
