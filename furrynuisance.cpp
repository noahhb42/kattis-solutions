#include"bits/stdc++.h"

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool bfs(int s, int trenger, vi &deg, vector<bool> &vis, vector<vi> &adj) {
    queue<int> cur, next;
    vis[s] = true;
    cur.push(s);
    int leaf = 0;

    while (!cur.empty()) {
        swap(cur, next);
        while (!next.empty()) {
            int v = next.front();
            next.pop();
            bool harbarn = false;
            for (int u : adj[v]) {
                if (vis[u]) continue;

                vis[u] = true;
                harbarn = true;
                cur.push(u);
            }

            if (!harbarn) leaf++;
        }

        if (sz(cur) + leaf >= trenger) return true;
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<vi> adj(n+1);
        vector<bool> vis(n+1, false);
        vi deg(n+1, 0);

        rep(i, 0, m) {
            int x, y; cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
            deg[y]++;
            deg[x]++;
        }

        bool ok = false;
        for (int i = 1; i <= n && !ok; i++) {
            if (vis[i]) continue;

            int trenger = 4 - (deg[i] == 1 ? 1 : 0);
            if (bfs(i, trenger, deg, vis, adj)) ok = true;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}