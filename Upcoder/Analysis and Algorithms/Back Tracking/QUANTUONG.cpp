#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 21;
int n, m, p, q, s, t;
bool blocked[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

struct State {
    int x, y, steps;
};

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && !blocked[x][y];
}

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<State> que;

    State start;
    start.x = p;
    start.y = q;
    start.steps = 0;
    que.push(start);
    dist[p][q] = 0;

    while (!que.empty()) {
        State curr = que.front(); que.pop();
        int x = curr.x, y = curr.y, steps = curr.steps;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            while (valid(nx, ny)) {
                if (dist[nx][ny] != -1) {
                    if (dist[nx][ny] <= steps + 1) {
                        nx += dx[dir];
                        ny += dy[dir];
                        continue;
                    }
                }
                dist[nx][ny] = steps + 1;

                State next;
                next.x = nx;
                next.y = ny;
                next.steps = steps + 1;
                que.push(next);

                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    return dist[s][t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p >> q >> s >> t;
    memset(blocked, false, sizeof(blocked));

    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        blocked[r][c] = true;
    }

    if (p == s && q == t) {
        cout << 0 << '\n';
    } else {
        int res = bfs();
        cout << res << '\n';
    }

    return 0;
}
