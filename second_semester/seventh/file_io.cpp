

#include <fstream>
#include <iterator>
#include <vector>

int main() {

    std::vector<int> nums;

    // std::ifstream fin("input.txt");

    // the same but fstream instead of ifstream
    std::fstream fin("input.txt", std::ios::in);

    std::copy(std::istream_iterator<int>(fin),
              std::istream_iterator<int>(),
              std::back_inserter(nums));

    fin.close();

    // clear file before writing
    // std::ofstream fout("output.txt", std::ios::out);

    // append to the end
    // std::ofstream fout("output.txt", std::ios::app);

    std::fstream fout("output.txt", std::ios::out);

    std::copy(nums.begin(), nums.end(),
              std::ostream_iterator<int>(fout, " "));
    fout << std::endl;

    fout.close();

}
