# Simple dynamic_bitset implementation in C++11

dynamic_bitset is implemented as a template class, so you can just include the header file to use it.

## Requirements

* C++11 compiler

## Usage

```
#include "dynamic_bitset.hh"

// init with 13 bits
dynamic_bitset db(13);

// init with 0bits
dynamic_bitset db;

// resize to 12bits
db.resize(12);

// set 3rd bit true
db.set(3);

// print bitfield
std::cout << db.to_string() << "\n";
```

## Note

dynamic_bitset is not compatible with `boost::dynamic_bitset`.

## TODO

* [ ] Implement more features.
* [ ] Endianness.
* [ ] Write more tests.

## License

dynamic_bitset is licensed under MIT license.

### Thrid party license

* acutest : For unit test. MIT license.
