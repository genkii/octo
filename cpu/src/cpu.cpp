#include <filesystem>
#include <fstream>
#include <octo/cpu/cpu.hpp>
#include <octo_log.h>
#include <vector>

void CPU::start(std::filesystem::path file) {

	log_info("[CPU]", "Read binary file from disk");
	std::ifstream stream(file, std::ios::binary);

	log_trace("[CPU]", "Resize program vector to match filesize");
	program.resize(std::filesystem::file_size(file));

	log_trace("[CPU]", "Write bytes into program vector");
	stream.read(reinterpret_cast<char *>(program.data()), program.size());

	log_trace("[CPU]", "Begin CPU steps");
	while (true) {

#ifndef NDEBUG
		log_trace("[CPU]", "CPU step");
#endif

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