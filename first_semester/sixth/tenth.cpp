#include <iostream>

int main() {
    std::string row, column;

    std::cin >> row >> column;

    int lengths[129][129];

    for (auto i = 0; i < 129; i++) {
        lengths[0][i] = 0;
        lengths[i][0] = 0;
    }
    auto m = row.size();
    auto n = column.size();

    auto result = 0;
    for (auto i_m = 1u; i_m <= m; i_m++) {
        for (auto i_n = 1u; i_n <= n; i_n++) {
            if (row[i_m - 1u] == column[i_n - 1u]) {
                lengths[i_m][i_n] = lengths[i_m - 1][i_n - 1] + 1;
            } else {
                lengths[i_m][i_n] = std::max(
                    lengths[i_m - 1][i_n], lengths[i_m][i_n - 1]
                );
            }
            result = std::max(result, lengths[i_m][i_n]);
        }
    }

    std::cout << result << std::endl;
}

