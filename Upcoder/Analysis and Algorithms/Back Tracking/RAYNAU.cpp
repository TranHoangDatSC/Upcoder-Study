#include <iostream>
#include <vector>
using namespace std;

#define MAX 250

int row, col;
int grid[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int total = 0;
vector<pair<int,int>> current_region;

void BackTracking(int x, int y) {
    visited[x][y] = true;
    current_region.push_back({x,y});
    
    for(int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        
        if(1 <= xx && xx <= row && 1 <= yy && yy <= col 
        && !visited[xx][yy] && grid[xx][yy] == 1) {
            BackTracking(xx,yy);
        }
    }
}

void Input() {
    cin >> row >> col;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1)
                total++;
        }
    }
}

void Process() {
    cout << total << "\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                current_region.clear();
                BackTracking(i, j);

                cout << current_region.size() << " ";
                for (size_t k = 0; k < current_region.size(); k++) {
                    // In chỉ số theo đề: [dòng, cột], tính từ 1
                    cout << "[" << current_region[k].first + 1
                         << "," << current_region[k].second + 1 << "]";
                    if (k != current_region.size() - 1)
                        cout << ", ";
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    Input();
    Process();
    return 0;
}
