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
/* La méthode sera exécuter jusqu'au "co_await" à
 * l'appel "[coroutine_handler].counter(...)" (voir dans le main)
co_await redonne la main à l'apelant (après avoir été préalablement appelé
via le "coroutine_handler")
On NE PEUT PAS utiliser de return dans une coroutine
Interactions coroutine::
co_await == repasse la main à l'appelant
co_yield == retourne une valeur, sauvegarde l'état et repasse la main à l'appelant
            L'appelant récupère la valeur via "[coroutine_handler].next()"
co_return == retourne une valeur, abandonne l'état et repasse la main à l'appelant
*/
ReturnObject Coroutine::counter(std::coroutine_handle<> *continuation_out)
{
    Awaiter a{continuation_out};
    for (unsigned i = 0; i < 3; ++i)
    {
        std::cout << "Acounter: " << i << std::endl;
        co_await a;
        std::cout << "counter: " << i << std::endl;
    }
    // co_yield "A";
    // co_yield "C";
    // co_yield "B";
}
/*Si la fin de la coroutine est atteinte par la pile d'exécution un co_return
 * est automatiquement appelé par le compilateur*/
