#include <iostream>
using namespace std;

int Catalan(int n) {
    if(n < 1) return 1;
    
    int result = 0;
    
    for(int i = 0; i < n; i++) {
        result += Catalan(i)*Catalan(n-i-1);
    }
    
    return result;
}

int main() {
    int n;
    while(cin >> n)
        cout << Catalan(n) << "\n";
        
    return 0;
}
