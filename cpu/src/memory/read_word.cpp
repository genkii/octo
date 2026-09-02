#include <cstdint>
#include <octo/memory/memory.hpp>

std::uint16_t Memory::read_word(std::uint16_t high_address) {
	auto high = this->read(high_address);
	auto low = this->read(high_address + 1);

	std::uint16_t value = (static_cast<std::uint16_t>(high) << 8) | low;

	return value;
}