#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll powmod(ll a, ll b, ll p){
    ll ret = 1;
    while(b){
        if(b&1){
            ret = (a*ret)%p;
        }
        a = (a*a)%p;
        b >>= 1;
    }
    return ret;
}

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,p;cin>>n>>p;
    ll ans = 0;
    rep(i,1,n){
        ll g = gcd(n,i);
        if(g == 1)continue;
        ans = (ans + powmod(2,g,p) - 2)%p;
    }
    ans = (ans * (n-2))%p;
    ans = (ans * powmod(2,p-2,p))%p;
    cout << ans << "\n";
}