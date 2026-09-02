#include <octo/cpu/register.hpp>

void Register16::set(std::uint16_t value) { this->value = value; }

std::uint16_t Register16::get() const { return value; }

void Register16::clear() { value = 0; }

void Register16::increment() { value += 1; }
