#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll timer = 0, compCnt = 0;

void dfs(vvll& sccs, vll& lowlink, vll& onstack, vll& idx, vvll& g, stack<ll>& st, vll& compId, ll node){
    idx[node] = lowlink[node] = timer++;
    st.push(node);
    onstack[node] = 1;
    
    for(auto v : g[node]){
        if(idx[v]==-1){
            dfs(sccs, lowlink, onstack, idx, g, st, compId, v);
            lowlink[node] = min(lowlink[node], lowlink[v]);
        }
        else if(onstack[v]){
            lowlink[node] = min(lowlink[node], idx[v]);
        }
    }

    if(lowlink[node] == idx[node]){
        vll comp;
        while(true){
            ll x = st.top();st.pop();
            onstack[x] = 0;
            compId[x] = compCnt;
            comp.push_back(x);
            if(x == node)break;
        }
        sccs.push_back(comp);
        compCnt++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll m,n;cin>>m>>n;
    vector<array<string,2>> in(m+n);
    for(auto &i : in)cin>>i[0]>>i[1];

    map<string, ll> nametoint;
    map<ll, string> inttoname;
    ll ind = 0;
    for(auto &[i,j] : in){
        if(nametoint.find(i) == nametoint.end()){
            nametoint[i] = ind;
            inttoname[ind] = i;
            ind++;
        }
        if(nametoint.find(j) == nametoint.end()){
            nametoint[j] = ind;
            inttoname[ind] = j;
            ind++;
        }
    }

    vvll g(ind+1,vll{}), gr(ind+1,vll{});

    rep(i,0,n+m){
        ll ui = nametoint[in[i][0]], uj = nametoint[in[i][1]];
        g[ui].push_back(uj);
        gr[uj].push_back(ui);
    }

    vll lowlink(ind), onstack(ind, 0), idx(ind, -1), compId(ind,-1);
    vvll sccs;
    stack<ll> st;
    rep(i,0,ind)if(idx[i]==-1)dfs(sccs,lowlink,onstack,idx,g,st,compId,i);
    ll comps = (ll)sccs.size();

    vector<vector<pll>> dag(comps,vector<pll>{});
    vll indeg(comps,0);

    rep(i,0,m+n){
        ll u = nametoint[in[i][0]];
        ll v = nametoint[in[i][1]];
        ll cu = compId[u], cv = compId[v];
        if(cu == cv)continue;

        ll w = (i >= m ? 1 : 0);

        dag[cu].push_back({cv,w});
        indeg[cv]++;
    }

    vll dp(comps,0);
    queue<ll> q;
    rep(i,0,comps)if(indeg[i]==0)q.push(i);

    while(!q.empty()){
        ll u = q.front();q.pop();
        for(auto [v,w] : dag[u]){
            dp[v] = max(dp[v], dp[u]+w);
            if(--indeg[v]==0)q.push(v);
        }
    }

    ll mn = 1;
    rep(i,0,comps)mn = max(mn,1+dp[i]);
    cout<<mn<<" "<<comps<<"\n";
    return 0;
}