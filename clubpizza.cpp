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
    map<ll,set<ll>> m;
    ll n,c;cin>>n>>c;
    rep(i,0,n){
        ll a,b;cin>>a>>b;
        m[b].insert(a);
    }
    set<ll> s;
    ll sm = 0, nr = 0;
    for(auto [t, ts] : m){
        for(auto i : ts){
            if(s.find(i)!=s.end() || sm+t>c)continue;
            s.insert(i);
            sm+=t;
            nr++;
        }
    }
    cout<<nr<<"\n";
}