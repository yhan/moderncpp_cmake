#include <iostream>
int g_Var1; // global goes to data segment
int g_Var2 = 10;

void increment(int arg)
{
    int cpy; // local
    cpy = arg; // local  goes to stack
    static int counter = 0; // static goes to data segment
    counter += arg;
    std::cout << counter << '\n';
}

int main(int argc, char* argv[])
{
    float PI = 3.14f;
    return 0;
}
