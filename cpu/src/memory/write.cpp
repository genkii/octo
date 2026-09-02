#include <cstdint>
#include <octo/memory/memory.hpp>

void Memory::write(std::uint16_t address, std::uint8_t value) {
	memory[address] = value;
}
