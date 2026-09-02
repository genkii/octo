#include <cstdint>
#include <format>
#include <octo/cpu/cpu.hpp>
#include <octo_log.h>

std::uint8_t CPU::fetch_byte() {
	std::uint8_t byte = program[PC.get()];
	PC.set(PC.get() + 1);

#ifndef NDEBUG
	log_trace(
		"[CPU]",
		std::format("Fetch byte: {} at PC: {}", byte, PC.get() - 1).c_str());
#endif

	return byte;
}