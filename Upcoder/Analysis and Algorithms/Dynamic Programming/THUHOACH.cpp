#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n,w;
    cin >> n >> w;
    
    int product[21];        // Sản phẩm (khối lượng)
    int dp[50001] = {0};    // Mảng Quy Hoạch Động lưu lại khối lượng
    int idx = 0;
    
    // Nhập vào các sản phẩm
    while(cin >> product[idx]) 
        idx++;
    
    for(int i = 0; i < n; i++) { // Duyệt qua các bao
        for(int j = w; j >= product[i]; j--) { // Xem lại khối lượng các bao
            // So sánh và chọn bao lớn nhất
            dp[j] = max(dp[j], dp[j - product[i]] + product[i]); 
        }
    }
    
    cout << dp[w];
    
    return 0;
}
