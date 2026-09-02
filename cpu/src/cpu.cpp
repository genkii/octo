#include <filesystem>
#include <fstream>
#include <octo/cpu/cpu.hpp>
#include <vector>

void CPU::start(std::filesystem::path file) {
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
	this->program = program;
}

CPU::CPU(std::uint8_t adressA, std::uint8_t adressPC)
	: A(adressA), PC(adressPC) {}