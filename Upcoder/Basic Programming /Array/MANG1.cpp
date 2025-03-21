#include <iostream>
using namespace std;

int main () {
    int n;
    int array[100];
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++) {
        sum = sum + array[i];
    }
    cout << sum;
}
