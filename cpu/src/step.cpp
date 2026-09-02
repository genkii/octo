#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>

bool CPU::step() {
	auto opcode = static_cast<OpCode>(fetch_byte());

	switch (opcode) {
	case OpCode::LOAD: {
		auto adress = fetch_byte();
		auto value = fetch_word();

		switch (adress) {
		case 0b00000000:
			A.set(value);
			break;

		case 0b00000001:
			PC.set(value);
			break;

		default:
			return false;
		}

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