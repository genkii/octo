#include <cstdint>

class Register16 {
private:
	std::uint16_t value;

	std::uint8_t adress;

public:
	std::uint16_t get() const;

	void set(std::uint16_t value);

	void clear();

	void increment();

	Register16(std::uint8_t adress);
};
