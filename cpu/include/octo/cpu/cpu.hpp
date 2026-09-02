#include "register.hpp"
#include <filesystem>
#include <vector>

class CPU {
private:
	Register16 PC;

	Register16 A;

	std::vector<std::uint8_t> program;

public:
	std::uint16_t get_a() const;

	void start(std::filesystem::path file);

	void set_program(std::vector<std::uint8_t> program);

	std::uint8_t fetch_byte();

	std::uint16_t fetch_word();

	std::uint16_t get_pc();

	bool step();
};
