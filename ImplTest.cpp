module;

//g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
import <iostream>;

module foo;


Gege::Gege() = default;
Gege::~Gege() = default;
void Gege::helloworld() { std::cout << "hello world\n"; }
