/*
Ввод:

7
sensor1 80
sensor2 35
sensor1 -4
sensor1 8
sensor2 -1
sensor2 15
sensor2 80
3
sensor1
sensor2
sensor3
Вывод:

8
15
no data
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::unordered_map<std::string, std::vector<int>> data;

    std::string sensor;
    int value, amount;
    std::cin >> amount;
    for (auto i = 0; i < amount; i++) {
        std::cin >> sensor >> value;
        data[sensor].push_back(value);
    }

    std::cin >> amount;
    for (auto i = 0; i < amount; i++) {
        std::cin >> sensor;

        if (data.count(sensor)) {
            auto& values = data[sensor]; // std::vector<int>
            auto median_index = (values.size() + 1) / 2 - 1;
            auto median_iterator = values.begin() + median_index;
            std::nth_element(values.begin(),
                median_iterator, values.end());
            std::cout << values[median_index] << std::endl;
        } else {
            std::cout << "no data" << std::endl;
        }
    }






}
