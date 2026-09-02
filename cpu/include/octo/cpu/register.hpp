#include <cstdint>

class Register16 {
private:
	std::uint16_t value;

public:
	std::uint16_t get();

	void set(std::uint16_t value);

	void clear();

	void increment();
};
