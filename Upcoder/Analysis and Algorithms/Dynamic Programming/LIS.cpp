#include <iostream>
using namespace std;

int main() {
    int a[100];     // Mảng lưu các phần tử
    int dp[100];    // Mảng quy hoạch động 
    int n = 0;      
    
    int x;
    while(cin >> x)     
        a[n++] = x;
        
    int size = 0;   // Độ dài lớn nhất của dãy con
    
    for(int i = 0; i < n; i++) {
        dp[i] = 1;      // Mỗi phần tử đơn lẻ là dãy tăng độ dài ít nhất là 1
        
        for(int j = 0; j < i; j++) 
            if(a[j] < a[i] && dp[j] + 1 > dp[i]) // Nếu có phần tử nhỏ hơn a[i]
                dp[i] = dp[j] + 1;               // Cập nhật LIS tại i
        
        if(dp[i] > size) 
            size = dp[i];                        // Cập nhật độ dài lớn nhất
    }
    
    cout << size;
    
    return 0;
}
