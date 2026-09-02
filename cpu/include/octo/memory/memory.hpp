#include <array>
#include <cstdint>

class Memory {
private:
	std::array<std::uint8_t, 65536> memory{};

public:
	void write(std::uint16_t address, std::uint8_t value);

	std::uint8_t read(std::uint16_t address);

	void set_memory(std::array<std::uint8_t, 65536> memory);
};
