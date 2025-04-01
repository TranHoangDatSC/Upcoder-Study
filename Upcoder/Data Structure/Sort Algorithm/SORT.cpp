#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_odd(int n) {
    int sum = 0;
    while (n > 0) {
        if ((n % 10) % 2 == 1) sum++;
        n /= 10;
    }
    return sum;
}

bool compare(int a, int b) {
    int oddA = count_odd(a);
    int oddB = count_odd(b);
    if (oddA != oddB) return oddA > oddB; 
    return a < b; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end(), compare);

    for (int num : arr) cout << num << " ";
    cout << "\n";

    return 0;
}
