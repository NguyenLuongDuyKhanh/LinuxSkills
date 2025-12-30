// src/main.cpp
#include <iostream>
#include <chaiscript/chaiscript.hpp>

// a simple C++ function we'll expose to scripts
int add(int a, int b) {
    std::cout << "This is add() function in C++ code main.cpp" << std::endl;
    return a + b;
}

int mul(int a, int b) {
    std::cout << "This is mul() function in C++ code main.cpp" << std::endl;
    return a * b;
}

int main() {
    try {
        chaiscript::ChaiScript chai;              // create engine
        chai.add(chaiscript::fun(&add), "add");  // register C++ func as 'add'
        chai.add(chaiscript::fun(&mul), "mul_function_interfacar");  // register C++ func as 'add'

        // run a script file
        chai.eval_file("scripts/hello.chai");
        
    } catch (const chaiscript::exception::eval_error &e) {
        std::cerr << "ChaiScript error: " << e.pretty_print() << std::endl;
        return 1;
    }
    return 0;
}
