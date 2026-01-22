#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxc = 1001;
ll dp[mxc][mxc];


int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll c,n;cin>>c>>n;
    vll a(n);
    for(auto& i:a)cin>>i;
    
    dp[0][0] = 1;

    for(auto v : a){
        for(ll j = c ; j>=0 ; j--){
            for(ll i = c ; i>=0 ; i--){
                if(i-v>=0)dp[i][j] = max(dp[i][j],dp[i-v][j]);
                if(j-v>=0)dp[i][j] = max(dp[i][j],dp[i][j-v]);
            }
        }
    }

    ll di = LLONG_MIN/4,dj = LLONG_MAX/4;
    for(ll ans = 2*c ; ans>=0 ; ans--){
        bool found = false;
        for(ll i = c ; i>=0 ; i--){
            ll j = ans - i;
            if(j > c || j < 0)continue;
            if(dp[i][j] && abs(i-j) < abs(di-dj)){found = true; di = i;dj = j;}
        }
        if(found){
            cout<<di<<" "<<dj<<endl;
            return 0;
        }
    }
}