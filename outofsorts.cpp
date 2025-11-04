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
    ll n,m,a,c,x;cin>>n>>m>>a>>c>>x;
    vll v(n);
    rep(i,0,n){
        x=a*x+c;
        x%=m;
        v[i]=x;
    }
    ll found = 0;
    rep(i,0,n){
        ll l = 0, r = n-1;
        while(l <= r){
            ll mid = (l+r)/2;
            if(mid==i){++found;break;}
            if(v[i]<v[mid])r=mid-1;
            else l=mid+1;
        }
    }
    cout<<found<<"\n";
}