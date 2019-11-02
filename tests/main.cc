#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif

#include "acutest.h"

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <bitset>
#include <iostream>

#include "dynamic_bitset.hh"

static void test_dynamic_bitset()
{
  dynamic_bitset db;
  db.resize(1);

  TEST_CHECK(db[0] == false);

  db.set(0, true);
  TEST_CHECK(db[0] == true);

}

static void test_initial_value()
{
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    std::bitset<12> b(42);

    for (size_t i = 0; i < 12; i++) {
      TEST_CHECK(db[i] == b[i]);
    }

    TEST_CHECK(db.to_string().compare(b.to_string()) == 0);
  }

  {
    dynamic_bitset db(/* bits */48, /* value */0x123f80000);
    std::bitset<48> b(0x123f80000);

    for (size_t i = 0; i < 48; i++) {
      TEST_CHECK(db[i] == b[i]);
    }

    TEST_CHECK(db.to_string().compare(b.to_string()) == 0);
  }

}

static void test_set()
{
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    db.setall(true);

    for (size_t i = 0; i < 12; i++) {
      TEST_CHECK(true == db[i]);
    }

    db.set(11, false);
    TEST_CHECK(false == db.test(11));

    db.setall(false);

    for (size_t i = 0; i < 12; i++) {
      TEST_CHECK(false == db[i]);
    }
  }
}

static void test_flip()
{
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    std::bitset<12> b(42);

    db.flip();
    b.flip();

    for (size_t i = 0; i < 12; i++) {
      TEST_CHECK(b[i] == db[i]);
    }
  }
}

TEST_LIST = {
  { "dynamic_bitset", test_dynamic_bitset },
  { "test_initial_value", test_initial_value },
  { "test_set", test_set },
  { "test_flip", test_flip },
  { nullptr, nullptr }
};

