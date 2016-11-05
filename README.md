Header only implementation of the Tiger and Tiger2 Hash in C++14.

The code will compile without warnings when using clang with ```-Weverything -Wno-c++98-compat-pedantic -Wno-padded```.

Example:

```
#include "tiger_hash.h"
#include <iostream>

int main()
{
	// 1) Initialize the algorithm
	Hash::tiger_algorithm_t tiger;
	// 2) Update the internal state
	tiger.update(u8"Hallo Welt");
	// 3) Get the hash from the algorithm (this also resets the internal state of the algorithm!)
	Hash::tiger_hash_t hash = tiger.get_digest();
	// 4) Display the hash in hexadecimal format
	std::cout << Hash::to_string(hash) << std::endl;

	// *) Hash calculation in one step:
	std::cout << Hash::to_string(Hash::tiger2_algorithm_t(u8"Hallo Welt").get_digest()) << std::endl;
}
```

The Hash algorithm was published in:

 * Ross Anderson and Eli Biham, Tiger — A Fast New Hash Function, proceedings of Fast Software Encryption 3, Cambridge, 1996
