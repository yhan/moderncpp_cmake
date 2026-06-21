#pragma once

class MyTest
{
public:
    int m_Val{10};

    MyTest() = default;

    explicit MyTest(int x) : m_Val{x}
    {
    }
};
