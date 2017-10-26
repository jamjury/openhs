#include "gtest/gtest.h"
#include "library.h"

TEST(basic_check, eq) {
    EXPECT_EQ(1, A::one());
}