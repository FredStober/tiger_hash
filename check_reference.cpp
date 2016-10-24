#include "tiger_hash.h"
#include <iostream>

void check_reference();

template<typename HashAlgorithm>
inline void check_hash(std::string const & in, std::string const & ref)
{
	HashAlgorithm t;
	t.update(in);
	typename HashAlgorithm::result_type const h = t.get_digest();
	if (to_string(h) != ref)
		std::cout << "\tFAIL: " << Hash::to_string(h) << " " << in << std::endl;
	else
		std::cout << "\tOK: " << Hash::to_string(h) << std::endl;
}

void check_reference()
{
	std::cout << "Checking hash reference values ..." << std::endl;
	check_hash<Hash::tiger_algorithm_t>("", "3293ac630c13f0245f92bbb1766e16167a4e58492dde73f3");
	check_hash<Hash::tiger2_algorithm_t>("", "4441be75f6018773c206c22745374b924aa8313fef919f41");
	check_hash<Hash::tiger_algorithm_t>("The quick brown fox jumps over the lazy dog", "6d12a41e72e644f017b6f0e2f7b44c6285f06dd5d2c5b075");
	check_hash<Hash::tiger2_algorithm_t>("The quick brown fox jumps over the lazy dog", "976abff8062a2e9dcea3a1ace966ed9c19cb85558b4976d8");
	check_hash<Hash::tiger_algorithm_t>("The quick brown fox jumps over the lazy cog", "a8f04b0f7201a0d728101c9d26525b31764a3493fcd8458f");
	check_hash<Hash::tiger2_algorithm_t>("The quick brown fox jumps over the lazy cog", "09c11330283a27efb51930aa7dc1ec624ff738a8d9bdd3df");
	check_hash<Hash::tiger_algorithm_t>(std::string(    1,  'a'), "77befbef2e7ef8ab2ec8f93bf587a7fc613e247f5f247809");
	check_hash<Hash::tiger_algorithm_t>(std::string(  140,  'a'), "6a49ece93ed6bf1a520bf23ee1c333a265f0837848850fcc");
	check_hash<Hash::tiger_algorithm_t>("abc", "2aab1484e8c158f2bfb8c5ff41b57a525129131c957b5f93");
	check_hash<Hash::tiger_algorithm_t>("12345678901234567890123456789012345678901234567890123456789012345678901234567890",
		"1c14795529fd9f207a958f84c52f11e887fa0cabdfd91bfd");
	check_hash<Hash::tiger_algorithm_t>("message digest", "d981f8cb78201a950dcf3048751e441c517fca1aa55a29f6");
	check_hash<Hash::tiger_algorithm_t>("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
		"0f7bf9a19b9c58f2b7610df7e84f0ac3a71c631e7b53f78e");
	check_hash<Hash::tiger_algorithm_t>("abcdefghijklmnopqrstuvwxyz", "1714a472eee57d30040412bfcc55032a0b11602ff37beee9");
	check_hash<Hash::tiger_algorithm_t>(std::string(  0/8, '\0'), "3293ac630c13f0245f92bbb1766e16167a4e58492dde73f3");
	check_hash<Hash::tiger_algorithm_t>(std::string(  8/8, '\0'), "5d9ed00a030e638bdb753a6a24fb900e5a63b8e73e6c25b6");
	check_hash<Hash::tiger_algorithm_t>(std::string( 80/8, '\0'), "654d00c774fbe74cfe4c0a6dea5917823a6b20070cd0cccb");
	check_hash<Hash::tiger_algorithm_t>(std::string(800/8, '\0'), "a5a54e12a9538a158e78ae09896dcb2ce31f14150625e615");
	check_hash<Hash::tiger_algorithm_t>(std::string(1000000, 'a'), "6db0e2729cbead93d715c6a7d36302e9b3cee0d2bc314b41");
}
