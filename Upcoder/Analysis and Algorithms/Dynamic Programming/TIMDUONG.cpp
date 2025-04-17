#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nV, nE, S, T;
const int MAX = 1e5 + 5;
vector<int> adj[MAX];
bool visited[MAX];
int cnt[MAX];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x : adj[v]) {
            if(!visited[x]) {
                cnt[x] = cnt[v] + 1;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    cin >> nV >> nE >> S >> T;
    
    while(nE--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(S);
    cout << cnt[T];
    
    return 0;
}
