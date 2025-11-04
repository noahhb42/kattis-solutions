#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    vector<string> g(8);
    rep(i,0,8)cin>>g[i];
    ll kr = -1, kc = -1;

    rep(r,0,8){
        rep(c,0,8){
            if(g[r][c]=='K'){kr=r;kc=c;}
        }
    }

    auto inb = [&](ll i, ll j){return i>=0 && i<8 && j>=0 && j<8;};

    bool check = false;
    for(auto dc : {-1,1}){
        ll r = kr-1;
        ll c = kc+dc;
        if(inb(r,c) && g[r][c]=='p')check = true;
    }

    const ll KDR[8] = {-2,-2,-1,-1,1,1,2,2};
    const ll KDC[8] = {-1,1,-2,2,-2,2,-1,1};

    rep(k,0,8){
        ll r = kr+KDR[k], c = kc+KDC[k];
        if(inb(r,c) && g[r][c]=='n')check = true;
    }

    auto ray = [&](vector<pll> dirs, string hitters){
        for(auto [dc, dr] : dirs){
            ll r = kr + dr, c = kc+dc;
            while(inb(r,c)){
                if(g[r][c]!='.'){
                    if(hitters.find(g[r][c]) != string::npos)return true;
                    break;
                }
                r+=dr;c+=dc;
            }
        }
        return false;
    };

    if(ray({{-1,0},{0,-1},{1,0},{0,1}},"rq"))check=true;
    if(ray({{-1,-1},{1,-1},{1,1},{-1,1}},"bq"))check=true;

    cout << (check ? "Yes\n" : "No\n");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)solve();
}