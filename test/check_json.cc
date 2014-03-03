/* This is free and unencumbered software released into the public domain. */

#include "catch.hpp"

#include <rfc/json.h>

using namespace rfc4627;

TEST_CASE("test_json_writer") {
  // @see http://tools.ietf.org/html/rfc4627#section-8
  json_writer json(stdout);
  json.begin_object();
  {
    json.write_string("Image");
    json.begin_object();
    {
      json.write_string("Width");
      json.write_integer(800);
      json.write_string("Height");
      json.write_integer(600);
      json.write_strings("Title", "View from 15th Floor");
      json.write_string("Thumbnail");
      json.begin_object();
      {
        json.write_strings("Url", "http://www.example.com/image/481989943");
        json.write_string("Height");
        json.write_integer(125);
        json.write_string("Width");
        json.write_string("100");
      }
      json.finish_object();
      json.write_string("IDs");
      json.begin_array();
      {
        json.write_integer(116);
        json.write_integer(943);
        json.write_integer(234);
        json.write_integer(38793);
      }
      json.finish_array();
    }
    json.finish_object();
  }
  json.finish_object();
}
