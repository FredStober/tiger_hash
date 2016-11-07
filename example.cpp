#include "tiger_hash.h"
#include <iostream>

int main()
{
	// 1) Initialize the algorithm
	Hash::tiger_algorithm_t tiger;
	// 2) Update the internal state
	tiger.update(u8"Hello World");
	// 3) Get the hash from the algorithm (this also resets the internal state of the algorithm!)
	Hash::tiger_hash_t hash = tiger.get_digest();
	// 4) Display the hash in hexadecimal format
	std::cout << Hash::to_string(hash) << std::endl;

	// *) Hash calculation in one step:
	std::cout << Hash::to_string(Hash::tiger2_algorithm_t(u8"Hello World").get_digest()) << std::endl;
	Hash::tiger_algorithm_t tiger;
	tiger.update(u8"Hello World");
	Hash::tiger_hash_t hash = tiger.get_digest();
	std::cout << Hash::to_string(hash) << std::endl;
}
