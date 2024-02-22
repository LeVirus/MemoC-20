export module mconcept;
import <concepts>;
import <iostream>;

export
{
    template <std::integral T>
    class Container
    {
        T Contents;
    };

    class Player {};
    class Monster {};
    class Goblin : public Monster {};


    class TestConcept
    {
    public:
        TestConcept();
        ~TestConcept() = default;
        void basic();
        //CONCEPT DIRECT
        template <std::integral T>
        T average(T x, T y)
        {
            return (x + y) / 2;
        }

        //REQUIRES
        //Peut utiliser les opérateurs || et &&
        template <typename T>
            requires std::integral<T> ||
                     std::floating_point<T>
        T ReqAverage(T x, T y) {
            std::cout << "Using integral function\n";
            return (x + y) / 2;
        }

        //utilisation de is_base_of_v first ==> base second type to test.
        // on peut utiliser std::derived_from ou std::base_of comme équivalent
        template <typename T>
            requires std::is_base_of_v<Player, T> ||
                     std::is_base_of_v<Monster, T>
        void IsBaseFunction(T Character) {}
    };
}
/**
 * Les concepts permettent d'ajouter des contraintes au template
 * Il existe des concept préexistant dans le standard
 *
 * Il existe 4 manière différentes d'utiliser les concepts
 *
 * 1- Contraintes de template
 * 2- mot clé "requires"
 */
