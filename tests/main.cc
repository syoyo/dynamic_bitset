#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif

#include "acutest.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <bitset>

#include "dynamic_bitset.hh"

static void test_dynamic_bitset()
{
  dynamic_bitset db;
  db.resize(1);

  TEST_CHECK(db[0] == false);

  db.set(0, true);
  TEST_CHECK(db[0] == true);

}

TEST_LIST = {
  { "dynamic_bitset", test_dynamic_bitset },
  { nullptr, nullptr }
};

