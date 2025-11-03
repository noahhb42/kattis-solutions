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
    ll last = -LLONG_MIN;
    vll ans(0);
    rep(i,0,n){
        ll a;cin>>a;
        if(a>=last){
            ans.push_back(a);
            last = a;
        }
    }
    for(auto i : ans)cout<<i<<" ";cout<<"\n";
}