#include <cstdint>
#include <octo/memory/memory.hpp>

std::uint8_t Memory::read(std::uint16_t address) {
	std::uint8_t value = memory[address];

	return value;
}