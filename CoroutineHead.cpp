#pragma once
export module cor;

//!! Placer les import après export module "..."!!!
//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header coroutine
import <coroutine>;
import <optional>;
import <cstdint>;

export
{
    struct ReturnObject;
    class Coroutine
    {
    public:
        Coroutine();
        ~Coroutine() = default;
        void testCor();
        ReturnObject counter(std::coroutine_handle<> *continuation_out);
    };

    // The caller-level type
    struct ReturnObject
    {
        // The coroutine level type
        struct promise_type
        {
            ReturnObject get_return_object() { return {}; }
            std::suspend_never initial_suspend() { return {}; }
            std::suspend_never final_suspend() noexcept { return {}; }
            void return_void() {}
            void unhandled_exception() {}
        };
    };

    struct Awaiter
    {
        std::coroutine_handle<> *hp_;
        constexpr bool await_ready() const noexcept { return false; }
        void await_suspend(std::coroutine_handle<> h) { *hp_ = h; }
        constexpr void await_resume() const noexcept {}
    };


    //Coroutine co_yield (retour de paramètre)
    template<typename T>
    struct Generator
    {
        // Le nom de classe 'Generator' est notre choix et il n'est pas requis pour la coroutine
        // la magie. Le compilateur reconnaît la coroutine par la présence du mot-clé 'co_yield'.
        // Vous pouvez utiliser le nom 'MyGenerator' (ou tout autre nom) à la place tant que vous incluez
        // struct imbriqué promise_type avec la méthode 'MyGenerator get_return_object()'.

        struct promise_type;
        using handle_type = std::coroutine_handle<promise_type>;

        struct promise_type // required
        {
            T value_;
            std::exception_ptr exception_;

            Generator get_return_object()
            {
                return Generator(handle_type::from_promise(*this));
            }
            std::suspend_always initial_suspend() { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }
            void unhandled_exception() { exception_ = std::current_exception(); } // saving
            // exception

            template<std::convertible_to<T> From> // Notion C++20
            std::suspend_always yield_value(From&& from)
            {
                value_ = std::forward<From>(from); // mise en cache du résultat dans  promise
                return {};
            }
            void return_void() {}
        };

        handle_type h_;

        Generator(handle_type h) : h_(h) {}
        ~Generator() { h_.destroy(); }
        explicit operator bool()
        {
            fill(); // La seule façon de savoir de manière fiable si nous avons terminé ou non la coroutine,
                // si une prochaine valeur sera générée ou non (co_yield)
                // dans la coroutine via le getter C++ (opérateur () ci-dessous) doit exécuter/reprendre
                // coroutine jusqu'au prochain point co_yield (ou laissez-le tomber).
                // Ensuite, nous stockons/cachons le résultat dans  promise  pour autoriser le getter (operator() ci-dessous
                // pour le récupérer sans exécuter de coroutine).
            return !h_.done();
        }
        T operator()()
        {
            fill();
            full_ = false; // nous allons sortir du cache précédemment
                // résultat pour rendre  promise  à nouveau vide
            return std::move(h_.promise().value_);
        }

    private:
        bool full_ = false;

        void fill()
        {
            if (!full_)
            {
                h_();
                if (h_.promise().exception_)
                    std::rethrow_exception(h_.promise().exception_);
                // propage l'exception de coroutine dans le contexte appelé

                full_ = true;
            }
        }
    };

    Generator<std::uint64_t> fibonacci_sequence(unsigned n)
    {
        if (n == 0)
            co_return;

        if (n > 94)
            co_return
            // throw std::runtime_error("Too big Fibonacci sequence. Elements would overflow.");

        co_yield 0;

        if (n == 1)
            co_return;

        co_yield 1;

        if (n == 2)
            co_return;

        std::uint64_t a = 0;
        std::uint64_t b = 1;

        for (unsigned i = 2; i < n; ++i)
        {
            std::uint64_t s = a + b;
            co_yield s;
            a = b;
            b = s;
        }
    }
};
/*
 *
 * --Les coroutine doivent utiliser une structure appelée EXACTEMENT
 * "promise_type" définis par le dev.
 * --Les valeurs retours passeront par cette structure.
 * --
 * */
