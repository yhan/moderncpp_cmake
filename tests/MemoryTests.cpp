#include <gtest/gtest.h>
#include "MyTest.h"  // provided via the modern_cpp_lib include directory
#include "TestLinker.h"

TEST(UnderstandMemory, copy_array) {
    int *data = hello();
    ASSERT_NE(data, nullptr);
    for (int i = 0; i < 5; ++i) {
        if (i < 3) {
            EXPECT_EQ(data[i], i + 1); // Expect 1, 2, 3 for the first three elements
        } else {
            //EXPECT_EQ(data[i], 0);      // Expect 0 for the remaining elements
        }
    }
    delete[] data;
}

TEST(UnderstandMemory, reference) {
    int a = 42;

    int copy = a; // copy:    independent, changing copy doesn't affect a
    int *ptr = &a; // pointer: holds address, must dereference with *ptr to use
    int &ref = a; // reference: alias, used exactly like a, no dereferencing needed

    copy = 99; // a unchanged
    *ptr = 99; // a = 99  ===> act on *ptr, does not assign address, but assign value
    ref = 99; // a = 99
    /**
     *
    * int* ptr = &a;     Declaration — * means "ptr is a pointer type"
*ptr = 99;               Dereference — * means "go to the address and act on the value there"
*/
}

TEST(UnderstandMemory, reference_pointer) {
    int a = 42;
    int *ptr = &a; // ptr  = the ADDRESS of a  (e.g. 0x1234)
    // *ptr = the VALUE at that address = 42

    int b = 0;
    ptr = &b; // ? reassign pointer to point at b instead of a (ptr now holds address of b)
    *ptr = 99; // ? go to the address ptr holds (b), write 99 there ? b = 99, a unchanged

    ptr = reinterpret_cast<int*>(0x1234); // force ptr to point at address 0x1234
}
