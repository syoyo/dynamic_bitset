# Simple dynamic_bitset implementation in C++11

[![Build Status](https://dev.azure.com/syoyo/lte%20oss/_apis/build/status/syoyo.dynamic_bitset?branchName=master)](https://dev.azure.com/syoyo/lte%20oss/_build/latest?definitionId=3&branchName=master)

`dynamic_bitset` is implemented as a template class, so you can just include the header file to use it.
`dynamic_bitset` does not depend any library except for STL.

## Requirements

* C++11 compiler

## Usage

```
#include "dynamic_bitset.hh"

// init with 13 bits. fill bitfield with value `42`
dynamic_bitset db(13, 42);

// init with 0bits
dynamic_bitset db;

// resize to 12 bits
db.resize(12);

// resize does not initialize extended memory region.
// Use `reset()` to clear all bitfields.
db.reset();

// set 3rd bit true
db.set(3);

// get 5th bit state
std::cout << db[5] << "\n";

// print bitfield
std::cout << db.to_string() << "\n";

// set all bits with true or false
db.setall(true);

```

## Note

`dynamic_bitset` has similar functions defined in `std::bitset` and `std::vector`.
`dynamic_bitset` is not compatible with `boost::dynamic_bitset`

## TODO

* [ ] Implement more features.
* [ ] Validate endianness.
* [ ] Write more tests.


## Similar projects

* Feature-complete dynamic_bitset in C++17 https://github.com/pinam45/dynamic_bitset

## License

dynamic_bitset is licensed under MIT license.

### Thrid party license

* acutest : For unit test. MIT license.
