#include <gtest/gtest.h>
#include <octo/cpu/cpu.hpp>
#include <octo/opc/op_code.hpp>
#include <vector>

TEST(CPU, StepLoad) {
	CPU cpu = CPU{};
	std::vector<std::uint8_t> program = {
		static_cast<std::uint8_t>(OpCode::LOAD), 0x12, 0x34};

	cpu.set_program(program);

	EXPECT_TRUE(cpu.step());

	EXPECT_EQ(cpu.get_a(), 0x1234);
	EXPECT_EQ(cpu.get_pc(), 3);
}

TEST(CPU, StepHalt) {
	CPU cpu = CPU{};
	std::vector<std::uint8_t> program = {
		static_cast<std::uint8_t>(OpCode::HALT)};

	cpu.set_program(program);

	EXPECT_FALSE(cpu.step());

	EXPECT_EQ(cpu.get_pc(), 1);
}

TEST(CPU, StepUnknownOpcode) {
	CPU cpu = CPU{};
	std::vector<std::uint8_t> program = {0xFF};

	cpu.set_program(program);

	EXPECT_FALSE(cpu.step());

	EXPECT_EQ(cpu.get_pc(), 1);
}