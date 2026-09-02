#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>
#include <octo_log.h>

bool CPU::step() {
	auto opcode = static_cast<OpCode>(fetch_byte());

	switch (opcode) {

	case OpCode::LOAD: {
		auto register_id = fetch_byte();
		auto value = fetch_word();

#ifndef NDEBUG
		log_trace("[CPU]",
				  std::format("Fetch LOAD opcode with register address: {}",
							  register_id)
					  .c_str());
#endif

		switch (register_id) {
		case 0b00000000:
			A.set(value);
			break;

		case 0b00000001:
			PC.set(value);
			break;

		case 0b00000010:
			B.set(value);
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

	case OpCode::STORE: {
		auto register_id = fetch_byte();
		auto memory_address = fetch_word();

		std::uint16_t value;

		switch (register_id) {
		case 0b00000000:
			value = A.get();
			break;

		case 0b00000001:
			value = PC.get();
			break;

		case 0b00000010:
			value = B.get();
			break;

		default:
			return false;
		}

		memory.write_word(memory_address, value);

		break;
	}

	case OpCode::LOADM: {
		auto register_id = fetch_byte();
		auto memory_adress = fetch_word();

		std::uint16_t value = memory.read_word(memory_adress);

		switch (register_id) {
		case 0b00000000:
			A.set(value);
			break;

		case 0b00000001:
			PC.set(value);
			break;

		case 0b00000010:
			B.set(value);
			break;

		default:
			return false;
		}

		break;
	}

	default:
		return false;
	}

	return true;
}