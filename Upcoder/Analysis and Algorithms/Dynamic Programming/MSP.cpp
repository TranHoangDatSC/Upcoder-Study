#include <iostream>
using namespace std;

const int MAX = 10000;

int main() {
    int array[MAX]; // Mảng các phần tử
    int dp[MAX];    // Mảng quy hoạch động
    int n = 0;
    
    int x;
    while(cin >> x) {
        array[n++] = x;
    }
    
    dp[0] = array[0];   // Trường hợp cơ sở
    int maxSum = dp[0]; // Tổng lớn nhất ban đầu
    
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] + array[i] > array[i]) 
            dp[i] = dp[i - 1] + array[i];   // Tiếp tục dãy trước
        else 
            dp[i] = array[i];   // Bắt đầu dãy mới
            
        if(dp[i] > maxSum)
            maxSum = dp[i]; // Cập nhật tổng lớn nhất 
    }
    
    cout << maxSum;
    return 0;
}
