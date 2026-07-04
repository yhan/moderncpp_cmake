#include <gtest/gtest.h>
#include "MyTest.h"  // provided via the modern_cpp_lib include directory

// Forward declarations - definitions compiled into modern_cpp_lib
int* hello();
void hello_hello();

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

TEST(TestLinkerTests, copy_array) {
    int* data = hello();
    ASSERT_NE(data, nullptr);
    for (int i = 0; i < 5; ++i) {
        if (i < 3) {
            EXPECT_EQ(data[i], i + 1);  // Expect 1, 2, 3 for the first three elements
        } else {
            //EXPECT_EQ(data[i], 0);      // Expect 0 for the remaining elements
        }
    }
    delete[] data;
}

TEST(TestLinkerWrapperTests, test_wrapper) {
    hello_hello();
}

TEST(IncrementTest, plusplus) {
    int i = 42;
    int a = i++;
    ASSERT_EQ(a, 42);
}

// gtest_main provides main(); no need to define it here.
