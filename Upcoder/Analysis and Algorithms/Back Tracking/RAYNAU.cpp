#include <iostream>
#include <vector>
using namespace std;

struct ToaDo {
    int Ox, Oy;
    ToaDo(int a, int b) : Ox(a), Oy(b) {}
};

int n, m, sum = 0;
int a[100][100];
vector<ToaDo> pos;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void Try(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == 1) {
            a[xx][yy] = 0;
            pos.push_back({xx,yy});
            Try(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) sum++;
        }
    }
    
    cout << sum << "\n";
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 1) {
                a[i][j] = 0;
                pos.push_back({i,j});
                Try(i,j);
                
                cout << pos.size();
                for(int k = 0; k < pos.size(); k++) {
                    if(k > 0) cout << ",";
                    cout << " [" << pos[k].Ox << ","
                    << pos[k].Oy << "]";
                }
                cout << "\n";
                pos.clear();
            }
        }
    }
    return 0;
}
