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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;cin>>n>>m;
    vector<set<ll>>adj(n);
    vll cnt(n,0);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--; b--;
        ll ok = 1;
        auto it = adj[b].lower_bound(a);
        if(it != adj[b].end()){
            if(*it == a) {adj[b].erase(a); ok = 0; cnt[a]--;}
        }
        if(ok) {adj[a].insert(b); cnt[b]++;}
    }
    ll ans = 0; ll cur = 0;
    rep(i,0,n){
        if(cnt[i] > ans){
            cur = i;
            ans = cnt[i];
        }
    }
    cout<<cur+1<<" "<<ans;


}