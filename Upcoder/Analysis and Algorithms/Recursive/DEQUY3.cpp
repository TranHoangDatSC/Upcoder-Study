#include <iostream>
using namespace std;

void ChinhHop0Lap(int n, int k, int arr[], bool used[], int pos) {
    if(pos == n) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << "";
        }
        cout << '\n';
    } else {
        for(int i = 1; i <= k; i++) {
            if(!used[i]) {
                arr[pos] = i;
                used[i] = true;
                ChinhHop0Lap(n,k,arr,used,pos + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    bool used[n] = {false};
    
    ChinhHop0Lap(n,k,arr,used,0);
    
    return 0;
}
