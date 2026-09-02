#include <cstdint>
#include <octo/memory/memory.hpp>

void Memory::write_word(std::uint16_t high_address, std::uint16_t value) {
	std::uint8_t high = value >> 8;
	std::uint8_t low = value & 0xFF;

	this->write(high_address, high);
	this->write(high_address + 1, low);
}