#include "tiger_hash.h"
#include <iostream>

int main()
{
	Hash::tiger_algorithm_t tiger;
	tiger.update(u8"Hallo Welt");
	std::cout << Hash::to_string(tiger.get_digest()) << std::endl;
}
