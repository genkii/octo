#include <cstdint>
#include <octo/memory/memory.hpp>

void Memory::set_memory(std::array<std::uint8_t, 65536> memory) {
	this->memory = memory;
}