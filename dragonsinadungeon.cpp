#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = LLONG_MAX;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    queue<pll> q;
    vector<string> a(n);
    vvll dis(n,vll(m,INF));
    for(auto& x : a)cin>>x;
    rep(i,0,n){
        rep(j,0,m){
            if(a[i][j]=='G'){
                q.push({i,j});
                dis[i][j]=0;
            }
        }
    }
    const pll moves[8] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(auto [i,j] : moves){
            if(x+i<n && x+i>=0 && y+j<m && y+j>=0 && a[x+i][y+j]!='M' && dis[x+i][y+j]==INF){
                dis[x+i][y+j]=dis[x][y]+1;
                q.push({x+i,y+j});
            }
        }
    }
    ll mx = LLONG_MAX;
    rep(i,0,n)rep(j,0,m)if(a[i][j]=='E')mx=min(mx,dis[i][j]);
    if(mx==LLONG_MAX){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}