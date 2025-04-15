#include <iostream>
using namespace std;

int ToHopChapK(int n, int k) {
    if(k == 1) return n;
    if(k == n) return 1;
    return ToHopChapK(n - 1, k) + ToHopChapK(n - 1, k - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << ToHopChapK(n,k);
    return 0;
}
