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
    vector<vector<char>> g(n,vector<char>(m));
    vvll dis(n,vll(m,INF));
    rep(i,0,n){
        rep(j,0,m){
            cin>>g[i][j];
            if(g[i][j]=='S'){
                dis[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        array<ll,2> moves[4] ={{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(auto [i,j] : moves){
            if(x+i<n && x+i>=0 && y+j<m && y+j>=0 && g[x+i][y+j] != '#' && dis[x+i][y+j]==INF){
                q.push({x+i,y+j});
                dis[x+i][y+j]=dis[x][y]+1;
            }
        }
    }
    ll mn = LLONG_MAX;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='G'){
                mn = min(mn,dis[i][j]);
            }
        }
    }
    if(mn==LLONG_MAX){
        cout<<"thralatlega nettengdur\n";
    }
    else{
        cout<<mn<<"\n";
    }
}