#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e5;
ll parent[mxn];
ll down[mxn], up[mxn], ans[mxn];

void dfs(vvll& g, ll node){
    if(g[node].size() == 1){
        down[node] = 0;
        return;
    }
    for(auto v : g[node]){
        if(v == parent[node])continue;
        parent[v] = node;
        dfs(g, v);
    }
    vll child;
    for(auto v : g[node]){
        if(v == parent[node])continue;
        child.push_back(down[v]);
    }
    sort(child.begin(),child.end());
    ll m = child.size();
    rep(i,0,m){
        down[node] = max(down[node],child[i]+m-i);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    iota(parent,parent+n,0);
    vvll g(n);
    rep(i,0,n){
        ll m;cin>>m;
        rep(_,0,m){
            ll a;cin>>a;
            g[i].push_back(a);
        }
    }
    ll root = 0;
    g[root].push_back(root);
    dfs(g,root);
    cout<<down[root]<<"\n";
}