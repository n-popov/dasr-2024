#include <map>

vector<int> twoSum(vector<int>& nums, int target) {
    std::map<int, int> not_enough_for_idx;
    for (auto i = 0; i < nums.size(); i++) {
        not_enough_for_idx[target - nums[i]] = i;
    }

    for (auto i = 0; i < nums.size(); i++) {
        if (not_enough_for_idx.count(nums[i]) &&
            i != not_enough_for_idx[nums[i]]) {
            return {i, not_enough_for_idx[nums[i]]};
        }
    }
    return {};
}

int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    auto result = twoSum(nums, target);
    if (result.size() == 2) {
        std::cout << result[0] << ' ' << result[1] << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}


