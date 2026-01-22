#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void dfs(vvll& g, ll node, vll& dis, vll& parent, vll& children){
    if(node != parent[node])children[parent[node]]++;
    for(auto v : g[node]){
        if(v == parent[node])continue;
        parent[v] = node;
        //cout << node << " " << v << " " << dis[v];
        dis[v] = dis[node]+1;
        //cout << " " << dis[v] << "\n";
        dfs(g,v,dis,parent,children);
    }
}

void solve(){
    ll n;cin>>n;
    vvll g(n,vll{});
    vll dis(n,0);
    vll parent(n,0);
    vll children(n,0);
    iota(parent.begin(),parent.end(),0);
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(g,0,dis,parent,children);
    
    ll depth = 0;
    for(auto i : dis)depth = max(depth,i);
    vll nr(depth+1,0);
    for(auto i : dis)nr[i]++;
    
    ll mx = -1;
    for(auto i : nr)mx = max(mx,i);
    rep(i,0,n){
        mx = max(mx,1+children[i]);
    }
    cout<<mx<<"\n";
    
    vvll byDepth(depth+1);
    rep(i,0,n){
        byDepth[dis[i]].push_back(i);
    }
    
    vll col(n,0);col[0] = 1;
    
    vll dsu(mx+2),seen(mx+2,0);
    ll tag = 0;
    
    function<ll(ll)> find = [&](ll x){
        if(x > mx+1)return mx+1;
        if(seen[x] != tag){seen[x] = tag;dsu[x]=x;}
        if(dsu[x]==x){return x;}
        return dsu[x]=find(dsu[x]);
    };

    auto mark = [&](ll x){
        if(x<1 || x>mx)return;
        if(seen[x] != tag){
            seen[x] = tag;
            dsu[x] = x;
        }
        dsu[x] = find(x+1);
    };

    rep(i,1,depth+1){
        vll &nodes = byDepth[i];
        ll m = sz(nodes);
        tag++;

        vll forbid(m),assigned(m,0);
        rep(i,0,m){
            ll v = nodes[i];
            forbid[i] = col[parent[v]];
        }

        rep(i,0,m){
            ll f = forbid[i];
            ll c = find(1);
            if(c==f)c=find(c+1);

            if(c==mx+1){
                ll j = -1;
                rep(t,0,i){
                    if(forbid[t]!=f){j=t;break;}
                }
                ll old=assigned[j];
                assigned[i]=old;
                assigned[j]=f;
                mark(f);
            }
            else{
                assigned[i]=c;
                mark(c);
            }
        }

        rep(i,0,m){
            col[nodes[i]]=assigned[i];
        }
    }

    vvll rounds(mx+1);
    rep(i,0,n){
        rounds[col[i]].push_back(i);
    }

    rep(i,1,mx+1){
        cout << sz(rounds[i]);
        for(ll c : rounds[i])cout<<" "<<c+1;
        cout<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	
    ll t;cin>>t;
    while(t--)solve();
    
}