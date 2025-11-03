#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    ll n;cin>>n;
    priority_queue<pll> bids;
    priority_queue<pll, vector<pll>, greater<pll>> asks;
    ll last = -1;
    rep(i,0,n){
        string typ, tmp1, tmp2; ll x,y;
        cin>>typ>>x>>tmp1>>tmp2>>y;
        if(typ == "buy"){bids.push({y,x});}
        else {asks.push({y,x});}

        while(!asks.empty() && !bids.empty() && bids.top()[0] >= asks.top()[0]){
            auto [ap, aq] = asks.top();asks.pop();
            auto [bp, bq] = bids.top();bids.pop();
            ll t = min(aq,bq);
            aq-=t;bq-=t;last=ap;
            if(aq)asks.push({ap,aq});
            if(bq)bids.push({bp,bq});
        }

        cout << (asks.empty() ? "-" : to_string(asks.top()[0])) << " " << (bids.empty() ? "-" : to_string(bids.top()[0])) << " " << (last < 0 ? "-" : to_string(last)) << "\n";
    }
}

int main(){
    ll t;cin>>t;
    while(t--)solve();
}