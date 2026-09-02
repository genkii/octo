#include "register.hpp"
#include <filesystem>
#include <octo/memory/memory.hpp>
#include <vector>

class CPU {
private:
	Register16 PC;

	Register16 A;

	Register16 B;

	std::vector<std::uint8_t> program;

	Memory memory;

public:
	CPU(std::uint8_t addressA, std::uint8_t addressPC, std::uint8_t addressB);

	std::uint16_t get_a() const;

	void start(std::filesystem::path file);

	void set_program(std::vector<std::uint8_t> program);

	std::uint8_t fetch_byte();

	std::uint16_t fetch_word();

	std::uint16_t get_pc();

	void write_memory_word(std::uint16_t address, std::uint16_t value);

	std::uint16_t read_memory_word(std::uint16_t address);

	bool step();
};
