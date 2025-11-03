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
    ll mn = LLONG_MAX, mns = LLONG_MAX, mx = LLONG_MIN, mxs = LLONG_MIN;
    rep(i,0,n){
        ll sm = 0;
        ll s;cin>>s;
        rep(_,0,s){
            ll a;cin>>a;
            mn = min(mn,a);
            mx = max(mx,a);
            sm+=a;
        }
        mns = min(mns,sm);
        mxs = max(mxs,sm);
    }
    cout<<mx<<"\n"<<mn<<"\n"<<mxs<<"\n"<<mns<<"\n";
}