#include <iostream>

using namespace std;
int main () {
    int position, number;
    cin >> position >> number;
    
    int n = 0;
    int a[100];
    int x;
    
    while (cin >> x) {
        a[n++] = x;
    }
    for (int i = n; i > position; i--) {
        a[i] = a[i-1];
    }
    a[position] = number;
    
    n++;
    
    for (int i = 0;i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}
