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

    ll k;cin>>k;
    vll S(k);
    for(auto& x:S)cin>>x;
    sort(S.begin(),S.end());
    S.erase(unique(S.begin(),S.end()),S.end());
    ll m;cin>>m;
    vvll pos(m);
    ll maxH = 0;
    rep(i,0,m){
        ll l;cin>>l;
        rep(j,0,l){
            ll a;cin>>a;
            maxH = max(a,maxH);
            pos[i].push_back(a);
        }
    }

    vll g(maxH+1, 0);
    vll used(k+100,-1);
    rep(x,1,maxH+1){
        ll mark_id = x;
        for(auto s : S){
            if(s>x)break;
            ll gv = g[x-s];
            if(gv<used.size())used[gv]=mark_id;
        }
        ll mex = 0;
        while(mex<used.size() && used[mex]==mark_id)++mex;
        g[x]=mex;
    }

    string out;
    for(auto i : pos){
        ll xorsum = 0;
        for(auto j : i){
            xorsum ^= g[j];
        }
        out.push_back(xorsum ? 'W' : 'L');
    }
    cout<<out<<"\n";
}