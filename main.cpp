// #include <concepts>
import <concepts>;
import <iostream>;
import <string>;
import <coroutine>;
//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
//pour que ce import marche
//Faire de même pour tous les autres includes de la STL

import foo;
import cor;

int main()
{
    //Module
    Gege gege;
    gege.helloworld();
    std::cout << "Hello World! MAIN" << std::endl;
    //Coroutine
    Coroutine c;
    // c.testCor();
    std::coroutine_handle<> h;
    c.counter(&h);
    for (int i = 0; i < 3; ++i) {
        std::cout << "In main1 function\n";
        h();
    }
    h.destroy();
    return 0;
}


