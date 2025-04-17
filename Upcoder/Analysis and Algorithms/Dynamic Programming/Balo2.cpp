#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int a, c;
};

int main() {
    int n, w;
    cin >> n >> w;
    vector<Item> items(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> items[i].a >> items[i].c;
        
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    vector<int> selected(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= items[i].a)
                dp[i][j] = max(dp[i][j], dp[i-1][j-items[i].a] + items[i].c);
        }
    }
    
    for(int i = n, j = w; i >= 1; i--) {
        if(j >= items[i].a && dp[i][j] == dp[i-1][j - items[i].a] + items[i].c) {
            selected[i] = 1;
            j -= items[i].a;
        }
    }
    
    cout << dp[n][w] << "\n";
    for(int i = 1; i <= n; i++) 
        cout << selected[i] << " ";
        
    return 0;
}
