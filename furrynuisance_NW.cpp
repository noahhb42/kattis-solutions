#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct DSU{
    ll n;
    vll p;
    DSU(ll n) : n(n), p(n+1) {iota(p.begin(),p.end(),0);}
    
    ll find(ll x){
        return x==p[x] ? x : p[x]=find(p[x]);
    }

    void unite(ll a, ll b){
        a = find(a);b = find(b);
        p[a] = b;
    }
    
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;
    while(cin>>n>>m){
        vll g(n+1,0);
        DSU dsu(n);
        rep(i,0,m){
            ll a,b;cin>>a>>b;
            g[a]++;
            g[b]++;
            dsu.unite(a,b);
        }
        bool connected = true;
        rep(i,1,n+1){
            connected &= (dsu.find(1) == dsu.find(i));
        }
        if(!connected){
            cout<<"NO\n";
            continue;
        }
        ll paws = 0;
        rep(i,1,n+1){
            paws += (g[i] == 1);
        }
        if(paws != 4){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}