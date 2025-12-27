#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin>>n>>m>>k;
    
    auto idx = [&](int i, int j){
        return i*m+j;
    };

    vector<bool> illegal(n*m,false);
    rep(i,0,k){
        int a,b;cin>>a>>b;
        illegal[idx(a,b)]=true;
    }

    vi leftId(n*m,-1),rightId(n*m,-1);
    int l=0,r=0;

    rep(i,0,n){
        rep(j,0,m){
            int id = idx(i,j);
            if(illegal[id])continue;
            if((i+j)&1)leftId[id]=l++;
            else rightId[id]=r++;
        }
    }

    vector<vi> g(l);

    auto addEdge = [&](int i1, int j1, int i2, int j2){
        if(i2<0 || i2>=n || j2<0 || j2>=m)return;
        int a = idx(i1,j1), b = idx(i2,j2);
        if(illegal[a] || illegal[b])return;
        if(leftId[a]==-1 || rightId[b]==-1)return;
        g[leftId[a]].push_back(rightId[b]);
    };

    rep(i,0,n){
        rep(j,0,m){
            int id = idx(i,j);
            if(illegal[id])continue;
            if(leftId[id]==-1)continue;

            addEdge(i,j,i+1,j);
            addEdge(i,j,i-1,j);
            addEdge(i,j,i,j+1);
        }
    }
    vi btoa(r,-1);

    cout<<hopcroftKarp(g,btoa)<<"\n";
}