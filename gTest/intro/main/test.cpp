#include <gtest/gtest.h>
#include "LibraryCode.hpp"

TEST(SumTest, PositiveNumbers) {
    int a = 3;
    int b = 4;
    int expected = 7;
    EXPECT_EQ(sum(a, b), expected);
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}