// #include <concepts>
import <concepts>;
import <iostream>;
import <string>;
import <coroutine>;
import <cstdint>;

//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
// Cette commande semble devoir être exécuté dans le dossier où est compilé le programme
//pour que ce import marche
//Faire de même pour tous les autres includes de la STL

import foo;
import cor;

int main()
{
    //==============================================Module
    Gege gege;
    gege.helloworld();
    std::cout << "Hello World! MAIN" << std::endl;

    //=============================================Coroutine
    Coroutine c;
    // c.testCor();

    std::coroutine_handle<> h;
    std::cout << "TEST COROUTINE co_await\n";

    c.counter(&h);
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "In main1 function\n";
        h();
    }

    // std::cout << next();
    // h.destroy();//PLANTE à destroy??
    std::cout << "TEST COROUTINE co_yield\n";

    Generator<std::uint64_t> gen = fibonacci_sequence(10); // max 94 avant le débordement de uint64_t

    for (int j = 0; gen; ++j)
        std::cout << "fib(" << j << ")=" << gen() << '\n';
    return 0;
}


