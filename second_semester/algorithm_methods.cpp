
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

int main() {

    
    std::list<int> nums{2, 764, -345, 7, 0};
    nums.sort([](auto l, auto r){return r < l;});

    for (auto item: nums) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    std::vector<int> sorted_nums{1, 2, 4, 6, 6, 7, 7, 8, 8, 9};

    // first element greater or equal
    auto lb = std::lower_bound(sorted_nums.begin(),
                               sorted_nums.end(), 6);

    std::cout << *lb << std::endl;

    // first element greater
    auto ub = std::upper_bound(sorted_nums.begin(),
                               sorted_nums.end(), 6);
    std::cout << *ub << std::endl;

    std::set<int> nums_set;
    std::copy(sorted_nums.begin(), sorted_nums.end(),
              std::inserter(nums_set, nums_set.begin()));
    std::cout << *nums_set.upper_bound(7) << std::endl;

}

