#include <array>
#include <cstdint>

class Memory {
private:
	std::array<std::uint8_t, 65536> memory{};

public:
	void write(std::uint16_t address, std::uint8_t value);

	std::uint8_t read(std::uint16_t address);

	void set_memory(std::array<std::uint8_t, 65536> memory);

	std::uint16_t read_word(std::uint16_t high_address);

	void write_word(std::uint16_t high_address, std::uint16_t value);
};
