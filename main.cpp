// #include <concepts>
import <concepts>;
import <iostream>;
import <string>;
import <coroutine>;
import <cstdint>;
import <ranges>;
import <vector>;
import <string>;
import <algorithm>;

//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
// Cette commande semble devoir être exécuté dans le dossier où est compilé le programme
//pour que ce import marche
//Faire de même pour tous les autres includes de la STL

import foo;
import cor;
import mconcept;

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

    // h.destroy();//PLANTE à destroy??
    std::cout << "TEST COROUTINE co_yield\n";

    Generator<std::uint64_t> gen = fibonacci_sequence(10); // max 94 avant le débordement de uint64_t

    for (int j = 0; gen; ++j)
        std::cout << "fib(" << j << ")=" << gen() << '\n';
    //=============================================Range && View

    std::vector<std::string> words
        = { "hello", "world", "c++", "ranges" };
    std::ranges::transform(
        words, words.begin(), [](std::string s) {
            transform(s.begin(), s.end(), s.begin(),
                      [](unsigned char c) {
                          return toupper(c);
                      });
            return s;
        });
    for (std::string word : words) {
        std::cout << word << " \n";
    }
    //=============================================Concept
    TestConcept dd;
    dd.basic();
    //error
    // std::cout << dd.average(1.5f, 1.6f) << std::endl;
    //OK
    std::cout << dd.average(1, 1) << std::endl;

    //error
    // Container<double> qq;
    //OK
    Container<int> cc;
    Goblin mm;
    //error
    // dd.IsBaseFunction(cc);
    //SEGMENT FAULT???
    dd.IsBaseFunction(mm);
    return 0;
}


