/*Слова
Считайте со стандартного потока ввода множество слов. После этого:

устраните дубли, каждое слово должно встречаться строго один раз;
выведите все уникальные слова в стандартный поток вывода, отсортировав по длине 
Если попадаются слова одинаковой длины, их взаимный порядок может быть любым.

Формат ввода
В первой строке целое число N - количество слов.

Далее N строк, каждая содержит строго одно слово. Словом считается последовательность символов, которая может включать только малые и большие буквы латинского алфавита.

Формат вывода
X строк, в каждой строке одно уникальное слово, слова отсортированы от коротких к длинным.

Пример ввода и вывода
Ввод:

5
foo
qwerty
aabb
qwerty
X
Вывод:

qwerty
aabb
foo
X
*/

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>



int main() {
    int n;
    std::cin >> n;

    std::set<std::string> unique_words;

    for (auto i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        unique_words.insert(word);
    }

    std::map<unsigned, std::vector<std::string>> len_to_words;
    for (const auto& word: unique_words) {
        len_to_words[word.size()].push_back(word);
    }

    for(const auto& item: len_to_words) {
        // item - это пара ключ-значение
        // item.first ключ
        // item.second значение

        const auto& words = item.second; // массив слов, имеющих длину item.first
        for (const auto& word: words) {
            std::cout << word << std::endl;
        }
    }
}