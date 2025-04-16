#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, p, q, k;
        cin >> n >> m >> p >> q >> k;

        int maxGraphPerStudent = k / p;
        int maxDPPerStudent = k / q;

        int res = INT_MAX;

        for (int graphByTran = 0; graphByTran <= min(n, k / p); ++graphByTran) {
            int dpByTran = (k - graphByTran * p) / q;
            if (dpByTran > m) dpByTran = m;

            int remainGraph = n - graphByTran;
            int remainDP = m - dpByTran;

            int studentsGraph = (maxGraphPerStudent == 0) ? INT_MAX : (remainGraph + maxGraphPerStudent - 1) / maxGraphPerStudent;
            int studentsDP = (maxDPPerStudent == 0) ? INT_MAX : (remainDP + maxDPPerStudent - 1) / maxDPPerStudent;

            res = min(res, studentsGraph + studentsDP + 1); // +1 for Tran
        }

        cout << res << '\n';
    }

    return 0;
}
