#include "tiger_hash.h"
#include <iostream>
#include <vector>

void check_benchmark();

void check_benchmark()
{
	Hash::tiger_algorithm_t t;
	std::vector<std::string> hash_strings;
	for (std::size_t i = 0; i < 1000; ++i)
	{
		std::string in = std::to_string(i);
		t.update(in.data(), in.data() + in.size());
		hash_strings.push_back(Hash::to_string(t.get_digest()));
	}
	for (std::size_t N = 0; N < 1e3; N++)
		for (std::size_t i = 0; i < hash_strings.size(); ++i)
		{
			Hash::tiger_hash_t h = Hash::tiger_hash_t::parse(hash_strings[i]);
			std::string s2 = Hash::to_string(h);
			if (hash_strings[i] != s2)
			{
				std::cout << "FAIL" << std::endl;
				break;
			}
		}
}
