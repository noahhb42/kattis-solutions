#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Pt{long double x,y;};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    rep(_,0,n){
        vll ans(5,0);
        rep(i,0,20){
            ll a;cin>>a;
            ans[a]++;
        }
        ll mx = 0;
        rep(i,0,5)mx=max(mx,ans[i]);
        if(ans[1]==mx){
            cout<<"leader\n";
        }
        else if(ans[2]==mx){
            cout<<"intellectual\n";
        }
        else if(ans[3]==mx){
            cout<<"social\n";
        }
        else{
            cout<<"practical\n";
        }
    }
}