#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    ll l,m;cin>>l>>m;
    ll cap = l*100;

    queue<ll> leftQ, rightQ;
    rep(i,0,m){
        ll len;string side;
        cin>>len>>side;
        if(side[0]=='l')leftQ.push(len);
        else rightQ.push(len);
    }

    ll trips = 0;
    bool onLeft = true;
    while(!leftQ.empty() || !rightQ.empty()){
        ll load = 0;
        if(onLeft){
            while(!leftQ.empty() && load + leftQ.front() <= cap){
                load += leftQ.front();leftQ.pop();
            }
        }
        else{
            while(!rightQ.empty() && load + rightQ.front() <= cap){
                load += rightQ.front();rightQ.pop();
            }
        }
        ++trips;
        onLeft = !onLeft;
    }
    cout<<trips<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)solve();
}
