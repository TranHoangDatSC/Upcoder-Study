#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void Game() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        
        sort(a.begin(),a.end());
        sort(b.begin(), b.end(), greater<int>());
        
        int sum_a = 0, sum_b = 0;
        for(int i = 0; i < m; ++i) {
            sum_a += a[i];
            sum_b += b[i];
        }
        
        cout << (sum_a > sum_b ? "YES" : "NO") << '\n';
    }
}

int main() {
    Game();
    return 0;
}
