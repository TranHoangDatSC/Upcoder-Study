#include <iostream>
using namespace std;

const int MAX = 51;
int n;
long long C[MAX][MAX]; // dùng long long để tránh tràn số

long long pascal(int i, int j) {
    if (j == 0 || j == i) return 1;
    if (C[i][j] != 0) return C[i][j];
    C[i][j] = pascal(i - 1, j - 1) + pascal(i - 1, j);
    return C[i][j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pascal(i, j);
            if (j < i) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
