#include <iostream>
using namespace std;

int dx[] = {-1,-2,1,-2,-1,2,2,1};
int dy[] = {-2,-1,-2,1,2,-1,1,2};
bool a[100][100];
int n, ans, cnt = 0;

void Try(int x, int y) {
    if(cnt == n * n) ans++;
    
    for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && !a[xx][yy]) {
            a[xx][yy] = true;
            cnt++;
            Try(xx,yy);
            cnt--;
            a[xx][yy] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] = true;
            cnt++;
            Try(i,j);
            cnt--;
            a[i][j] = false;
        }
    } cout << ans;
    return 0;
}
