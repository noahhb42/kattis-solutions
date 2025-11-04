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
    string dump;getline(cin,dump);

    unordered_map<string, string> cand_to_party;

    rep(i,0,n){
        string candidate, party;
        getline(cin,candidate);
        getline(cin,party);
        cand_to_party[candidate] = party;
    }

    ll m;cin>>m;
    getline(cin,dump);

    unordered_map<string, ll> votes;

    rep(i,0,m){
        string name;
        getline(cin,name);
        if(cand_to_party.find(name) != cand_to_party.end()){
            votes[name]++;
        }
    }

    ll best = -1;
    string winner;
    ll winnerWithBest = 0;

    for(auto [c,p] : cand_to_party){
        ll v = votes[c];
        if(v>best){
            best = v;
            winner = c;
            winnerWithBest = 1;
        }
        else if(v==best)winnerWithBest++;
    }

    if(winnerWithBest>1){
        cout<<"tie\n";
    }
    else{
        cout<<cand_to_party[winner]<<"\n";
    }

}
