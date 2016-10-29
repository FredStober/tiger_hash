#include "tiger_hash.h"
#include <functional>
#include <iostream>

void check_comparison();

template<typename Op>
inline void check_cmp(std::string const & desc, Op const & op,
	Hash::tiger_hash_t const & a, Hash::tiger_hash_t const & b)
{
	if (op(a, b))
		std::cout << "\tOK: " << desc << std::endl;
	else
		std::cout << "\tFAIL: " << Hash::to_string(a) << " " << desc << " " << Hash::to_string(b) << std::endl;
}

void check_comparison()
{
	std::cout << "Checking comparison operators ..." << std::endl;
	Hash::tiger_hash_t h1 = Hash::tiger_hash_t::parse("77befbef2e7ef8ab2ec8f93bf587a7fc613e247f5f247809");
	Hash::tiger_hash_t h2 = Hash::tiger_hash_t::parse("77befbef2e7ef8ab2ec8f93bf587a7fc613e247f5f247809");
	Hash::tiger_hash_t h3 = Hash::tiger_hash_t::parse("2aab1484e8c158f2bfb8c5ff41b57a525129131c957b5f93");

	check_cmp("==", std::equal_to<Hash::tiger_hash_t const &>(), h1, h2);
	check_cmp("!=", std::not_equal_to<Hash::tiger_hash_t>(), h1, h3);
	check_cmp("<", std::less<>(), h3, h1);
	check_cmp("<=", std::less_equal<>(), h3, h1);
	check_cmp(">", std::greater<>(), h1, h3);
	check_cmp(">=", std::greater_equal<>(), h1, h3);
}
