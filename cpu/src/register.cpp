#include <format>
#include <octo/cpu/register.hpp>
#include <octo_log.h>

void Register16::set(std::uint16_t value) { this->value = value; }

std::uint16_t Register16::get() const { return value; }

void Register16::clear() { value = 0; }

void Register16::increment() { value += 1; }

Register16::Register16(std::uint8_t adress) : adress(adress), value(0) {
	log_info("[Register]",
			 std::format("Created register with adress: {}", adress).c_str());
}