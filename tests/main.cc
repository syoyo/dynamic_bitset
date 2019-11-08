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

    db.flip(3);
    b.flip(3);
    TEST_CHECK(b[3] == db[3]);
  }

}

static void test_to_ulong()
{
  // TODO(LTE): Write test for bits > 32.
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    std::bitset<12> b(42);

    uint64_t db_value = db.to_ulong();
    uint64_t b_value = b.to_ulong();

    TEST_CHECK(db_value == b_value);
  }
}

static void test_to_ullong()
{
  // TODO(LTE): Write test for bits > 64.
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    std::bitset<12> b(42);

    uint64_t db_value = db.to_ullong();
    uint64_t b_value = b.to_ullong();

    TEST_CHECK(db_value == b_value);
  }
}


static void test_data()
{
  {
    dynamic_bitset db(/* bits */12, /* value */42);
    uint8_t value = (*db.data());

    TEST_CHECK(42 == value);

  }

  {
    dynamic_bitset db(/* bits */12, /* value */42);

    TEST_CHECK(12 == db.size());

    // size is in byte size. 1 + (bits - 1) / 8
    TEST_CHECK(2 == db.storage_size());
  }

  {
    dynamic_bitset db(/* bits */64, /* value */42);

    TEST_CHECK(64 == db.size());
    TEST_CHECK(8 == db.storage_size());
  }
}

TEST_LIST = {
  { "dynamic_bitset", test_dynamic_bitset },
  { "test_initial_value", test_initial_value },
  { "test_set", test_set },
  { "test_flip", test_flip },
  { "test_data", test_data },
  { "test_to_ulong", test_to_ulong },
  { "test_to_ullong", test_to_ullong },
  { nullptr, nullptr }
};

