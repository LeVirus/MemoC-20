#pragma once
export module cor;

//!! Placer les import après export module "..."!!!
import <coroutine>;


export class Coroutine
{
public:
    Coroutine();
    ~Coroutine() = default;
    void testCor();
};

// The caller-level type
export struct Task {
    // The coroutine level type
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};

/*
 *
 * --Les coroutine doivent utiliser une structure appelée EXACTEMENT
 * "promise_type" définis par le dev.
 * --Les valeurs retours passeront par cette structure.
 * --
 * */
