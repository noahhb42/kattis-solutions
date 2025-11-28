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
    map<ll,ll> mp;
    ll l,f,m;cin>>l>>f>>m;
    long double ans = 0;
    rep(i,0,l){
        ll n;cin>>n;
        vector<string> s(n);
        for(auto &j : s)cin>>j;
        ll nr = 0;
        for(auto j : s){
            if(j=="swing")nr+=4;
            if(j=="country")nr+=2;
            if(j=="bachata")nr+=1;
        }
        mp[nr]++;
    }
    rep(i,0,f){
        ll n;cin>>n;
        vector<string> s(n);
        for(auto &j : s)cin>>j;
        ll nr = 0;
        for(auto j : s){
            if(j=="swing")nr+=4;
            if(j=="country")nr+=2;
            if(j=="bachata")nr+=1;
        }
        if(mp[nr]>0){
            mp[nr]--;
            while(nr){
                if(nr&1)ans++;
                nr>>=1;
            }
        }
    }
    cout<<setprecision(20)<<ans*m/3<<"\n";
}