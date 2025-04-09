#include <iostream>
#include <bitset>
using namespace std;

void PrintBinaryString(int n) { 
    int total = 1;
    for(int i = 0; i < n; i++) {
        total *= 2;
    }
    
    for(int i = 0; i < total; i++) {
        // Chuyển số i sang dãy nhị phân 32 bit.
        bitset<32> b(i);   
        //Lấy n bit cuối (đảm bảo độ dài chính xác là n).
        string binary = b.to_string().substr(32 - n);  
        cout << binary << "\n";
    }
    
}

void Another(int n) {
    int total = 1;
    for(int i = 0; i < n; i++) {
        total *= 2;
    }
    
    for(int i = 0; i < total; i++) {
        int num = i;
        int binary[32];
        
        for(int j = 0; j < n; j++) {
            binary[n - j - 1] = num % 2;
            num /= 2;
        }
        
        for (int j = 0; j < n; j++) {
            cout << binary[j];
        }
        cout << "\n";
    }
}

void BackTracking(int idx, int n, int arr[]) {
    if(idx == n) {
        for(int i = 0; i < n; i++) {
            cout << arr[i];
        }
        cout << '\n';
        return;
    }
    
    arr[idx] = 0;
    BackTracking(idx + 1, n, arr);
    
    arr[idx] = 1;
    BackTracking(idx + 1, n, arr);
}

int main() {
    int n, binary[32];
    cin >> n;
    // Another(n);
    BackTracking(0,n,binary);
    return 0;
}
