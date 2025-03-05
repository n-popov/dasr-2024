
#include <vector>

class ATM
{
public:
    // Конструктор, создаёт пустой банкомат
    ATM() = default;

    // Деструктор, если нужен

    // Вносит в устройство набор купюр
    // - в векторе notes перечислены достоинства вносимых купюр (разумеется, возможны повторы)
    // - в поле currency указан код валюты
    void deposit(const std::vector<unsigned int>& notes, unsigned short int currency) {
        auto& note_to_amount = currency_to_notes[currency];

        for (auto note: notes) {
            note_to_amount[note] += 1;
        }
    }

    // Снять сумму amount в валюте currency, выдав её максимально мелкими купюрами
    // - если операция прошла успешно, учесть выданные купюры в банкомате и вернуть их в возвращаемом vector-е
    // - если целиком запрошенную сумму выдать невозможно, не выдавать ничего и вернуть пустой vector
    std::vector<unsigned int> withdraw_small(unsigned int amount, unsigned short int currency) {
        auto& note_to_amount = currency_to_notes[currency];
        std::map<unsigned, unsigned> withdraw_map;

        for (auto note_amount: note_to_amount) {
            auto note = note_amount.first;
            auto available_amount = note_amount.second;

            auto needed_amount = amount / note;
            auto withdraw_amount = std::min(needed_amount, available_amount);

            withdraw_map[note] = withdraw_amount;
            amount -= note * withdraw_amount;
        }


        std::vector<unsigned> result;
        if (amount == 0u) {
            for (auto note_amount: withdraw_map) {
                auto note = note_amount.first;
                auto withdraw_amount = note_amount.second;

                for (auto i = 0u; i < withdraw_amount; i++) {
                    result.push_back(note);
                }
                note_to_amount[note] -= withdraw_amount;
            }
        }
        return result;
    }

    // Вернуть максимальную сумму, доступную в валюте currency
    unsigned int check_reserve(unsigned short int currency) {
        auto& note_to_amount = currency_to_notes[currency];
        auto sum = 0u;

        for (auto note_amount: note_to_amount) {
            // note_amount -- пара, first - key, second - value
            sum += note_amount.first * note_amount.second;
        }
        return sum;
    }

private:
    std::map<unsigned short, std::map<unsigned, unsigned>> currency_to_notes;

};
