#include "dynamic_bitset.hh"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  {
    dynamic_bitset db(12, 0);

    db.set(0);
    db.set(3);
    std::cout << db.to_string() << std::endl;

    db.resize(8);
    std::cout << db.to_string() << std::endl;
  }

  {
    std::cout << "Initialize with value\n";
    dynamic_bitset db(/* bits */12, /* value */42);
    std::bitset<12> b(42);

    std::cout << db[3] << "\n";

    db.set(3, false);

    std::cout << db[3] << "\n";

    std::cout << db.to_string() << std::endl;
    std::cout << b.to_string() << std::endl;
  }

  {
    // initial size = 0
    dynamic_bitset db;

    db.resize(8);

    // resized bitfield is undefined. so clear with 'false'
    db.reset();
    db.set(7);

    std::cout << db.to_string() << std::endl;
  }

  return EXIT_SUCCESS;
}
