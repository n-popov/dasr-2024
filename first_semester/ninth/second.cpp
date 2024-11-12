#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap_arrays(int** p_array_0, int** p_array_1) {
    std::swap(*p_array_0, *p_array_1);
}

int main()
{
    int n;
    cin >> n;
    int *ar_0 = new int[n];
    int *ar_1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> ar_0[i];
    for (int i = 0; i < n; i++)
        cin >> ar_1[i];
    swap_arrays(&ar_0, &ar_1);
    for (int i = 0; i < n; i++)
        cout << ar_0[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << ar_1[i] << ' ';
    cout << endl;
    delete[] ar_0;
    delete[] ar_1;
    return 0;
}

