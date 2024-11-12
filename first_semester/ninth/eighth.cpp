#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int** create(unsigned int n, unsigned int m)
{
    int **a = new int*[n];
    for (unsigned int i = 0; i < n; i++)
        a[i] = new int[m];
    return a;
}
void destroy(int** a, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}
void print(int **a, unsigned int n, unsigned int m)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
unsigned get_size(unsigned k) {
    return (k + 1) / 2;
}

int** create_compact(int **a, unsigned int n, unsigned int m) {
    auto n_c = get_size(n);
    auto m_c = get_size(m);

    int** compact = new int*[n_c];
    for (auto i = 0u; i < n_c; i++) {
        compact[i] = new int[m_c];
    }

    for (auto i = 0u; i < n_c; i++) {
        for (auto j = 0u; j < m_c; j++) {
            compact[i][j] = a[2 * i][2 * j];
            if (2 * i + 1 < n) {
                compact[i][j] += a[2 * i + 1][2 * j];
            }
            if (2 * j + 1 < m) {
                compact[i][j] += a[2 * i][2 * j + 1];
            }
            if (2 * i + 1 < n && 2 * j + 1 < m) {
                compact[i][j] += a[2 * i + 1][2 * j + 1];
            }
        }
    }

    return compact;
}
void print_compact(int **compact, unsigned int n, unsigned int m) {
    auto n_c = get_size(n);
    auto m_c = get_size(m);

    for (auto i = 0u; i < n_c; i++) {
        for (auto j = 0u; j < m_c; j++) {
            std::cout << compact[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void destroy_compact(int** compact, unsigned int n) {
    for (auto i = 0u; i < get_size(n); i++) {
        delete[] compact[i];
    }
    delete[] compact;
}
// ваш код сюда
int main()
{
    unsigned int n, m;
    cin >> n >> m;
    int **a = create(n, m);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> a[i][j];
    int** b = create_compact(a, n, m);
    print(a, n, m);
    print_compact(b, n, m);
    destroy(a, n);
    destroy_compact(b, n);
    return 0;
}
