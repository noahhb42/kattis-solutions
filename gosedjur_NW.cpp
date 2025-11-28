#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N,R,C;cin>>N>>R>>C;

    vector<vector<int>> a(R, vector<int>(C));
    rep(i,0,R) rep(j,0,C) cin >> a[i][j];

    vector<vector<int>> g(N+1), gr(N+1);
    for(int r=1;r<R;r++){
        for(int c=0;c<C;c++){
            int below = a[r][c];
            int above = a[r-1][c];
            if(below==above) continue;
            g[below].push_back(above);
            gr[above].push_back(below);
        }
    }
    for(int i=1;i<=N;i++){
        auto &v1 = g[i];
        sort(v1.begin(), v1.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        auto &v2 = gr[i];
        sort(v2.begin(), v2.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
    }

    int n = (int)N;
    vector<int> disc(n+1,-1), low(n+1,0), comp_id(n+1,-1), st;
    vector<char> in_st(n+1,0);
    int timer = 0, comp_cnt = 0;

    function<void(int)> dfs_scc = [&](int u){
        disc[u] = low[u] = timer++;
        st.push_back(u);
        in_st[u] = 1;
        for(int v : g[u]){
            if(disc[v] == -1){
                dfs_scc(v);
                low[u] = min(low[u], low[v]);
            }else if(in_st[v]){
                low[u] = min(low[u], disc[v]);
            }
        }
        if(low[u] == disc[u]){
            while(true){
                int x = st.back(); st.pop_back();
                in_st[x] = 0;
                comp_id[x] = comp_cnt;
                if(x == u) break;
            }
            comp_cnt++;
        }
    };

    for(int i=1;i<=n;i++)
        if(disc[i] == -1)
            dfs_scc(i);

    vector<int> comp_sz(comp_cnt,0);
    for(int i=1;i<=n;i++) comp_sz[comp_id[i]]++;

    vector<vector<int>> compG(comp_cnt), compGR(comp_cnt);
    vector<char> compHasSelf(comp_cnt,0);
    for(int u=1;u<=n;u++){
        for(int v:g[u]){
            int cu = comp_id[u], cv = comp_id[v];
            if(cu == cv){
                compHasSelf[cu] = 1;
            }else{
                compG[cu].push_back(cv);
                compGR[cv].push_back(cu);
            }
        }
    }
    for(int c=0;c<comp_cnt;c++){
        auto &v1 = compG[c];
        sort(v1.begin(), v1.end());
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        auto &v2 = compGR[c];
        sort(v2.begin(), v2.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
    }

    vector<char> compBad(comp_cnt,0);
    queue<int> qc;
    for(int c=0;c<comp_cnt;c++){
        if(comp_sz[c] > 1 || compHasSelf[c]){
            compBad[c] = 1;
            qc.push(c);
        }
    }
    while(!qc.empty()){
        int c = qc.front(); qc.pop();
        for(int p : compGR[c]){
            if(!compBad[p]){
                compBad[p] = 1;
                qc.push(p);
            }
        }
    }

    vector<char> bad(n+1,0);
    for(int i=1;i<=n;i++)
        bad[i] = compBad[comp_id[i]];

    vector<int> indeg(n+1,0);
    for(int u=1;u<=n;u++) if(!bad[u]){
        for(int v:g[u]) if(!bad[v]) indeg[v]++;
    }

    vector<int> topo; topo.reserve(n);
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!bad[i] && indeg[i]==0) q.push(i);

    while(!q.empty()){
        int u=q.front(); q.pop();
        topo.push_back(u);
        for(int v:g[u]) if(!bad[v]){
            if(--indeg[v]==0) q.push(v);
        }
    }

    vll ans(n+1,-1);

    int B = (n + 63) / 64;
    vector<vector<unsigned long long>> bs(n+1, vector<unsigned long long>(B,0ULL));

    auto set_bit = [&](int u,int id){
        int block = (id-1)>>6;
        int bit   = (id-1)&63;
        bs[u][block] |= (1ULL<<bit);
    };
    auto or_into = [&](int u,int v){
        for(int k=0;k<B;k++) bs[u][k] |= bs[v][k];
    };
    auto count_bits = [&](int u)->ll{
        ll cnt=0;
        for(int k=0;k<B;k++) cnt += __builtin_popcountll(bs[u][k]);
        return cnt;
    };

    vector<int> rev_topo = topo;
    reverse(rev_topo.begin(), rev_topo.end());

    for(int u : rev_topo){
        if(bad[u]) continue;
        for(int v : g[u]){
            if(bad[v]) continue;
            or_into(u,v);
            set_bit(u,v);
        }
    }

    for(int i=1;i<=n;i++){
        if(bad[i]) ans[i] = -1;
        else ans[i] = count_bits(i);
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<(i==n?'\n':' ');
    }
}
