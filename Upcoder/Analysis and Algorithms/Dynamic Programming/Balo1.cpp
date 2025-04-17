#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    
    vector<int> a(n);
    for(int &x: a) cin >> x;
    
    vector<vector<int>> dp(n + 1, vector<int>(w + 1,0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if(a[i - 1] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] +a [i - 1]);
        }
    }
    cout << dp[n][w] << "\n";
    
    vector<int> chosen;
    int i = n, j = w;
    
    while(i > 0 && j > 0) {
        if(dp[i][j] != dp[i - 1][j]) {
            chosen.push_back(i - 1);
            j -= a[i - 1];
        }
        i--;
    }
    
    for(int k = chosen.size() - 1; k >= 0; k--)
        cout << chosen[k] << " ";
        
    return 0;
}
