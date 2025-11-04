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
    ll n;cin>>n;
    struct Deal{
        ll x,y;
        bool operator<(Deal const& other) const {
            if(y*other.x != x*other.y) return y*other.x<x*other.y;
            return x<other.x;
        }
        bool operator>(Deal const& other) const {
            return other < *this;
        }
    };
    vector<Deal> v(n);
    rep(i,0,n)cin>>v[i].x>>v[i].y;
    sort(v.rbegin(),v.rend());
    for(auto d : v){
        cout<<d.x<<" "<<d.y<<"\n";
    }
}