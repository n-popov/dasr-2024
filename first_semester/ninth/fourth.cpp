#include <iostream>
using namespace std;
int* doubling(int* arr, unsigned int N) {
    auto new_arr = new int[2 * N];
    for (auto i = 0u; i < N; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    return new_arr;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int up = 0; up < 5; up++)
    {
        for (int i = 0; i < n; i++)
            a[i] = n - i;
        a = doubling(a, n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != n - i)
            {
                cout << "NOPE" << endl;
                return 0;
            }
        }
        n *= 2;
    }
    delete[] a;
    cout << "YEP" << endl;
    return 0;
}
