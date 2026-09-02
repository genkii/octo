#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>
#include <vector>

TEST(CPU, FetchByteAndPC) {
	CPU cpu = CPU(0b00000000, 0b00000001);
	std::vector<std::uint8_t> program = {12};

	cpu.set_program(program);

	EXPECT_EQ(cpu.fetch_byte(), 12);

	EXPECT_EQ(cpu.get_pc(), 1);
}

TEST(CPU, FetchWordAndPC) {
	CPU cpu = CPU(0b00000000, 0b00000001);
	std::vector<std::uint8_t> program = {0x12, 0x34};

	cpu.set_program(program);

	EXPECT_EQ(cpu.fetch_word(), 0x1234);

	EXPECT_EQ(cpu.get_pc(), 2);
}

TEST(CPU, Start) {
	CPU cpu = CPU(0b00000000, 0b00000001);

	auto file = std::filesystem::temp_directory_path() / "octo_test.bin";

	std::vector<std::uint8_t> program = {
		static_cast<std::uint8_t>(OpCode::LOAD), 0b00000000, 0x12, 0x34,
		static_cast<std::uint8_t>(OpCode::HALT)};

	{
		std::ofstream stream(file, std::ios::binary);
		stream.write(reinterpret_cast<const char *>(program.data()),
					 program.size());
	}

	cpu.start(file);

	EXPECT_EQ(cpu.get_a(), 0x1234);
	EXPECT_EQ(cpu.get_pc(), 5);

	std::filesystem::remove(file);
}