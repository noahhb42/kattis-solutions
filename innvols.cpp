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
    string s;cin>>s;
    map<string,ll> m;
    rep(i,0,s.size()){
        rep(j,i,s.size()){
            string t = "";
            rep(k,i,j+1){
                t.push_back(s[k]);
            }
            m[t]++;
        }
    }
    vector<pair<ll,string>> a;
    for(auto [s,v] : m){
        a.push_back({-v,s});
    }
    sort(a.begin(),a.end());
    for(auto [v,s] : a){
        cout<<-v<<" "<<s<<"\n";
    }
}