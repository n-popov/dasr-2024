#pragma once

#include <chrono>
#include <iostream>

class Timer {
public:
    Timer(std::ostream&);

    ~Timer();

private:
    std::ostream& out;
    std::chrono::steady_clock::time_point start;
};
