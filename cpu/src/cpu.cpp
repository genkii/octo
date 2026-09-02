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