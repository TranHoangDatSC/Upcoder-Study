#include <iostream>
using namespace std;

int n, ways;
bool a[100], cheochinh[100],cheophu[100];

void Try(int i) {
    if(i == n) {
        ways++;
    }
    
    for(int j = 0; j < n; j++) {
        if(!a[j] && !cheochinh[i - j + n] && !cheophu[i + j]) {
            a[j] = true;
            cheochinh[i - j + n] = true;
            cheophu[i + j] = true;
            
            Try(i + 1);
            
            a[j] = false;
            cheochinh[i - j + n] = false;
            cheophu[i + j] = false;
        }
    }
}

int main() {
    cin >> n;
    Try(0);
    cout << ways;
    return 0;
}
