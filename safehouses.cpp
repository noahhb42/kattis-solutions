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
    ll n;cin>>n;
    queue<pll> q;
    vector<string> a(n);
    vvll dis(n,vll(n,INF));
    for(auto& x : a)cin>>x;
    rep(i,0,n){
        rep(j,0,n){
            if(a[i][j]=='H'){
                q.push({i,j});
                dis[i][j]=0;
            }
        }
    }
    const pll moves[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(auto [i,j] : moves){
            if(x+i<n && x+i>=0 && y+j<n && y+j>=0 && dis[x+i][y+j]==INF){
                dis[x+i][y+j]=dis[x][y]+1;
                q.push({x+i,y+j});
            }
        }
    }
    ll mx = LLONG_MIN;
    rep(i,0,n)rep(j,0,n)if(a[i][j]=='S')mx=max(mx,dis[i][j]);
    cout<<mx<<"\n";
}