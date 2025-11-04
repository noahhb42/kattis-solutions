#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct DSU{
    vll p,sz;
    DSU(ll n = 0): p(n+1), sz(n+1,1) {iota(p.begin(),p.end(),0);}
    ll find(ll x){return p[x]==x ? x : p[x]=find(p[x]);}
    void Union(ll a, ll b){
        a = find(a);b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        p[b]=a;sz[a]+=sz[b];
    }
    ll size(ll x){return sz[find(x)];}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    DSU dsu(n);
    ll best = -1;
    rep(i,0,m){
        ll x,y;cin>>x>>y;
        dsu.Union(x,y);
    }
    rep(i,1,n+1)best=max(best,dsu.size(i));
    cout<<best<<"\n";
}