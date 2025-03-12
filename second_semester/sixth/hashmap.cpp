
#include <iostream>
#include <functional>
#include <vector>
#include <string>

/*
std::pair

template <typename FirstType, typename SecondType>
struct Pair {
    FirstType first;
    SecondType second;
};
*/

template <typename K, typename V>
class HashMap {
public:
    HashMap(std::function<unsigned(K)> hash):
        hash(hash) {
        data = new std::pair<K, V>[capacity];
    }

    void add(K key, V value) {
        if (size == capacity) {
            auto new_capacity = 2 * capacity;
            auto new_data = new std::pair<K, V>[new_capacity];
            for (auto i = 0u; i < size; i++) {
                auto new_index = hash(data[i].first) % (new_capacity);
                new_data[new_index] = data[i];
            }
            delete[] data;
            capacity = new_capacity;
            data = new_data;
        }
        auto index = hash(key) % capacity;
        data[index] = std::pair(key, value);
    }

    V& operator[](K key) {
        auto index = hash(key) % capacity;

        return data[index].second;
    }


private:
    std::function<unsigned(K)> hash = [](K key){
        return std::size(key);
    };
    std::pair<K, V>* data;
    unsigned size = 0u, capacity = 1000u;
};

unsigned hash_wrapper(std::string value) {
    return std::hash<std::string>()(value);
}

int main() {
    HashMap<std::string, int> hash_map(hash_wrapper);

    hash_map.add("abc", 123);
    hash_map.add("xyz", 42);

    std::cout << hash_map["abc"] << std::endl;
    std::cout << hash_map["xyz"] << std::endl;
    hash_map["xyz"] = 255;
    std::cout << hash_map["xyz"] << std::endl;
}

