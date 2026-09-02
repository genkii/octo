#include <cstdint>
#include <octo/memory/memory.hpp>
#include <octo_log.h>

void Memory::write_word(std::uint16_t high_address, std::uint16_t value) {
	if (high_address > 0xFFFE) {
		log_error("[Memory]", "Memory adress out of bounds");
		return;
	}

	std::uint8_t high = value >> 8;
	std::uint8_t low = value & 0xFF;

	this->write(high_address, high);
	this->write(high_address + 1, low);
}