#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n;cin>>n;
    map<ll,pll> m;
    rep(i,0,n){
        ll a,b;cin>>a>>b;
        m[a][0]+=b;
        m[a][1]++;
    }
    ll mn = LLONG_MAX, car = -1;
    for(auto [carr, vals] : m){
        ll cur = vals[0]/vals[1];
        if(cur<mn){
            mn = cur;
            car = carr;
        }
    }
    cout<<car<<"\n"<<mn<<"\n";
}