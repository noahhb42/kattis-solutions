#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); }
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do {
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;
    while(cin>>n){
        if(n==-1)break;
        cin>>m;

        vi p(n+1);
        rep(i,1,n+1)cin>>p[i];

        vector<pii> matches(m);
        for(auto &i : matches) cin >> i.first >> i.second;

        vi ans(m,-1);
        ll cntN = 0;
        rep(i,0,m){
            auto [a,b] = matches[i];
            if(a == n) {ans[i] = 0; cntN++; }
            else if (b == n) { ans[i] = 2; cntN++; }
        }

        ll pn = p[n] + 2*cntN;

        vector<ll> cap(n+1,0);
        bool ok = true;
        rep(i,1,n){
            cap[i] = pn - 1 - p[i];
            if(cap[i] < 0)ok = false;
        }
        if(!ok){cout << "NO\n"; continue;}

        vi matchnode(m,-1);
        ll k = 0;
        rep(i,0,m){
            if(ans[i] == -1)matchnode[i] = k++;
        }

        ll s = 0, firstmatch = 1, firstteam = firstmatch + k, t = firstteam + n-1, v = t+1;
        Dinic din(v);

        auto teamId = [&](int t){
            return firstteam+t-1;
        };

        vector<pii> edges(m,{-1,-1});

        rep(i,0,m){
            if(matchnode[i] == -1)continue;

            auto [a,b] = matches[i];
            ll mn = firstmatch + matchnode[i];

            din.addEdge(s,mn,2);

            ll eaidx = sz(din.adj[mn]);
            din.addEdge(mn, teamId(a), 2);
            din.addEdge(mn, teamId(b), 2);
            edges[i] = {mn, eaidx};
        }

        rep(i,1,n){
            din.addEdge(teamId(i),t,cap[i]);
        }

        ll need = 2*k;
        ll flow = din.calc(s,t);
        if(flow != need){cout << "NO\n"; continue;}

        rep(i,0,m){
            if(ans[i] != -1)continue;
            auto [node, ei] = edges[i];
            ll fa = din.adj[node][ei].flow();
            if(fa == 2)ans[i] = 0;
            else if (fa==1)ans[i] = 1;
            else ans[i] = 2;
        }

        rep(i,0,m)cout<<ans[i]<<" ";cout<<"\n";
    }
    return 0;
}