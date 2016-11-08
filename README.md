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
	tiger.update(std::string("Hello World"));
	// 3) Get the hash from the algorithm (this also resets the internal state of the algorithm!)
	Hash::tiger_hash_t hash = tiger.get_digest();
	// 4) Display the hash in hexadecimal format
	std::cout << Hash::to_string(hash) << std::endl;
	// 5) Comparison of hash with reference value
	if (hash == Hash::tiger_hash_t::parse("2bab23b832ed1cc054498b8e5a9f2924d4042f35a22aaa55"))
		std::cout << "hash confirmed" << std::endl;
	else
		std::cout << "invalid hash!" << std::endl;

	// *) Hash calculation in one step (here with Tiger2):
	std::cout << Hash::to_string(Hash::tiger2_algorithm_t(std::string("Hello World")).get_digest()) << std::endl;
}
```

The Hash algorithm was published in:

 * Ross Anderson and Eli Biham, Tiger — A Fast New Hash Function, proceedings of Fast Software Encryption 3, Cambridge, 1996
