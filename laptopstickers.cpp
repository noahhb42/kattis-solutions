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
    ll n,m,k;cin>>m>>n>>k;
    vector<vector<char>> grid(n,vector<char>(m,'_'));
    rep(i,0,k){
        ll w,h,a,b;cin>>h>>w>>b>>a;
        rep(ii,a,a+w){
            if(ii>=n)continue;
            rep(jj,b,b+h){
                if(jj>=m)continue;
                grid[ii][jj]=i+'a';
            }
        }
    }
    rep(i,0,n){rep(j,0,m)cout<<grid[i][j];cout<<"\n";}
}