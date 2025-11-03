#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
typedef array<ll,4> qll;
#define rep(i,a,n) for(ll i=a;i<n;++i)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll inv(ll a, ll b){ return 1<a ? b - inv(b%a,a)*b/a : 1; }

void dfs(ll v, vvll&adj, vll&marked, ll &cnt, vll&assi, ll k){
    marked[v] = 1; assi[v] = cnt%k;
    for(auto u:adj[v]){
        if(!marked[u]){
            dfs(u,adj,marked,++cnt,assi, k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,m,k;cin>>n>>m>>k;
    vvll adj(n);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vll marked(n,0); ll ok = 1;
    vll assi(n,-1);
    rep(i,0,n){
        ll cnt = 0;
        if(!marked[i]){
            dfs(i,adj,marked,cnt,assi,k);
            if(cnt < k-1) ok = 0;
        }
    }
    if(!ok) cout<<"impossible";
    else{
        rep(i,0,n) cout<<assi[i]+1<<" ";
    }

}