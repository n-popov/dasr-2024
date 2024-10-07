#include <iostream>

int main() {
    std::string row, column;

    std::cin >> row >> column;

    int lengths[129][129];

    for (auto i = 0; i < 129; i++) {
        for (auto j = 0; j < 129; j++) {
            lengths[i][j] = 0;
        }
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

    char rev_result[128];
    for (auto i = 0; i < 128; i++) {
        rev_result[i] = 0;
    }
    int res_idx = -1;

    for (auto i_m = m, i_n = n; i_m > 0 && i_n > 0;) {
        if (row[i_m - 1] == column[i_n - 1]) {
            rev_result[++res_idx] = row[i_m - 1];
            i_m--;
            i_n--;
        } else {
            if (lengths[i_m - 1][i_n] > lengths[i_m][i_n - 1]) {
                i_m--;
            } else {
                i_n--;
            }
        }
    }

    for (auto i = res_idx; i >= 0; i--) std::cout << rev_result[i];
    std::cout << std::endl;
}

