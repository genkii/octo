#include <filesystem>
#include <fstream>
#include <octo/cpu/cpu.hpp>
#include <vector>

void CPU::start(std::filesystem::path file) {
	PC = Register16{};
	A = Register16{};

	std::ifstream stream(file, std::ios::binary);

	program.resize(std::filesystem::file_size(file));

	stream.read(reinterpret_cast<char *>(program.data()), program.size());

	while (true) {
		auto running = step();

		if (!running) {
			break;
		}
	}
}

std::uint16_t CPU::get_a() const { return A.get(); }

std::uint16_t CPU::get_pc() { return PC.get(); }

void CPU::set_program(std::vector<std::uint8_t> program) {
	PC = Register16{};
	A = Register16{};

	this->program = program;
}