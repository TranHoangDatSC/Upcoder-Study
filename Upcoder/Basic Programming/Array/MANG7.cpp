#include <bits/stdc++.h>
using namespace std;

void nhapMang(int a[][100], int n) {
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void inCheoChinh(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i][i] << " ";
    }
}

int main() {
    int n, a[100][100];
    cin >> n;

    nhapMang(a, n);
    inCheoChinh(a, n);

    return 0;
}
