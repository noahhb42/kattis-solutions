#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll MOD = (ll)1e9+7;
const ll mxn = 2e6+5;
ll fac[mxn], invfac[mxn];

ll powmod(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b&1){
            ret*=a;
            ret%=MOD;
        }
        b>>=1;
        a*=a;
        a%=MOD;
    }
    return ret;
}

ll inv(ll a){
    return powmod(a,MOD-2);
}

void build_factorial(){
    fac[0] = 1;
    rep(i,1,mxn){
        fac[i] = (fac[i-1] * i) % MOD;
    }
    invfac[mxn-1] = inv(fac[mxn-1]);
    for(ll i = mxn - 2 ; i>=0 ; --i){
        invfac[i] = (invfac[i+1]*(i+1))%MOD;
    }
}

ll binom(ll n, ll k){
    if(n<k)return 0;
    return (((fac[n]*invfac[k])%MOD)*invfac[n-k])%MOD;
}

ll coef(ll d, ll R, ll W){
    ll ret = 0;
    for(ll t = 0 ; R-t*(d+1)>=0 ; ++t){
        ll prod = binom(W,t);
        if(t&1)prod = (MOD-prod)%MOD;
        prod = (prod*binom(W+(R-t*(d+1))-1,W-1))%MOD;
        ret = (ret+prod)%MOD;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    build_factorial();
    ll R,W,d;cin>>R>>W>>d;
    cout<<coef(d,R,W+1)<<"\n";
}