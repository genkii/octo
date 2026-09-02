#include "register.hpp"
#include <filesystem>;
#include <vector>;

class CPU {
private:
	Register16 A;

	Register16 PC;

	std::vector<std::uint8_t> program;

	bool step();

	std::uint8_t fetch_byte();

	std::uint16_t fetch_word();

public:
	CPU(/* args */);
	~CPU();

	void start(std::filesystem::path file);
};
