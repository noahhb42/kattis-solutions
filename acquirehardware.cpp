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
    ll n,m;cin>>n>>m;
    vector<string> a(n);
    rep(i,0,n)cin>>a[i];
    vvll dp(n,vll(m,0));
    rep(i,0,n){
        rep(j,0,m){
            dp[i][j] = max((i>0 ? dp[i-1][j] : 0LL), (j>0 ? dp[i][j-1] : 0LL)) + (a[i][j]=='I' ? 1 : 0);
        }
    }
    cout<<dp[n-1][m-1]<<"\n";
}