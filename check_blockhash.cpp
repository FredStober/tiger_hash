#include "tiger_hash.hpp"
#include <iostream>
#include <vector>

void check_blockhash();

void check_blockhash()
{
	std::cout << "Checking block hash function..." << std::endl;
	std::array<Hash::byte_t, 64> block;
	block.fill(0x77);
	block[55] = 0x01; // padding
	uint64_t bit_count = 55 << 3;
	std::memcpy(block.data() + 56, &bit_count, sizeof(std::uint64_t));

	std::array<Hash::byte_t, 24> block_hash;
	Hash::tiger_compress_block(block.data(), block_hash.data());
	std::string const hash_direct(Hash::_to_string(block_hash));
	Hash::tiger_algorithm_t algo(block.begin(), block.end() - 8 - 1);
	std::string const hash_algo(Hash::to_string(algo.get_digest()));
	if (hash_algo == hash_direct)
		std::cout << "\tOK: " << hash_direct << std::endl;
	else
		std::cout << "\tFAIL: " << hash_direct << " " << hash_algo << std::endl;
}
