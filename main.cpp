// #include <concepts>
import <concepts>;
import <iostream>;
import <string>;
//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
//pour que ce import marche
//Faire de même pour tous les autres includes de la STL

import foo;
import Coroutine;

int main()
{
    //Module
    Gege gege;
    gege.helloworld();
    std::cout << "Hello World! MAIN" << std::endl;
    //Coroutine
    Coroutine c;
    c.testCor();
    return 0;
}


