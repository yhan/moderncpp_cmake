#include <gtest/gtest.h>
#include "MyTest.h"  // provided via the modern_cpp_lib include directory

TEST(TestClass, DefaultInitialization) {
    MyTest t{};
    EXPECT_EQ(t.m_Val, 10);
}

TEST(TestClass, ParameterizedInit) {
    MyTest t{42};
    EXPECT_EQ(t.m_Val, 42);
}

TEST(Ploof, declare_pointer) {
    int i = 42;
    int* p = &i;

    int j = 42;
    int* p2 = &j;

    EXPECT_EQ(*p, 42);
    EXPECT_EQ(*p2, 42);
    EXPECT_TRUE(*p == *p2);
}

TEST(arrayTest, array_assign) {
    int arr[3];
    arr[2] = 42;
    EXPECT_EQ(arr[2], 42);
}

// gtest_main provides main(); no need to define it here.
