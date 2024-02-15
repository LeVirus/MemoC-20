module;
//les import doivent être impérativement positionné aprés le "module;"
import <iostream>;
module cor;

//=========================================================
Coroutine::Coroutine() = default;

//=========================================================
void Coroutine::testCor()
{
    std::cerr << "Debut Coroutine\n";
}

//=========================================================
ReturnObject Coroutine::counter(std::coroutine_handle<> *continuation_out)
{
    Awaiter a{continuation_out};
    for (unsigned i = 0;; ++i)
    {
        co_await a;
        std::cout << "counter: " << i << std::endl;
    }
}
