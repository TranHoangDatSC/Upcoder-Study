#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> computer(n);
    vector<int> buying;
    
    for(int i = 0; i < n;i++) 
        cin >> computer[i];
    
    for(int i = 0; i < n; i++) 
        if(computer[i] < 0)
            buying.push_back(computer[i]);
            
    sort(buying.begin(),buying.end());
    int sum = 0;
    int maxCnt = min(m, (int)buying.size());
    
    for(int i = 0; i < maxCnt; i++) {
        if(!buying.empty())
            sum += -(buying[i]);
        else 
            sum = 0;
    }
    
    cout << sum;
    
    return 0;
}
