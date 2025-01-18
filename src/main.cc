
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <listconfig.h>
#include <print/print.hxx>
#include <func.hxx>

int main(int argc, char *argv[])
{
    char first[256];
    char last[256];
    char about[1024];

    Core::input(first, "Enter Your first name : ");
    Core::input(last, "Enter your last name : ");

    Core::input(about, "Something about you in one line : ");

    Core::print("Info you provided:\n");

    Core::print(first);
    Core::print(last);
    Core::print(about);
    return 0;
};
