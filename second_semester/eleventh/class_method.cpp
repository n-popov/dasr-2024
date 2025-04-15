

#include <thread>
#include <future>
#include <vector>
#include <iostream>
#include <numeric>

struct Student {
    double get_mean() {
        return std::accumulate(std::begin(marks),
            std::end(marks), 0.) / std::size(marks);
    }

    std::vector<int> marks;
};

int main() {
    Student s;
    s.marks = {8, 10, 10, 8, 10, 10, 8, 8};

    auto mean_promise = std::async(std::launch::async,
        &Student::get_mean, &s);

    std::cout << "Mean mark: " << mean_promise.get() << std::endl;
}
