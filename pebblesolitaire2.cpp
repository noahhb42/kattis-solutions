#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll dp[1<<23];

ll solve_mask(ll mask){
    ll &res = dp[mask];
    if(res != -1)return res;

    res = __builtin_popcount(mask);

    rep(i,0,21){
        ll tri = (mask >> i) & 7;
        if(tri == 0b110){
            ll nmask = mask;
            nmask ^= (1<<i);
            nmask ^= (1<<(i+1));
            nmask ^= (1<<(i+2));
            res = min(res,solve_mask(nmask));
        }
        if(tri == 0b011){
            ll nmask = mask;
            nmask ^= (1<<i);
            nmask ^= (1<<(i+1));
            nmask ^= (1<<(i+2));
            res = min(res,solve_mask(nmask));
        }
    }

    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(begin(dp),end(dp),-1);
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll mask = 0;
        rep(i,0,23){
            if(s[i]=='o')mask|=(1<<i);
        }
        cout<<solve_mask(mask)<<"\n";
    }
}