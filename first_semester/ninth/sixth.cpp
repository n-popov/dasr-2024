#include <iostream>
using namespace std;
int** transpose(int** matrix, unsigned int N, unsigned int M) {
    int** transposed = new int*[M];
    for (auto i = 0u; i < M; i++) {
        transposed[i] = new int[N];
    }

    for (auto i = 0u; i < M; i++) {
        for (auto j = 0u ; j < N; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

// ваш код здесь
int main()
{
    int** matrix;
    unsigned int N, M;
    cin >> N >> M;
    matrix = new int*[N];
    for(unsigned int i = 0; i < N; i++) {
        matrix[i] = new int[M];
        for(unsigned int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    int** t = transpose(matrix, N, M);
    for(unsigned int i = 0; i < N; i++) {
        for(unsigned int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(unsigned int i = 0; i < M; i++) {
        for(unsigned int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    for(unsigned int i = 0; i < M; i++) {
        delete[] t[i];
    }
    delete[] t;
    for(unsigned int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
