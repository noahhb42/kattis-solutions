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
    vll a(n),b(n);
    rep(i,0,n){
        ll c,d,e;cin>>c>>d>>e;
        a[i] = c*d;
        b[i] = e;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll sm = 0;
    rep(i,0,n){
        sm+=a[i]*b[i];
    }
    cout<<sm<<"\n";
}