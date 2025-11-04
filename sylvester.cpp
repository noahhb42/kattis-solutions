#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    ll n,x,y,w,h;cin>>n>>x>>y>>w>>h;
    rep(r,y,y+h){
        rep(c,x,x+w){
            ll parity = __builtin_popcountll(r & c) & 1;
            cout << (parity ? -1 : 1) << " ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll t;cin>>t;
    while(t--)solve();
}