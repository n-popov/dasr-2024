#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;

template <typename Iter, typename T>
void accumulate_wrapper(Iter begin, Iter end, T init, T& result) {
    /* bad variant for illustration of race condition
    m.lock();
    result += init;
    m.unlock();

    for (auto it = begin; it != end; it++) {
        m.lock();
        result += *it;
        m.unlock();
    }
    */ 
    auto sum = std::accumulate(begin, end, init);

    m.lock();
    result += sum;
    m.unlock();
}

template <typename Iter, typename T>
T parallel_accumulate_with_one_result_variable(Iter begin, Iter end, T init) {
    auto dist = std::distance(begin, end) / 2;
    auto middle = std::next(begin, dist);

    T result = T(0);
    std::thread other(accumulate_wrapper<Iter, T>,
                begin, middle, init, std::ref(result));
    accumulate_wrapper(middle, end, T(0), result);
    other.join();
    return result;
}

const long long N = 100'000'000;

int main() {
    std::vector<long long> nums(N);
    for (auto i = 0; i < N; i++) {
        nums[i] = 1;
    }

    long long res = parallel_accumulate_with_one_result_variable(nums.begin(), nums.end(), 0ll);
    std::cout << res << std::endl;
}
