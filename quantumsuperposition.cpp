#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n1,n2,m1,m2;cin>>n1>>n2>>m1>>m2;

    vvll g1(n1+1), gr1(n1+1);
    vll outdeg1(n1+1,0);
    vector<set<ll>> pos1(n1+1,set<ll>{});

    rep(_,0,m1){
        ll a,b;cin>>a>>b;
        g1[a].push_back(b);
        gr1[b].push_back(a);
        outdeg1[a]++;
    }

    queue<ll> q1;
    vll order1;
    rep(i,1,n1+1){
        if(outdeg1[i]==0)q1.push(i);
    }
    while(q1.size()){
        ll u = q1.front();q1.pop();
        order1.push_back(u);
        for(auto v : gr1[u])if(--outdeg1[v]==0)q1.push(v);
    }
    reverse(order1.begin(),order1.end());

    for(auto i : order1){
        if(pos1[i].size()==0){
            pos1[i].insert(0);
        }
        for(auto v : g1[i]){
            for(auto j : pos1[i]){
                pos1[v].insert(j+1);
            }
        }
    }

    vvll g2(n2+1), gr2(n2+1);
    vll outdeg2(n1+1,0);
    vector<set<ll>> pos2(n2+1,set<ll>{});

    rep(_,0,m2){
        ll a,b;cin>>a>>b;
        g2[a].push_back(b);
        gr2[b].push_back(a);
        outdeg2[a]++;
    }

    queue<ll> q2;
    vll order2;
    rep(i,1,n2+1){
        if(outdeg2[i]==0)q2.push(i);
    }
    while(q2.size()){
        ll u = q2.front();q2.pop();
        order2.push_back(u);
        for(auto v : gr2[u])if(--outdeg2[v]==0)q2.push(v);
    }
    reverse(order2.begin(),order2.end());

    for(auto i : order2){
        if(pos2[i].size()==0){
            pos2[i].insert(0);
        }
        for(auto v : g2[i]){
            for(auto j : pos2[i]){
                pos2[v].insert(j+1);
            }
        }
    }

    set<ll> allpos;
    for(auto i : pos1[n1]){
        for(auto j : pos2[n2]){
            allpos.insert(i+j);
        }
    }

    ll q;cin>>q;
    rep(_,0,q){
        ll x;cin>>x;
        if(allpos.find(x) != allpos.end()){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
}