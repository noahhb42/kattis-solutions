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

    vector<unordered_set<ll>> songs(n+1);
    ll song_id = 0;

    rep(day,0,m){
        ll k;cin>>k;
        vll att(k);
        bool bard_here = false;
        rep(i,0,k){
            cin>>att[i];
            if(att[i]==1)bard_here=true;
        }

        if(bard_here){
            ++song_id;
            for(auto v : att)songs[v].insert(song_id);
        }
        else{
            unordered_set<ll> s;
            for(auto v : att){
                s.insert(songs[v].begin(),songs[v].end());
            }
            for(auto v : att){
                songs[v].insert(s.begin(),s.end());
            }
        }
    }

    vll ans;
    rep(v,1,n+1){
        if(songs[v].size()==song_id)ans.push_back(v);
    }

    for(auto v : ans)cout<<v<<" ";cout<<"\n";
}