#include <iostream>
using namespace std;

int main () {
    int a[100];
    int n = 0;
    int x;
    while(cin >> x) {
        a[n++] = x;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
