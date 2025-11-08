#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct DSU{
    vll p, val;
    DSU(ll n): p(n+1), val(n+1,0) {iota(p.begin(),p.end(),0);}
    ll find(ll u){
        return (p[u]==u ? u : p[u]=find(p[u]));
    }
    void Union(ll a, ll b){
        a = find(a);b = find(b);
        if(a==b)return;
        p[b]=a;
        val[a] |= val[b];
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,q;cin>>n>>m>>q;
    DSU dsu(n);
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        dsu.val[a] |= c;
        dsu.val[b] |= c;
        dsu.Union(a,b);
    }
    rep(i,0,q){
        ll a,b;cin>>a>>b;
        if(dsu.find(a) != dsu.find(b)){
            cout<<"-1\n";
            continue;
        }
        cout << __builtin_popcount(dsu.val[dsu.find(a)]) << "\n";
    }
}