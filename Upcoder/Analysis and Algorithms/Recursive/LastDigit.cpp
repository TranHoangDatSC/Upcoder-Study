#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, n;
    cin >> a >> n;

    int last_digit = a % 10;
    vector<int> cycle;
    int current = last_digit;

    // Tìm chu kỳ lặp
    do {
        cycle.push_back(current);
        current = (current * last_digit) % 10;
    } while (current != cycle[0]);

    // Nếu n == 0, bất kỳ số nào mũ 0 là 1
    if (n == 0) {
        cout << 1;
    } else {
        int index = (n - 1) % cycle.size();
        cout << cycle[index];
    }

    return 0;
}



// #include <iostream>
// using namespace std;

// int Pow(int a, int n) {
//     if(n == 0) return 1;
//     return a * Pow(a, n - 1);
// }

// int LastDigit(int n) {
//     if(n < 10) return n;
//     return LastDigit(n % 10);
// }

// int main() {
//     int a,n;
//     cin >> a >> n;
//     cout << LastDigit(Pow(a,n));
//     return 0;
// }


