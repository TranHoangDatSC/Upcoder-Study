#include <iostream>
#include <cmath>

using namespace std;

double recursive(int n) { 
    if (n == 0) 
        return 0;  
    return sqrt(2 + recursive(n - 1)); 
}

double removeRecursive(int n) {  
    double res = 0; 
    for (int i = 1; i <= n; i++) {
        res = sqrt(2 + res);
    }
    return res;
}

int main() {
    int n;
    cin >> n;    
    cout << recursive(n) << endl;
    cout << removeRecursive(n) << endl;
    return 0;
}
