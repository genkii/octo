#include <array>
#include <gtest/gtest.h>
#include <octo/memory/memory.hpp>

TEST(Memory, Read) {
	Memory memory;

	EXPECT_EQ(memory.read(0), 0);
}

TEST(Memory, Write) {
	Memory memory;

	memory.write(0, 42);

	EXPECT_EQ(memory.read(0), 42);
}

TEST(Memory, SetMemory) {
	Memory memory;
	std::array<std::uint8_t, 65536> memory_local{};

	memory_local[0] = 3;

	memory.set_memory(memory_local);

	EXPECT_EQ(memory.read(0), 3);
}