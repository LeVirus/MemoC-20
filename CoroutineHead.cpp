#pragma once
export module cor;

//!! Placer les import après export module "..."!!!
//Lancer g++ -std=c++20 -fmodules-ts -xc++-system-header coroutine
import <coroutine>;

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
};
/*
 *
 * --Les coroutine doivent utiliser une structure appelée EXACTEMENT
 * "promise_type" définis par le dev.
 * --Les valeurs retours passeront par cette structure.
 * --
 * */
