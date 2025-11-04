#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Cost{
    ll titans, shamans, dist;
    bool operator<(Cost const& other) const{
        if(titans != other.titans)return titans<other.titans;
        if(shamans != other.shamans)return shamans<other.shamans;
        return dist<other.dist;
    }
    bool operator>(Cost const& other) const{return other < *this;}  
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,x,y;cin>>n>>m>>x>>y;

    struct Edge{ll v, addTitan, addShaman, w;};
    vector<vector<Edge>> g(n+1);
    rep(i,0,m){
        ll a,b,c,w;cin>>a>>b>>w>>c;
        ll addT = (c==2), addS = (c==1);
        g[a].push_back({b, addT, addS, w});
        g[b].push_back({a, addT, addS, w});
    }

    ll INF = LLONG_MAX;

    vector<Cost> best(n+1, {INF,INF,INF});
    priority_queue<pair<Cost,ll>, vector<pair<Cost,ll>>, greater<pair<Cost,ll>>> pq;

    best[x]={0,0,0};
    pq.push({best[x],x});

    while(!pq.empty()){
        auto [c,u] = pq.top();pq.pop();
        if(c.titans != best[u].titans || c.shamans != best[u].shamans || c.dist != best[u].dist)continue;
        if(u==y)break;

        for(auto e : g[u]){
            Cost nc = {c.titans + e.addTitan, c.shamans + e.addShaman, c.dist + e.w};
            if(nc < best[e.v]){
                best[e.v] = nc;
                pq.push({nc, e.v});
            }
        }
    }

    if(best[y].dist == INF){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<best[y].dist<<" "<<best[y].shamans<<" "<<best[y].titans<<"\n";
    }
}