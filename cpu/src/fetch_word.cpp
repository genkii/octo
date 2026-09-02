#include <cstdint>
#include <octo/cpu/cpu.hpp>
#include <octo_log.h>

std::uint16_t CPU::fetch_word() {
	auto high_byte = fetch_byte();
	auto low_byte = fetch_byte();

	std::uint16_t value =
		(static_cast<std::uint16_t>(high_byte) << 8) | low_byte;

#ifndef NDEBUG
	log_trace("[CPU]", std::format("Fetch word: {} begins at PC: {}", value,
								   PC.get() - 2)
						   .c_str());
#endif

	return value;
}