#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>
#include <octo_log.h>

bool CPU::step() {
	auto opcode = static_cast<OpCode>(fetch_byte());

	switch (opcode) {
	case OpCode::LOAD: {
		auto adress = fetch_byte();
		auto value = fetch_word();

#ifndef NDEBUG
		log_trace(
			"[CPU]",
			std::format("Fetch LOAD opcode with register adress: {}", adress)
				.c_str());
#endif

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
#ifndef NDEBUG
		log_trace("[CPU]", std::format("Fetch HALT opcode").c_str());
#endif
		return false;
	}

	default:
		return false;
	}

	return true;
}