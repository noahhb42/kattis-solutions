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
    ll n;cin>>n;
    map<ll,ll> m;
    rep(_,0,n){
        string s;cin>>s;
        set<ll> st;
        rep(i,0,1){
            rep(j,i,7){
                ll ans = 0;
                rep(k,i,j+1){
                    ans*=10;
                    ans+=s[k]-'0';
                }
                st.insert(ans);
            }
        }
        for(auto i : st){
            m[i]++;
        }
    }
    ll q;cin>>q;
    rep(_,0,q){
        ll a;cin>>a;
        cout<<m[a]<<"\n";
    }
}