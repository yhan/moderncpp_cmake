#include <gtest/gtest.h>
#include "GArray.h"

TEST(GArrayTest, ctor) {
    basics::GArray<int> arr;
    EXPECT_EQ(arr.get_capacity(), 8);
    EXPECT_EQ(arr.get_size(), 0);
}