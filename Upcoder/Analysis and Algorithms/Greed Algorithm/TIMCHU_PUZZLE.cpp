#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int n, m, t;
char c[55][55];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool checkDirection(int x, int y, int dir, const string &word, vector<pair<int, int>> &path) {
    path.clear();
    for (int i = 0; i < word.size(); ++i) {
        if (!isValid(x, y) || c[x][y] != word[i]) return false;
        path.push_back({x + 1, y + 1});
        x += dx[dir];
        y += dy[dir];
    }
    return true;
}

bool searchWord(const string &word, vector<pair<int, int>> &path) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int dir = 0; dir < 8; ++dir)
                if (checkDirection(i, j, dir, word, path))
                    return true;
    return false;
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    while (t--) {
        string word;
        cin >> word;
        vector<pair<int, int>> path;

        if (searchWord(word, path)) {
            cout << "YES\n";
            for (int i = 0; i < path.size(); ++i)
                cout << "(" << path[i].first << "," << path[i].second << ") ";
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
