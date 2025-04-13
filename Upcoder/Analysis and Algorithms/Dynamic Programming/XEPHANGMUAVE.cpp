#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> t(N), r(N - 1);
    for (int i = 0; i < N; i++) cin >> t[i];
    for (int i = 0; i < N - 1; i++) cin >> r[i];

    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = t[0];

    for (int i = 2; i <= N; i++) {
        dp[i] = min(dp[i - 1] + t[i - 1], dp[i - 2] + r[i - 2]);
    }

    cout << dp[N] << endl;
    return 0;
}
