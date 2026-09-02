#include <gtest/gtest.h>
#include <octo/cpu/register.hpp>

TEST(Register16, CanSetAndGetValue) {
	Register16 reg;

	reg.set(42);

	EXPECT_EQ(reg.get(), 42);
}

TEST(Register16, CanSetAndClearValue) {
	Register16 reg;
	reg.set(21);

	EXPECT_EQ(reg.get(), 21);

	reg.clear();

	EXPECT_EQ(reg.get(), 0);
}

TEST(Register16, CanIncrementValue) {
	Register16 reg;

	reg.increment();

	EXPECT_EQ(reg.get(), 1);
}
