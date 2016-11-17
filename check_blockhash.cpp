#include "tiger_hash.hpp"
#include <iostream>
#include <vector>

void check_blockhash();

void check_blockhash()
{
	std::array<Hash::byte_t, 64> block;
	block.fill(0x77);
	block[55] = 0x01; // padding
	uint64_t bit_count = 55 << 3;
	std::memcpy(block.data() + 56, &bit_count, sizeof(std::uint64_t));

	std::array<Hash::byte_t, 24> block_hash = Hash::tiger_compress_block(block);
	std::cout << Hash::_to_string(block_hash) << std::endl;
	Hash::tiger_algorithm_t algo(block.begin(), block.end() - 8 - 1);
	std::cout << Hash::to_string(algo.get_digest()) << std::endl;
}
