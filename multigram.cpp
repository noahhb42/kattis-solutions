#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

bool check(string& s, ll d){
    map<ll,ll> m{};
    rep(i,0,d){
        m[s[i]]++;
    }
    rep(k,1,s.size()/d){
        map<ll,ll> m2{};
        rep(i,k*d,(k+1)*d){
            m2[s[i]]++;
        }
        for(auto [i,d] : m2){
            if(m.find(i)==m.end())return false;
            if(m[i] != d)return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;cin>>s;
    for(ll i = 1 ; i<s.size() ; ++i){
        if(s.size()%i != 0)continue;
        if(check(s,i)){
            rep(j,0,i){
                cout<<s[j];
            }
            cout<<"\n";
            return 0;
        }
    } 
    cout<<"-1\n";
}