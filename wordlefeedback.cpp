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
    string target,guess;cin>>target>>guess;

    ll n = target.size();

    auto idx = [](char c){return tolower(c)-'a';};

    string out(n,'-');
    array<ll,26> cnt{};

    rep(i,0,n){
        if(target[i]==guess[i])out[i]='G';
    }
    rep(i,0,n){
        if(out[i]!='G')cnt[idx(target[i])]++;
    }
    rep(i,0,n){
        if(out[i]=='G')continue;
        ll k = idx(guess[i]);
        if(cnt[k]>0){
            out[i]='Y';
            cnt[k]--;
        }
    }
    cout<<out<<"\n";
}