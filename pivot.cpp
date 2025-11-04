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
    vll a(n);for(auto& i : a)cin>>i;

    vll prefMax(n), sufMin(n);
    rep(i,0,n){
        prefMax[i] = (i==0 ? a[i] : max(prefMax[i-1],a[i]));
        sufMin[n-i-1] = (i==0 ? a[n-i-1] : min(sufMin[n-i],a[n-i-1]));
    }

    ll count = 0;
    rep(i,0,n){
        bool leftOk = (i==0 ? true : a[i]>prefMax[i-1]);
        bool rightOk = (i==n-1 ? true : a[i]<sufMin[i+1]);
        if(leftOk && rightOk)count++;
    }
    cout<<count<<"\n";
}