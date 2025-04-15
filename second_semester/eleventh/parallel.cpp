#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <thread>

const int N = 100'000'000;

class Timer {
public:
    Timer(): start(std::chrono::steady_clock::now()) {}

    ~Timer() {
        std::cout <<
            (std::chrono::steady_clock::now() - start).count()
            << std::endl;
    }

private:
    std::chrono::steady_clock::time_point start;
};

template <typename Iter, typename T>
void accumulate_wrapper(Iter begin, Iter end, T init, T& result) {
    result = std::accumulate(begin, end, init);
}

template <typename Iter, typename T>
T parallel_accumulate_simple_with_thread(Iter begin, Iter end, T init) {
    auto dist = std::distance(begin, end) / 2;
    auto middle = std::next(begin, dist);

    T first_part;
    std::thread other(accumulate_wrapper<Iter, T>,
                begin, middle, init, std::ref(first_part));
    auto second_part = std::accumulate(middle, end, T(0));
    other.join();
    return first_part + second_part;
}

template <typename Iter, typename T>
T parallel_accumulate_simple_with_future(Iter begin, Iter end, T init) {
    auto dist = std::distance(begin, end) / 2;
    auto middle = std::next(begin, dist);

    auto future = std::async(
        std::launch::async, std::accumulate<Iter, T>,
        begin, middle, T(0));

    return std::accumulate(middle, end, init) + future.get();
}

template <typename Iter, typename T>
T parallel_accumulate(Iter begin, Iter end, T init) {
    auto num_threads = std::thread::hardware_concurrency();
    auto batch_size = std::distance(begin, end) / num_threads;

    std::vector<std::thread> threads;
    std::vector<T> results(num_threads);

    for(auto i = 0; i + 1 < num_threads; i++) {
        threads.push_back(std::thread(
            accumulate_wrapper<Iter, T>,
            std::next(begin, i * batch_size),
            std::next(begin, (i + 1) * batch_size),
            T(0),
            std::ref(results[i])));
    }

    results[results.size() - 1u] = std::accumulate(
        std::next(begin, (num_threads - 1) * batch_size),
        end, T(0));

    for (auto i = 0; i + 1 < num_threads; i++) {
        threads[i].join();
    }

    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    std::cout << "Amount of supported threads: " <<
        std::thread::hardware_concurrency() << std::endl;

    std::vector<long long> nums(N);
    std::iota(nums.begin(), nums.end(), 1ll);

    long long res;
    {
        Timer t;
        res = std::accumulate(nums.begin(), nums.end(), 0ll);
    }
    std::cout << res << std::endl;

    {
        Timer t;
        res = parallel_accumulate(nums.begin(), nums.end(), 0ll);
    }
    std::cout << res << std::endl;
}
