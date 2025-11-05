#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll MAXN = 10000000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<bool> isPrime(MAXN,true);
    isPrime[0]=isPrime[1]=false;
    for(ll i = 2 ; i*i<MAXN ; ++i){
        if(isPrime[i]){
            for(ll j = i*i ; j<MAXN ; j+=i)isPrime[j]=false;
        }
    }
    
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        array<ll,10> freq{};
        for(char c : s)freq[c-'0']++;

        unordered_set<ll> seen;

        ll ans = 0;

        function<void(ll)> dfs = [&](ll cur){
            rep(d,0,10)if(freq[d]>0){
                freq[d]--;
                ll nxt = 10*cur+d;
                if(seen.find(nxt)==seen.end()){
                    seen.insert(nxt);
                    if(isPrime[nxt])ans++;
                }
                dfs(nxt);
                freq[d]++;
            }
        };

        dfs(0);

        cout<<ans<<"\n";
    }
}