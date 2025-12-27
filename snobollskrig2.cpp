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
    ll n,m;cin>>n>>m;
    multiset<ll> a,b;
    rep(i,0,n){ll x;cin>>x;a.insert(x);}
    rep(i,0,m){ll x;cin>>x;b.insert(x);}

    ll ans = 0;
    while(!a.empty() && !b.empty()){
        bool in_a = true;
        if(*a.begin() > *b.begin())in_a = false;
        ll cur;
        if(in_a){cur = *a.begin();a.erase(a.begin());}
        else {cur = *b.begin();b.erase(b.begin());}

        while(true){
            if(in_a){
                auto it = b.upper_bound(cur);
                if(it == b.end())break;
                cur = *it;
                b.erase(it);
                ans++;
            }
            else{
                auto it = a.upper_bound(cur);
                if(it == a.end())break;
                cur = *it;
                a.erase(it);
                ans++;
            }
            in_a = !in_a;
        }
    }
    cout<<ans<<"\n";
}