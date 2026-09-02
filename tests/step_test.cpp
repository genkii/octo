#include <gtest/gtest.h>
#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>
#include <vector>

TEST(CPU, StepLoad) {
	CPU cpu = CPU(0b00000000, 0b00000001);
	std::vector<std::uint8_t> program = {
		static_cast<std::uint8_t>(OpCode::LOAD), 0b00000000, 0x12, 0x34};

	cpu.set_program(program);

	EXPECT_TRUE(cpu.step());

	EXPECT_EQ(cpu.get_a(), 0x1234);
	EXPECT_EQ(cpu.get_pc(), 4);
}

TEST(CPU, StepHalt) {
	CPU cpu = CPU(0b00000000, 0b00000001);
	std::vector<std::uint8_t> program = {
		static_cast<std::uint8_t>(OpCode::HALT)};

	cpu.set_program(program);

	EXPECT_FALSE(cpu.step());

	EXPECT_EQ(cpu.get_pc(), 1);
}

TEST(CPU, StepUnknownOpcode) {
	CPU cpu = CPU(0b00000000, 0b00000001);
	std::vector<std::uint8_t> program = {0xFF};

	cpu.set_program(program);

	EXPECT_FALSE(cpu.step());

	EXPECT_EQ(cpu.get_pc(), 1);
}