#include <iostream>
using namespace std;

int main () {
    int vt;
    cin >> vt;
    
    int a[100];
    int x, n = 0;
    
    while (cin >> x) {
        a[n++] = x;
    }
    
    for (int i = vt; i < n-1; i++) {
        a[i] = a[i+1];
    }
    
    n--;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
