#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 50005;
ll parent[mxn], deg[mxn], val[mxn];

ll find(ll a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}

void remove(vvll& g, ll n){
    queue<ll> q;
    rep(i,1,n+1){
        if(deg[i] == 1)q.push(i);
    }

    while(!q.empty()){
        ll u = q.front();q.pop();
        for(auto  v : g[u]){
            if(deg[v] == 1)continue;
            parent[u] = v;
            if(--deg[v] == 1){
                q.push(v);
            }
            break;
        }
    }
}

void fill1(vvll& g, ll node){
    ll idx = 1;
    for(auto v : g[node]){
        ll pv = find(v);
        if(pv == node)continue;

        set<ll> seen;
        queue<ll> q;
        q.push(pv);
        seen.insert(pv);

        while(!q.empty()){
            ll u = q.front();q.pop();
            val[u] = idx;
            for(auto w : g[u]){
                ll pw = find(w);
                if(pw == node)continue;
                if(seen.count(pw))continue;
                seen.insert(pw);
                q.push(pw);
            }
        }
        idx++;
    }
}

void fill2(vvll& g, ll& ret, ll& check, ll na, ll nb){
    ll idx = 1;
    for(auto v : g[na]){
        ll pv = find(v);
        if(pv == na)continue;

        if(pv == nb){
            ret++;
            check = idx++;
            continue;
        }

        set<ll> seen;
        queue<ll> q;
        q.push(pv);
        seen.insert(pv);

        while(!q.empty()){
            ll u = q.front();q.pop();
            val[u] = idx;
            for(auto w : g[u]){
                ll pw = find(w);
                if(pw == nb){ret++;check=idx;continue;}
                if(pw == na)continue;
                if(seen.count(pw))continue;
                seen.insert(pw);
                q.push(pw);
            }
        }
        idx++;
    }

    for(auto v : g[nb]){
        ll pv = find(v);
        if(pv == nb)continue;
        if(pv == na)continue;
        if(val[pv] == check)continue;

        set<ll> seen;
        queue<ll> q;
        q.push(pv);
        seen.insert(pv);

        while(!q.empty()){
            ll u = q.front();q.pop();
            val[u] = idx;
            for(auto w : g[u]){
                ll pw = find(w);
                if(pw == nb || pw == na)continue;
                if(seen.count(pw))continue;
                seen.insert(pw);
                q.push(pw);
            }
        }
        idx++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    iota(parent,parent+mxn,0);
    fill(deg,deg+mxn,0);
    fill(val,val+mxn,0);

    ll n,q;cin>>n>>q;
    vvll g(n+1,vll{});
    rep(i,0,n+1){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    remove(g,n);

    ll nr = 0;
    vll nds;
    rep(i,1,n+1){
        if(deg[i] > 2){nr++;nds.push_back(i);}
    }

    if(nr == 1){
        ll node = nds[0];
        fill1(g,node);
        rep(i,0,q){
            ll a,b;cin>>a>>b;
            a = find(a);b = find(b);
            if(a == b)cout << 1 << "\n";
            else if(a == node || b == node) cout << 2 << "\n";
            else if (val[a] == val[b])cout << 2 << "\n";
            else cout << 4 << "\n";
        }
    }
    else{
        ll na = nds[0], nb = nds[1];
        ll ret = 0, check = 0;
        fill2(g,ret,check,na,nb);
        rep(i,0,q){
            ll a,b;cin>>a>>b;
            a = find(a);b = find(b);
            if(ret == 1){
                if(a == b)cout << 1 << "\n";
                else if(a == na || a == nb || b == na || b == nb){
                    if((a==na && b==nb) || (a==nb && b==na))cout << 1 << "\n";
                    else if(val[a] == check || val[b] == check)cout << 1 << "\n";
                    else cout << 2 << "\n";
                }
                else if(val[a] == check && val[b] == check)cout << 1 << "\n";
                else if(val[a] == check || val[b] == check)cout << 2 << "\n";
                else if(val[a] == val[b])cout << 2 << "\n";
                else cout << 4 << "\n";
            }
            else{
                if(a == b)cout << 1 << "\n";
                else if(a == na || a == nb || b == na || b == nb || val[a] == val[b]) cout << 3 << "\n";
                else cout << 4 << "\n";
            }
        }
    }
}