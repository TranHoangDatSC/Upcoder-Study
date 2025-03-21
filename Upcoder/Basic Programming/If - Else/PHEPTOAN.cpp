#include <iostream>
using namespace std;
int main () {
    int a,b;
    char x;
    cin >> a >> b >> x;
    switch (x) {
        case '+': 
            cout << a << x << b << "="<< a + b;
            break;
        case '-': 
            cout << a << x << b << "="<< a - b;
            break;
        case '*': 
            cout << a << x << b << "="<< a * b;
            break;
        case '%': 
            cout << a << x << b << "="<< a % b;
            break;
        default:
            cout << "thuc hien sai";
    }
    return 0;
}
