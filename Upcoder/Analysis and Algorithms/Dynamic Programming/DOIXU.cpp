#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> coins = {1,2,5};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int coin : coins) 
        for(int i = coin; i <= n; i++)
            dp[i] = dp[i] + dp[i - coin];
            
    cout << dp[n];
    return 0;
}
