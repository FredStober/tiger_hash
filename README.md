Header only implementation of the Tiger and Tiger2 Hash in C++14.

The code will compile without warnings when using clang with ```-Weverything -Wno-c++98-compat-pedantic -Wno-padded```.

Example:

```
#include "tiger_hash.h"
#include <iostream>

int main()
{
	Hash::tiger_algorithm_t tiger;
	tiger.update(u8"Hallo Welt");
	std::cout << Hash::to_string(tiger.get_digest()) << std::endl;
}
```

The Hash algorithm was published in:

 * Ross Anderson and Eli Biham, Tiger — A Fast New Hash Function, proceedings of Fast Software Encryption 3, Cambridge, 1996
