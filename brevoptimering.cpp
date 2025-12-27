#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct E{
    ll j,w;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin>>n;
    vll send(n+1,0);
    vll indeg(n+1,0);
    vector<vector<E>> g(n+1,vector<E>{});
    rep(i,1,n+1){
        ll k;cin>>send[i]>>k;
        rep(_,0,k){
            ll j,pc;cin>>j>>pc;
            indeg[j]++;
            g[i].push_back({j,pc});
        }
    }

    vector<long double> out(n+1,0),in(n+1,0);
    queue<ll> q;
    rep(i,1,n+1)if(indeg[i]==0){q.push(i);in[i]=send[i];}

    vll ans;

    while(!q.empty()){
        ll u = q.front();q.pop();
        out[u] = in[u];
        if ((long double)send[u] <= out[u]){
            out[u] = send[u];
            ans.push_back(u);
        }
        // cerr << u << " " << in[u] << " " << out[u] << " " << send[u] << "\n";
        for(auto [v,pc] : g[u]){
            in[v] += (long double)pc/100*out[u];
            if(--indeg[v]==0){
                q.push(v);
            }
        }
    }

    sort(ans.begin(),ans.end());

    for(auto i : ans)cout<<i<<" ";cout<<"\n";
}