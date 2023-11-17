#pragma once
#include <iostream>

class Subject {
public:
    int f(int arg1) {
        std::cout << "args: arg1 = " << arg1 << std::endl;
        return arg1;
    }
    int f1(int arg1, int arg2) {
        std::cout << "args: arg1 = " << arg1 << "  arg2 = " << arg2 << std::endl;
        return arg1 - arg2;
    }
    int f2(int arg1, int arg2) {
        std::cout << "args: arg1 = " << arg1 << "  arg2 = " << arg2 << std::endl;
        return arg1 * arg2;
    }
    int f3(int arg1, int arg2) {
        std::cout << "args: arg1 = " << arg1 << "  arg2 = " << arg2 << std::endl;
        return arg1 + arg2;
    }
    int fu3(int arg1, int arg2, int arg3) {
        std::cout << "args: arg1 = " << arg1 << "  arg2 = " << arg2 << "  arg3 = " << arg3 << std::endl;
        return arg1 + arg2 + arg3;
    }
};