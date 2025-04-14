#include <iostream>
using namespace std;

int DaySo(int n) {
     if(n < 2) return n;
     if(n % 2 == 0) return DaySo(n / 2);
     return DaySo(n / 2) + DaySo(n / 2 + 1);
}

int main() {
    int n;
    cin >> n;
    int max = -1;
    
    for(int i = 0; i <= n; i++) 
        if(DaySo(i) > max)
            max = DaySo(i);
            
    cout << max;
    
    return 0;
}
