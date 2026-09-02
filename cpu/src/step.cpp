#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>

bool CPU::step() {
	auto opcode = static_cast<OpCode>(fetch_byte());

	switch (opcode) {
	case OpCode::LOAD: {
		auto value = fetch_word();

		A.set(value);

		break;
	}

	case OpCode::HALT: {
		return false;
	}

	default:
		return false;
	}

	return true;
}