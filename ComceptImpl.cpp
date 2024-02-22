module;

import <iostream>;

module mconcept;

//=================================================
TestConcept::TestConcept()
{
    if(std::is_base_of_v<TestConcept, Player> == true)std::cerr << "SDFF\n";
    else std::cerr << "KAPOU222\n";
}

//=================================================
void TestConcept::basic()
{
    //test si <int> est un "integral"
    if constexpr(std::integral<int>)
    {
        std::cout << "int is an integral\n";
    }
    if constexpr(!std::integral<float>)
    {
        std::cout << "float isn't\n";
    }
}
