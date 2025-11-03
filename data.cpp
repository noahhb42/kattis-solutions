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

    ll N;cin>>N;
    vll A(N);
    rep(i,0,N)cin>>A[i];

    int LIM = 0; rep(i,0,N) LIM += A[i];
    vector<bool> is(LIM+1,true);
    is[0]=is[1]=false;
    for (ll i=2;i*i<=LIM;++i)if(is[i])for(ll j=i*i;j<=LIM;j+=i)is[j]=false;
    vll primes;
    rep(i,2,LIM+1)if(is[i])primes.push_back(i);

    auto pf = [&](ll x){
        if(x<=1) return 0LL;
        ll c=0;
        for(ll p:primes){
            if(1LL*p*p>x)break;
            if(x%p==0){
                ++c;
                while(x%p==0)x/=p;
            }
        }
        if(x>1)++c;
        return c;
    };

    ll M = 1<<N;
    vll sum(M,0), val(M,0);
    rep(m,1,M){
        ll b = m&-m;
        ll i = __builtin_ctz(b);
        sum[m] = sum[m^b]+A[i];
        val[m] = pf(sum[m]);
    }

    ll NEG = -1e9;
    vll dp(M, NEG);
    dp[0]=0;
    rep(m,1,M){
        for(ll s=m; s; s=(s-1)&m){
            dp[m] = max(dp[m], dp[m^s]+val[s]);
        }
    }

    cout<<dp[M-1]<<'\n';
}
