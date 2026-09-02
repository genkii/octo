#include <cstdint>
#include <octo/cpu/cpu.hpp>

std::uint8_t CPU::fetch_byte() {
	std::uint8_t byte = program[PC.get()];
	PC.set(PC.get() + 1);

	return byte;
}