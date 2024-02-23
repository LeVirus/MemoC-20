export module mconcept;
import <concepts>;
import <iostream>;

export
{
    //Créer notre propre concept
    //A mettre en dehors des classes/structures
    template <typename T>
    concept Integer = std::integral<T> || std::floating_point<T>;

    //On peut également ajouter comme une fonction pour définir notre concept
    template <typename T>
    concept Averagable =
        requires(T x, T y) {
            (x + y) / 2;
    };

    class Object{};
    //Cumul de 2 conditions "&&"
    //Vérifie si l'objet derriere le template possede les méthode Render et hasRendered
    template <typename T>
    concept Renderable =
        std::derived_from<T, Object> &&
        requires(T Object){
            Object.Render();
            Object.hasRendered;
    };

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

        /*
         * Il est possible de positionner le requires après la définition de la fontion/méthode
        */
        template <typename T>
        T DAverage(T x, T y)
            requires std::integral<T>
        {
            return (x + y) / 2;
        }

        /*
         * Possibilité d'utiliser des auto comme usage des concepts
        */
        auto AutooAverage(auto x, auto y) {
            return (x + y) / 2;
        }
        auto AutoAverage(std::integral auto x,
                     std::integral auto y) {
            return (x + y) / 2;
        }

        /*
        * Combinaison des concepts fifférents
        */
        template <std::integral TFirst, typename TSecond>
            requires std::integral<TSecond> ||
                     std::floating_point<TSecond>
        void Function(TFirst x, TSecond y){}


        //Utiliser de notre template déclarer en haut du fichier
        template <Integer T>
        T CREATE_Average(T x, T y) {
            return (x + y) / 2;
        }

        //Utiliser de notre template déclarer en haut du fichier
        template <Averagable T>
        T averageableTest(T a, T b)
        {
            return (a + b) / 2;
        }
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
