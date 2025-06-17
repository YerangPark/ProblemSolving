#include <iostream>
#include <vector>
using namespace std;

int N;
using Matrix = vector<vector<int>>;

Matrix multiply(Matrix& A, Matrix& B) {
    Matrix result(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % 1000;
            }
        }
    }
    return result;
}

Matrix power(Matrix A, long long exp) {
    if (exp == 1) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                A[i][j] %= 1000;
            }
        }
        return A;
    }

    Matrix half = power(A, exp / 2);
    Matrix result = multiply(half, half);
    if (exp % 2 == 1) {
        result = multiply(result, A);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long B;
    cin >> N >> B;

    Matrix A(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }

    Matrix answer = power(A, B);
    for (const auto& row : answer) {
        for (int val : row) {
            cout << val % 1000 << ' ';
        }
        cout << '\n';
    }
    return 0;
}