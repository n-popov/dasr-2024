#include "timer.hpp"

Timer::Timer(std::ostream& out): out(out), start(std::chrono::steady_clock::now()) {}

Timer::~Timer() {
    auto end = std::chrono::steady_clock::now();

    out << "Elapsed time: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count() << std::endl;
}


