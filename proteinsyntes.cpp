#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 998244353, base = 911382323;
const ll mxn = 1e5+1;
ll pw[mxn], pref[mxn];

ll powmod(ll a, ll b){
    ll ret = 1; a %= mod;
    while(b){
        if(b&1)ret = (ret*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    string s;cin>>s;
    pw[0] = 1;
    pref[0] = 0;
    rep(i,0,n){
        pref[i+1] = (pref[i]*base + s[i])%mod;
        pw[i+1] = (pw[i]*base)%mod;
    }

    auto getHash = [&](ll l, ll r){
        return ((pref[r] - pref[l]*pw[r-l])%mod+mod)%mod;
    };

    set<ll> lengths;
    map<ll,set<ll>> mp;
    ll q;cin>>q;
    rep(i,0,q){
        string t;cin>>t;
        lengths.insert((ll)t.size());
        ll hash = 0;
        rep(i,0,t.size()){
            hash = (hash*base + t[i])%mod;
        }
        mp[t.size()].insert(hash);
    }

    vll dis(n+1,-1);
    dis[0]=0;
    queue<ll> qq;
    qq.push(0);

    while(!qq.empty()){
        ll u = qq.front();qq.pop();
        for(auto l : lengths){
            if(u+l>n)break;
            if(mp[l].count(getHash(u,u+l)) && dis[u+l]==-1){
                dis[u+l]=dis[u]+1;
                qq.push(u+l);
            }
        }
    }

    // for(auto i : dis)cout<<i<<" ";cout<<"\n";

    cout<<dis[n]<<"\n";
}