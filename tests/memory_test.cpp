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

TEST(Memory, ReadWord) {
	Memory memory;

	memory.write(0x1000, 0x12);
	memory.write(0x1001, 0x34);

	EXPECT_EQ(memory.read_word(0x1000), 0x1234);
}

TEST(Memory, WriteWord) {
	Memory memory;

	memory.write_word(0x1000, 0x1234);

	EXPECT_EQ(memory.read(0x1000), 0x12);
	EXPECT_EQ(memory.read(0x1001), 0x34);
}

TEST(Memory, ReadWordOutOfBounds) {
	Memory memory;

	EXPECT_EQ(memory.read_word(0xFFFF), 0);
}

TEST(Memory, WriteWordOutOfBounds) {
	Memory memory;

	memory.write_word(0xFFFF, 0x1234);

	EXPECT_EQ(memory.read(0xFFFF), 0);
}
