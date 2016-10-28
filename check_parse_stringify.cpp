#include "tiger_hash.h"
#include <iostream>

void check_parse_stringify();

void check_parse_stringify()
{
	std::cout << "Checking hash parse and stringify operations ..." << std::endl;
	std::string const s1 = "77befbef2e7ef8ab2ec8f93bf587a7fc613e247f5f247809";
	Hash::tiger_hash_t const h = Hash::tiger_hash_t::parse(s1);
	std::string const s2 = Hash::to_string(h);
	if (s1 == s2)
		std::cout << "\tOK: string->hash->string " << s1 << std::endl;
	else
		std::cout << "\tFAIL: string->hash->string " << s1 << " " << s2 << std::endl;
}
