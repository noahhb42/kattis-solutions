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
    ll W,H;cin>>W>>H;
    ll n=H,m=W;

    vector<string> a(n);
    for(auto& i : a)cin>>i;

    pll start = {-1,-1};
    rep(i,0,n)rep(j,0,m)if(a[i][j]=='P')start={i,j};

    const pll moves[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    auto inb = [&](ll x,ll y){return x>=0 && x<n && y>=0 && y<m;};

    vvll vis(n,vll(m,0));
    queue<pll> q;
    q.push(start);
    vis[start[0]][start[1]]=1;
    ll gold = 0;

    while(!q.empty()){
        auto [x,y] = q.front();q.pop();

        if(a[x][y]=='G')gold++;

        bool nearTrap = false;
        rep(k,0,4){
            auto [i,j] = moves[k];
            ll nx = x + i, ny = y+j;
            if(inb(nx,ny) && a[nx][ny]=='T')nearTrap = true;
        }
        if(nearTrap)continue;

        rep(k,0,4){
            auto [i,j] = moves[k];
            ll nx = x+i, ny = y+j;
            if(!inb(nx,ny) || vis[nx][ny])continue;
            char ch = a[nx][ny];
            if(ch=='#')continue;
            if(ch=='T')continue;
            vis[nx][ny]=1;
            q.push({nx,ny});
        }
    }

    cout<<gold<<"\n";
}
