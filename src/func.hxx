#ifndef _FUNC_HXX_
#define _FUNC_HXX_
#include <print/print.hxx>
void sumExample()
{
    int a{}, b{}, c{};
    Core::input(a, "A:");
    Core::input(b, "B:");
    c = a + b;
    Core::print("A+B:", c);
};

#endif